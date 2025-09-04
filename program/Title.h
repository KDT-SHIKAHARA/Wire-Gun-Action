#pragma once
#include<memory>
#include"Scene.h"
#include"Image.h" 
#include"ParticleEffect.h"

class TitleScene : public Scene {
public:
	TitleScene();
	virtual ~TitleScene() = default;
	void Update()override;
	void Render()override;

private:
	std::shared_ptr<Image> m_bg;
	std::shared_ptr<ParticleEffect> m_particle;
};