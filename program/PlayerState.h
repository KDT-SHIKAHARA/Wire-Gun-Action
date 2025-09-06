#pragma once
#include"Component.h"


#define _PLAYER_STATE PlayerState::State

class PlayerState : public Component {
public:
	enum class State {
		Idle,
		Move,
	}; // enum class

	//	�e�R���|�[�l���g�̏I����Ԃ����đҋ@��Ԃɖ߂�
	void Update()override;


	//	��ԕύX�\�m�F


	//	��ԕύX���N�G�X�g


	//	���݂̏�Ԃ��w�肵����ԂƓ������ǂ���
	bool CheckState(State a_state) { return m_state == a_state; }
	State GetState()const { return m_state; }

private:
	State m_state = State::Move;

};	//	class