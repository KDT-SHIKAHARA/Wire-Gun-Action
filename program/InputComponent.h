#pragma once
#include"Component.h"

class InputComponent : public Component {
public:
	void Update()override;
	int GetHorizontal()const { return m_horizontal; }
private:
	//	���������̓��͏��
	//	0: �Ȃ� 1: �E -1: ��
	int m_horizontal = 0;
};