#pragma once
#include<memory>
#include<unordered_map>
#include<functional>

#include"singleton.h"
#include "SceneType.h"

class Scene;
class SceneManager final : public Singleton<SceneManager> {
	friend class Singleton<SceneManager>;
	SceneManager();
public:
	void Update();
	void Render();

	//	スクリーンの生成
	void CreateScene(SceneType a_type);

	//	オーバレイの作成
	void CreateSOverlay(SceneType a_type);

	//	overlayの消去
	void ReleaseOverlay();
private:
	std::unique_ptr<Scene> m_scene;
	std::unique_ptr<Scene> m_overlay;
	std::unordered_map<SceneType, std::function<std::unique_ptr<Scene>()>> m_sceneFactoty;
};
