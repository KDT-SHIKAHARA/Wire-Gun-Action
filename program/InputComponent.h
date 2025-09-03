#pragma once
#include"Component.h"

class InputComponent : public Component {
public:
	void Update()override;
	int GetHorizontal()const { return m_horizontal; }
private:
	//	…•½•ûŒü‚Ì“ü—Íó‘Ô
	//	0: ‚È‚µ 1: ‰E -1: ¶
	int m_horizontal = 0;
};