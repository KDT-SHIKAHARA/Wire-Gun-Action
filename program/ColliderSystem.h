#pragma once
#include<memory>

#include"System.h"
#include"CollisionRule.h"
#include"GameObject.h"
#include"Collider.h"

class ColliderSystem : public System {
	CollisionRule m_rule;
public:
	//	組み合わせの追加
	ColliderSystem();

	//	当たり判定ループ
	void Update()override;

private:
	//	形状に応じて当たり判定を行う
	bool checkCollision(std::shared_ptr<GameObject> gameObject1, std::shared_ptr<Collider> collider1,
						std::shared_ptr<GameObject> gameObject2, std::shared_ptr<Collider> collider2);


	//	: で文字列を分割する
	std::pair<std::string, std::string> splitTag(const std::string& key) {
		//	文字列の検索して分割部のインデックスの取得
		auto pos = key.find(":");
		return { key.substr(0,pos),key.substr(pos + 1) };
	}

	//	両方の押し戻し
	void PushBack(std::shared_ptr<GameObject> object1, std::shared_ptr<Collider> collider1,
		std::shared_ptr<GameObject> object2, std::shared_ptr<Collider> collider2);


	////	円同士の当たり判定
	//bool CheckCircleCircle(const Transform& trans1, std::shared_ptr<CircleCollider> circle1,
	//					   const Transform& trans2, std::shared_ptr<CircleCollider> circle2);

	////	四角形同士の当たり判定
	//bool CheckBoxBox(const Transform& trans1, std::shared_ptr<BoxCollider> box1,
	//		 		 const Transform& trans2, std::shared_ptr<BoxCollider> box2);

	////	円と四角形の当たり判定
	//bool CheckCircleBox(const Transform& trans1, std::shared_ptr<CircleCollider> circle1,
	//					const Transform& trans2, std::shared_ptr<BoxCollider> box2);

};