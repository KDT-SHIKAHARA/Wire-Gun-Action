#pragma once

#include"Component.h"
#include"vector2d.h"
#include"flag.h"

enum class ColliderType{ Circle,Box };

class Collider : public Component {
public:
	virtual ColliderType GetType()const = 0;

	Collider() = default;
	virtual ~Collider() = default;

	virtual void Update()override {};

public:
	Flag m_isActive = true;	//	当たり判定を行うかどうかのフラグ
	Flag m_pushable = true;	//	押し戻し処理を行うかどうかのフラグ
};

class CircleCollider : public Collider {
public:
	CircleCollider(float a_radius, Flag a_isActive = true, Flag a_pushable = true)
		:m_radius(a_radius){
		m_isActive = a_isActive;
		m_pushable = a_pushable;
	}
	ColliderType GetType() const override { return ColliderType::Circle; }
	void Update()override {}
	float GetRadius()const { return m_radius; }
private:
	float m_radius;
};

class BoxCollider : public Collider {
public:
	BoxCollider(const Vector2Df& a_size, Flag a_isActive = true, Flag a_pushable = true)
		:m_size(a_size){
		m_isActive = a_isActive;
		m_pushable = a_pushable;
	}
	ColliderType GetType() const override { return ColliderType::Box; }
	void Update()override {}
	Vector2Df GetSize() { return m_size; }
private:
	Vector2Df m_size;
};