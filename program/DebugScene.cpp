#include "DebugScene.h"
#include "EntityFactory.h"
#include "SystemManager.h"
#include "PhysicsSystem.h"

DebugScene::DebugScene()
{
	//	�V�X�e���ǉ�
	SystemManager::Instance().AddSystem<PhysicsSystem>();

	//	�I�u�W�F�N�g�ǉ�
	GameObjectFactory::CreatePlayer();
}

void DebugScene::Update()
{

}

void DebugScene::Render()
{
	DEBUG_LOG("Debug");
}
