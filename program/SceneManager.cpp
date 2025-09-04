#include "SceneManager.h"
#include "Scene.h"
#include "DefaultScene.h"
#include "Title.h"
#include "MainMenu.h"
#include "RendererSystem.h"
#include "DebugScene.h"

#include <cassert>
#include <vector>

SceneManager::SceneManager() {
	//	生成メソッドをSceneの数だけ追加する
	m_sceneFactoty[SceneType::Default] = []() {return std::make_unique<DefaultScene>(); };
	m_sceneFactoty[SceneType::Title] = []() {return std::make_unique<TitleScene>(); };
	m_sceneFactoty[SceneType::MainMenu] = []() {return std::make_unique<MainMenu>(); };
	m_sceneFactoty[SceneType::DebugScene] = []() {return std::make_unique<DebugScene>(); };
}

/// <summary>
/// スクリーンがなければ何もしない
/// オーバーレイがあればオーバーレイだけ更新処理を呼ぶ
/// オーバーレイがなければスクリーンの更新処理を呼ぶ
/// </summary>
void SceneManager::Update()
{
	assert(m_scene);
	if (!m_scene) return;
	if (m_overlay) {
		m_overlay->Update();
		return;
	}
	m_scene->Update();
}

void SceneManager::Render()
{
	if (!m_scene)return;
	m_scene->Render();
	if (m_overlay) m_overlay->Render();
}

/// <summary>
/// 引数のタイプを生成するメソッドがあるかどうかを検索して
/// 存在していれば生成してなければ何もしない
/// </summary>
/// <param name="a_type"> 生成するスクリーンのタイプ </param>
void SceneManager::CreateScene(SceneType a_type){
	auto ite = m_sceneFactoty.find(a_type);
	if (ite != m_sceneFactoty.end())
	{
		RendererSystem::Instance().AllDelete();
		m_scene = ite->second();
	}
}

/// <summary>
/// 引数のタイプを生成するメソッドがあるかどうかを検索して
/// 存在していれば生成してなければ何もしない
/// </summary>
/// <param name="a_type"> 生成するスクリーンのタイプ </param>
void SceneManager::CreateSOverlay(SceneType a_type)
{
	auto ite = m_sceneFactoty.find(a_type);
	if (ite != m_sceneFactoty.end())
		m_overlay = ite->second();
}

void SceneManager::ReleaseOverlay()
{
	m_overlay.release();
}

