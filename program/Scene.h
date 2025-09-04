#pragma once
#include"SystemType.h"
#include"SystemManager.h"
#include"debugDef.h"
#include"InputManager.h"

class Scene {
public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void Init() {};
	virtual void Update() { };
	virtual void Render() = 0;
private:

};