#pragma once
#include<memory>

#include"GameObject.h"

class GameObjectFactory {
	static void SetSystem(std::shared_ptr<GameObject> a_gameObject);
public:
	static std::shared_ptr<GameObject> CreatePlayer();

};