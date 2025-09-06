#include "PlayerRender.h"
#include "GameObject.h"
#include "Camera.h"
#include "ResGraphicManager.h"

PlayerAnimation::PlayerAnimation()
{
	const float exRate = 1.0f;


	//	フォルダパス
	std::string base_str = "Res/Player/Texture/";
	std::string run_str = "Run/Unitychan_Run_";
	m_anims[_PLAYER_STATE::Move].LoadFrames(base_str + run_str, 18, 0.1f, exRate);

}

void PlayerAnimation::Start()
{
	m_state = GetGameObj()->GetComponent<PlayerState>();
}


void PlayerAnimation::Update(){
	//	状態取得
	m_now_state = m_state->GetState();

	_PLAYER_STATE before_type = m_now_state;

	//	今の状態と前の状態が変わっていたら前の状態のリセットを行う
	if (before_type != m_now_state) {
		m_anims[before_type].Reset();
	}

	m_anims[m_now_state].Update();


}

//
void PlayerAnimation::Render(){
	auto pos = GetGameObj()->m_transform.WorldPosition();
	//	カメラ座標
	Vector2D<float> camera_pos = Camera::Instance().position();
	Vector2D<float> camera_size = Camera::Instance().area_size();
	Vector2D<float> draw = pos - camera_pos + (camera_size / 2);
	m_anims[m_now_state].Render(draw.x, draw.y);
}