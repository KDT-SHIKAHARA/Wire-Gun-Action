#pragma once
#include"Component.h"
#include"flag.h"
#include "vector2d.h"

#include<map>

class PlayerInput : public Component {
public:
	PlayerInput(float a_speed = 100.0f);
	virtual ~PlayerInput()  = default;
	void Update()override;

private:
	std::map<int, Vector2Df> m_inputVec;
	float m_speed;
public:
	Flag m_isInput = false;
	Flag m_isTrans = false;
};

