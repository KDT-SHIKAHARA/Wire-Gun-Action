#include "ColliderSystem.h"
#include "GameObjectManager.h"
#include "Collider.h"
#include "CheckHit.h"
#include"vector2d.h"

#include<string>

ColliderSystem::ColliderSystem()
{
	//	�g�ݍ��킹�̒ǉ�
}

void ColliderSystem::Update()
{
	//	�^�O�̂���Ƃ�������胋�[�v
	for (const auto& key : m_rule.GetAllRules()) {
		auto tags = splitTag(key);
		const auto& tag1 = tags.first;
		const auto& tag2 = tags.second;

		//	�^�O�̑g�ݍ��킹�ɉ�����GameObject�̃R���N�V�������擾
		auto objects1 = GameObjectManager::Instance().GetGameObjWithTag(tag1);
		auto objects2 = GameObjectManager::Instance().GetGameObjWithTag(tag2);

		//	����p���[�v
		for (auto& object1 : objects1) {
			for (auto& object2 : objects2) {
				//	�����I�u�W�F�N�g�͏��O
				if (object1 == object2) continue;

				//	�����蔻��pcomponent�擾
				auto collider1 = object1->GetComponent<Collider>();
				auto collider2 = object2->GetComponent<Collider>();

				//	���ݔ���
				if (!collider1 || !collider2) continue;

				//	�����蔻����s�����ǂ���������
				if (!collider1->m_isActive || !collider2->m_isActive) continue;

				if (checkCollision(object1, collider1, object2, collider2)) {
					//	�C�x���g�ʒm

					bool push1 = collider1->m_pushable;
					bool push2 = collider2->m_pushable;

					//	�����߂�����
					//	����
					if (push1 && push2) {
						//	�����߂����\�b�h
					}
					//	1����
					else if (push1) {
						//	���\�b�h	
					}
					//	2����
					else if (push2) {
						//	���\�b�h
					}
					//	�����߂��Ȃ��ꍇ�͉������Ȃ�
				}

			}
		}
	}
}

bool ColliderSystem::checkCollision(std::shared_ptr<GameObject> gameObject1, std::shared_ptr<Collider> collider1, std::shared_ptr<GameObject> gameObject2, std::shared_ptr<Collider> collider2)
{
	//	���W
	auto pos1 = gameObject1->m_transform.WorldPosition();
	auto pos2 = gameObject2->m_transform.WorldPosition();

	//	�����ړ��ʂ�component���������炻�̈ړ��ʕ��ړ�������


	//	�~���m
	if (collider1->GetType() == ColliderType::Circle && collider2->GetType() == ColliderType::Circle) {
		return CheckHit::CircleCircleFast(pos1, std::static_pointer_cast<CircleCollider>(collider1)->GetRadius(),
										  pos2, std::static_pointer_cast<CircleCollider>(collider2)->GetRadius());
	}

	//	�l�p�`���m
	if (collider1->GetType() == ColliderType::Box && collider2->GetType() == ColliderType::Box) {
		//	�T�C�Y
		const auto& size1 = std::static_pointer_cast<BoxCollider>(collider1)->GetSize();
		const auto& size2 = std::static_pointer_cast<BoxCollider>(collider2)->GetSize();
		return CheckHit::BoxBox(pos1, size1, pos2, size2);
	}

	//	�~�Ǝl�p�`
	if (collider1->GetType() == ColliderType::Circle && collider2->GetType() == ColliderType::Box) {
		const auto& size2 = std::static_pointer_cast<BoxCollider>(collider2)->GetSize();
		return CheckHit::BoxCircle(pos2, size2, pos1, std::static_pointer_cast<CircleCollider>(collider1)->GetRadius());
	}

	//	�l�p�`�Ɖ~
	if (collider1->GetType() == ColliderType::Box && collider2->GetType() == ColliderType::Circle) {
		const auto& size1 = std::static_pointer_cast<BoxCollider>(collider1)->GetSize();
		return CheckHit::BoxCircle(pos1, size1, pos2, std::static_pointer_cast<CircleCollider>(collider2)->GetRadius());
	}

	return false;
}



//bool ColliderSystem::CheckCircleCircle(const Transform& trans1, std::shared_ptr<CircleCollider> circle1, const Transform& trans2, std::shared_ptr<CircleCollider> circle2)
//{
//	return false;
//}
//
//bool ColliderSystem::CheckBoxBox(const Transform& trans1, std::shared_ptr<BoxCollider> box1, const Transform& trans2, std::shared_ptr<BoxCollider> box2)
//{
//	return false;
//}
//
//bool ColliderSystem::CheckCircleBox(const Transform& trans1, std::shared_ptr<CircleCollider> circle1, const Transform& trans2, std::shared_ptr<BoxCollider> box2)
//{
//	return false;
//}
//
//
