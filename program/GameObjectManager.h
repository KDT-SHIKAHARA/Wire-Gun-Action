#pragma once
#include<vector>
#include<memory>

#include"singleton.h"
#include"GameObject.h"

class GameObjectManager : public Singleton<GameObjectManager> {
	friend class Singleton<GameObjectManager>;
	GameObjectManager() = default;
	virtual ~GameObjectManager() = default;
	using GameObjects = std::vector<std::shared_ptr<GameObject>>;

public:
	//	�ǉ�
	void AddGameObject(std::shared_ptr<GameObject> a_gameObject) {
		m_gameObjects.push_back(a_gameObject);
	}

	//	�S�Ă̍X�V�������Ăяo��
	void Update() {
		for (auto& gameObject : m_gameObjects) {
			gameObject->Update();
		}
	}

	//	�폜�t���O�������Ă���Q�[���I�u�W�F�N�g�̍폜
	void DestroyGameObject() {
		m_gameObjects.erase(
			std::remove_if(m_gameObjects.begin(),m_gameObjects.end(),[](const std::shared_ptr<GameObject>& gameObject) 
			{ return gameObject->m_isDestory;}), m_gameObjects.end());
	}

	//	�^�O�ɊY�������I�u�W�F�N�g�̐V�������X�g��Ԃ�
	GameObjects GetGameObjWithTag(const std::string& a_tag) {
		GameObjects new_gameObjects;

		for (auto& gameObject : m_gameObjects) {
			if (gameObject->GetTag() == a_tag) {
				new_gameObjects.push_back(gameObject);
			}
		}
		return new_gameObjects;
	}


private:
	GameObjects m_gameObjects;
};