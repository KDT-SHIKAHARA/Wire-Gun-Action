#include "PlayerState.h"

void PlayerState::Update()
{
	switch (m_state)
	{
	case PlayerState::State::Idle:
		break;
	case PlayerState::State::Move:
		break;
	case PlayerState::State::Jump:
		break;
	case PlayerState::State::Attack:
		break;
	case PlayerState::State::Damage:
		break;
	case PlayerState::State::Dead:
		break;
	default:
		break;
	}
}
