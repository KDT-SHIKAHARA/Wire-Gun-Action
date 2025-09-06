#pragma once
#include<memory>
#include<algorithm>
#include"Component.h"
#include"vector2d.h"
#include"flag.h"

class PhysicsSystem;
class Physics : public Component ,public std::enable_shared_from_this<Physics>{
public:
	Physics(float a_maxFallSpeed = 1000.f, Flag a_enable = true, Flag a_isGravity = true);
	virtual ~Physics();

	void Start()override;
	void Update()override;
	void Move();

	//	アクセサ
	void SetFriction(float a_friction) {
		//m_friction = a_friction > 1.0 ? 1.0 :
		//	(a_friction < 0.0 ? 0.0 : a_friction);

		//	別にめったに呼び出さないメソッドなので処理効率を気にする必要
		//	よりも可動性を上げるほうがいいことに気づいたのでおとなしくこっち
		m_friction  = std::clamp(a_friction, 0.0f, 1.0f);
	}

	//	移動ベクトルの追加
	void AddVelociry(const Vector2Df& a_velocity) {
		m_velocity += a_velocity;
	}


	//	移動ベクトルの
	void SetVelociry(const Vector2Df& a_velocity) {
		m_velocity = a_velocity;
	}
	Vector2Df GetVelociry()const { return m_velocity; }

private:
	Vector2Df m_velocity;		//	移動量
	Vector2Df m_acceleration;	//	重力、外力
	float m_gravityVelocity = 0;//	重力で発生している移動ベクトル
	float m_maxFallSpeed;		//	落下速度上限
	float m_friction = 0.0f;	//	水平摩擦	0.0 - 1.0
	float m_gravity = 980.f;		//	重力加速度(秒速)

	std::weak_ptr<PhysicsSystem> m_system;
public:
	Flag m_enable = true;		//	物理演算可能判定
	Flag m_isGravity = true;	//	重力処理判定	
};