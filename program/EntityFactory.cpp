#include "EntityFactory.h"
#include "WindowData.h"
#include "GameObjectManager.h"
#include "Collider.h"
#include "PlayerRender.h"
#include "vector2d.h"

void GameObjectFactory::SetSystem(std::shared_ptr<GameObject> a_gameObject)
{
    GameObjectManager::Instance().AddGameObject(a_gameObject);
}

/// <summary>
/// �K�v�ȃR���|�[�l���g��ǉ������v���C���[�ɂȂ�GameObject��Ԃ�
/// </summary>
/// <returns></returns>
std::shared_ptr<GameObject> GameObjectFactory::CreatePlayer()
{
    //  �����ɕK�v�ȏ��
    const Vector2Df size = {10,20};

    //  �v���C���[�̐���
    auto player = std::make_shared<GameObject>();

    //  ���W
    player->m_transform.SetWorldPosition(Vector2Df{ (float)WindowData::m_sceneW / 2, (float)WindowData::m_sceneH / 2 });

    //  �R���|�[�l���g�̒ǉ�
    player->AddComponent<BoxCollider>(size,true,false);
    auto render = player->AddComponent<PlayerAnimation>();
    render->Init();

    //  �V�X�e���ɒǉ�
    SetSystem(player);
    return player;
}
