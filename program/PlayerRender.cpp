#include "PlayerRender.h"
#include "GameObject.h"
#include "Camera.h"
#include "ResGraphicManager.h"

PlayerAnimation::PlayerAnimation()
{
	const float exRate = 1.0f;


	//	�t�H���_�p�X
	std::string base_str = "Res/Player/Texture/";
	std::string run_str = "Run/Unitychan_Run_";
	m_anims[_PLAYER_STATE::Move].LoadFrames(base_str + run_str, 18, 0.1f, exRate);

}

void PlayerAnimation::Start()
{
	m_state = GetGameObj()->GetComponent<PlayerState>();
}


void PlayerAnimation::Update(){
	//	��Ԏ擾
	m_now_state = m_state->GetState();

	_PLAYER_STATE before_type = m_now_state;

	//	���̏�ԂƑO�̏�Ԃ��ς���Ă�����O�̏�Ԃ̃��Z�b�g���s��
	if (before_type != m_now_state) {
		m_anims[before_type].Reset();
	}

	m_anims[m_now_state].Update();


}

//
void PlayerAnimation::Render(){
	auto pos = GetGameObj()->m_transform.WorldPosition();
	//	�J�������W
	Vector2D<float> camera_pos = Camera::Instance().position();
	Vector2D<float> camera_size = Camera::Instance().area_size();
	Vector2D<float> draw = pos - camera_pos + (camera_size / 2);
	m_anims[m_now_state].Render(draw.x, draw.y);
}