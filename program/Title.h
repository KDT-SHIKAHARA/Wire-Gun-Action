#pragma once
#include<memory>
#include"Scene.h"
#include"Image.h" 

class TitleScene : public Scene {
public:
	TitleScene();
	void Update()override;
	void Render()override;

private:
	std::shared_ptr<Image> m_bg;
};