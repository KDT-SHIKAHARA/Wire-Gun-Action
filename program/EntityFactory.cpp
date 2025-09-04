#include "EntityFactory.h"
#include "GameObjectManager.h"

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
    auto player = std::make_shared<GameObject>();
    //  �R���|�[�l���g�̒ǉ�

    //  �V�X�e���ɒǉ�
    SetSystem(player);
    return player;
}
