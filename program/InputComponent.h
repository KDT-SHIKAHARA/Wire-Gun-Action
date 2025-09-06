#pragma once
#include"Component.h"
#include"flag.h"
#include "vector2d.h"

#include<map>

class InputComponent : public Component {
public:
	InputComponent(float a_speed = 100.f);
	virtual ~InputComponent() = default;
	void Update()override;
	int GetHorizontal()const { return m_horizontal; }

private:
	std::map<int, Vector2Df> m_inputVec;
	float m_speed;
	//	…•½•ûŒü‚Ì“ü—Íó‘Ô
	//	0: ‚È‚µ 1: ‰E -1: ¶
	int m_horizontal = 0;
};