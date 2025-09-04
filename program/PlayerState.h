#pragma once
#include"Component.h"


class PlayerState : public Component {
public:
	enum class State {
		Idle,
		Move,
		Jump,
		Attack,
		Damage,
		Dead,
	}; // enum class

	//	�e�R���|�[�l���g�̏I����Ԃ����đҋ@��Ԃɖ߂�
	void Update()override;


	//	��ԕύX�\�m�F


	//	��ԕύX���N�G�X�g


	//	���݂̏�Ԃ��w�肵����ԂƓ������ǂ���
	bool CheckState(State a_state) { return m_state == a_state; }

private:
	State m_state = State::Idle;

};	//	class