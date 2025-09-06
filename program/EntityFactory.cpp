#include "EntityFactory.h"
#include "WindowData.h"
#include "GameObjectManager.h"
#include "Collider.h"
#include "PlayerRender.h"
#include "vector2d.h"
#include "PlayerState.h"
#include "Physics.h"
#include "InputComponent.h"
#include "PlayerInput.h"


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
    //  引数に必要な情報
    const Vector2Df size = {10,20};

    //  プレイヤーの生成
    auto player = std::make_shared<GameObject>();

    //  座標
    player->m_transform.SetWorldPosition(Vector2Df{ (float)WindowData::m_sceneW / 2, (float)WindowData::m_sceneH / 2 });

    //  コンポーネントの追加

    //  判定用
    player->AddComponent<BoxCollider>(size,true,false);
    //  状態
    player->AddComponent<PlayerState>();
    //  物理演算
    player->AddComponent<Physics>(500.f,true,false);
    //  アニメーション
    auto render = player->AddComponent<PlayerAnimation>();
    render->Init();
    //  入力
    player->AddComponent<InputComponent>();

    //  システムに追加
    SetSystem(player);
    return player;
}
