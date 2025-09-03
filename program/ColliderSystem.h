#pragma once
#include<memory>

#include"System.h"
#include"CollisionRule.h"
#include"GameObject.h"
#include"Collider.h"

class ColliderSystem : public System {
	CollisionRule m_rule;
public:
	//	�g�ݍ��킹�̒ǉ�
	ColliderSystem();

	//	�����蔻�胋�[�v
	void Update()override;

private:
	//	�`��ɉ����ē����蔻����s��
	bool checkCollision(std::shared_ptr<GameObject> gameObject1, std::shared_ptr<Collider> collider1,
						std::shared_ptr<GameObject> gameObject2, std::shared_ptr<Collider> collider2);


	//	: �ŕ�����𕪊�����
	std::pair<std::string, std::string> splitTag(const std::string& key) {
		//	������̌������ĕ������̃C���f�b�N�X�̎擾
		auto pos = key.find(":");
		return { key.substr(0,pos),key.substr(pos + 1) };
	}

	//	�����̉����߂�
	void PushBack(std::shared_ptr<GameObject> object1, std::shared_ptr<Collider> collider1,
		std::shared_ptr<GameObject> object2, std::shared_ptr<Collider> collider2);


	////	�~���m�̓����蔻��
	//bool CheckCircleCircle(const Transform& trans1, std::shared_ptr<CircleCollider> circle1,
	//					   const Transform& trans2, std::shared_ptr<CircleCollider> circle2);

	////	�l�p�`���m�̓����蔻��
	//bool CheckBoxBox(const Transform& trans1, std::shared_ptr<BoxCollider> box1,
	//		 		 const Transform& trans2, std::shared_ptr<BoxCollider> box2);

	////	�~�Ǝl�p�`�̓����蔻��
	//bool CheckCircleBox(const Transform& trans1, std::shared_ptr<CircleCollider> circle1,
	//					const Transform& trans2, std::shared_ptr<BoxCollider> box2);

};