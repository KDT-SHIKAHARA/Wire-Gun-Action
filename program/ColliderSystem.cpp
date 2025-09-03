#include "ColliderSystem.h"
#include "GameObjectManager.h"
#include "Collider.h"
#include "CheckHit.h"
#include"vector2d.h"

#include<string>

ColliderSystem::ColliderSystem()
{
	//	組み合わせの追加
}

void ColliderSystem::Update()
{
	//	タグのすりとがある限りループ
	for (const auto& key : m_rule.GetAllRules()) {
		auto tags = splitTag(key);
		const auto& tag1 = tags.first;
		const auto& tag2 = tags.second;

		//	タグの組み合わせに応じたGameObjectのコレクションを取得
		auto objects1 = GameObjectManager::Instance().GetGameObjWithTag(tag1);
		auto objects2 = GameObjectManager::Instance().GetGameObjWithTag(tag2);

		//	判定用ループ
		for (auto& object1 : objects1) {
			for (auto& object2 : objects2) {
				//	同じオブジェクトは除外
				if (object1 == object2) continue;

				//	当たり判定用component取得
				auto collider1 = object1->GetComponent<Collider>();
				auto collider2 = object2->GetComponent<Collider>();

				//	存在判定
				if (!collider1 || !collider2) continue;

				//	当たり判定を行うかどうかを見て
				if (!collider1->m_isActive || !collider2->m_isActive) continue;

				if (checkCollision(object1, collider1, object2, collider2)) {
					//	イベント通知

					bool push1 = collider1->m_pushable;
					bool push2 = collider2->m_pushable;

					//	押し戻し処理
					//	両方
					if (push1 && push2) {
						//	両方戻すメソッド
					}
					//	1だけ
					else if (push1) {
						//	メソッド	
					}
					//	2だけ
					else if (push2) {
						//	メソッド
					}
					//	両方戻さない場合は何もしない
				}

			}
		}
	}
}

bool ColliderSystem::checkCollision(std::shared_ptr<GameObject> gameObject1, std::shared_ptr<Collider> collider1, std::shared_ptr<GameObject> gameObject2, std::shared_ptr<Collider> collider2)
{
	//	座標
	auto pos1 = gameObject1->m_transform.WorldPosition();
	auto pos2 = gameObject2->m_transform.WorldPosition();

	//	もし移動量のcomponentがあったらその移動量分移動させる


	//	円同士
	if (collider1->GetType() == ColliderType::Circle && collider2->GetType() == ColliderType::Circle) {
		return CheckHit::CircleCircleFast(pos1, std::static_pointer_cast<CircleCollider>(collider1)->GetRadius(),
										  pos2, std::static_pointer_cast<CircleCollider>(collider2)->GetRadius());
	}

	//	四角形同士
	if (collider1->GetType() == ColliderType::Box && collider2->GetType() == ColliderType::Box) {
		//	サイズ
		const auto& size1 = std::static_pointer_cast<BoxCollider>(collider1)->GetSize();
		const auto& size2 = std::static_pointer_cast<BoxCollider>(collider2)->GetSize();
		return CheckHit::BoxBox(pos1, size1, pos2, size2);
	}

	//	円と四角形
	if (collider1->GetType() == ColliderType::Circle && collider2->GetType() == ColliderType::Box) {
		const auto& size2 = std::static_pointer_cast<BoxCollider>(collider2)->GetSize();
		return CheckHit::BoxCircle(pos2, size2, pos1, std::static_pointer_cast<CircleCollider>(collider1)->GetRadius());
	}

	//	四角形と円
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
