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

	//	�A�N�Z�T
	void SetFriction(float a_friction) {
		//m_friction = a_friction > 1.0 ? 1.0 :
		//	(a_friction < 0.0 ? 0.0 : a_friction);

		//	�ʂɂ߂����ɌĂяo���Ȃ����\�b�h�Ȃ̂ŏ����������C�ɂ���K�v
		//	�����������グ��ق����������ƂɋC�Â����̂ł��ƂȂ���������
		m_friction  = std::clamp(a_friction, 0.0f, 1.0f);
	}

	//	�ړ��x�N�g���̒ǉ�
	void AddVelociry(const Vector2Df& a_velocity) {
		m_velocity += a_velocity;
	}


	//	�ړ��x�N�g����
	void SetVelociry(const Vector2Df& a_velocity) {
		m_velocity = a_velocity;
	}
	Vector2Df GetVelociry()const { return m_velocity; }

private:
	Vector2Df m_velocity;		//	�ړ���
	Vector2Df m_acceleration;	//	�d�́A�O��
	float m_gravityVelocity = 0;//	�d�͂Ŕ������Ă���ړ��x�N�g��
	float m_maxFallSpeed;		//	�������x���
	float m_friction = 0.0f;	//	�������C	0.0 - 1.0
	float m_gravity = 980.f;		//	�d�͉����x(�b��)

	std::weak_ptr<PhysicsSystem> m_system;
public:
	Flag m_enable = true;		//	�������Z�\����
	Flag m_isGravity = true;	//	�d�͏�������	
};