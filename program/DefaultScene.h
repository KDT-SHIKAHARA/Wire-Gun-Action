#pragma once
#include"Scene.h"
#include"debugDef.h"

#include"InputManager.h"
#include"ActionMap.h"

class DefaultScene : public Scene {
public:
	DefaultScene() = default;
	virtual ~DefaultScene() = default;
	void Init()override{}
	void Update()override{}
	void Render()override 
	{
		DEBUG_LOG("Default Scene");
	}
};