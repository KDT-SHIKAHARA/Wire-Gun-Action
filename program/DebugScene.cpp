#include "DebugScene.h"
#include "EntityFactory.h"

DebugScene::DebugScene()
{
	GameObjectFactory::CreatePlayer();
}

void DebugScene::Update()
{

}

void DebugScene::Render()
{
	DEBUG_LOG("Debug");
}
