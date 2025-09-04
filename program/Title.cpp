#include "Title.h"
#include "ResTitle.h"
#include "WindowData.h"
#include "SceneManager.h"


/// <summary>
/// インスタンス生成
/// </summary>
TitleScene::TitleScene()
{
	/*	背景画像の読込*/
	m_bg = std::make_shared<Image>(
		ResTitle::m_bg,
		Vector2Df{ 0,0 },
		1.0f,
		0
	);

	m_particle = std::make_shared<ParticleEffect>(
		1,
		WindowData::m_sceneW,
		WindowData::m_sceneH
	);

	m_particle->Init();
	m_bg->Init();

}

/// <summary>
/// 画面移動処理
/// </summary>
void TitleScene::Update(){
	if (Input::IsActionTriggered(Action::Select)) {
		_SCENE_CREATE(SceneType::MainMenu);
	}
}

/// <summary>
/// 現在のスクリーン表示
/// </summary>
void TitleScene::Render(){
	DEBUG_LOG("Title Scene");
}
