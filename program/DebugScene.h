#pragma once
#include"Scene.h"

class DebugScene : public Scene {
public:
	DebugScene();
	void Update()override;
	void Render()override;

};