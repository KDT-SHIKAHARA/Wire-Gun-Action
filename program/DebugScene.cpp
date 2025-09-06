#include "DebugScene.h"
#include "EntityFactory.h"
#include "SystemManager.h"
#include "PhysicsSystem.h"

DebugScene::DebugScene()
{
	//	システム追加
	SystemManager::Instance().AddSystem<PhysicsSystem>();

	//	オブジェクト追加
	GameObjectFactory::CreatePlayer();
}

void DebugScene::Update()
{

}

void DebugScene::Render()
{
	DEBUG_LOG("Debug");
}
