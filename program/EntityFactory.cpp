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

    //  ����p
    player->AddComponent<BoxCollider>(size,true,false);
    //  ���
    player->AddComponent<PlayerState>();
    //  �������Z
    player->AddComponent<Physics>(500.f,true,false);
    //  �A�j���[�V����
    auto render = player->AddComponent<PlayerAnimation>();
    render->Init();
    //  ����
    player->AddComponent<InputComponent>();

    //  �V�X�e���ɒǉ�
    SetSystem(player);
    return player;
}
