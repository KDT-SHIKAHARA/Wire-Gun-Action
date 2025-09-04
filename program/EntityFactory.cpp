#include "EntityFactory.h"
#include "GameObjectManager.h"

void GameObjectFactory::SetSystem(std::shared_ptr<GameObject> a_gameObject)
{
    GameObjectManager::Instance().AddGameObject(a_gameObject);
}

/// <summary>
/// 必要なコンポーネントを追加したプレイヤーになるGameObjectを返す
/// </summary>
/// <returns></returns>
std::shared_ptr<GameObject> GameObjectFactory::CreatePlayer()
{
    auto player = std::make_shared<GameObject>();
    //  コンポーネントの追加

    //  システムに追加
    SetSystem(player);
    return player;
}
