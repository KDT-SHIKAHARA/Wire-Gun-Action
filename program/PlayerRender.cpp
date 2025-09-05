#include "PlayerRender.h"
#include "GameObject.h"
#include "Camera.h"
#include "ResGraphicManager.h"

PlayerAnimation::PlayerAnimation()
{
	const float exRate = 1.5f;


	//	フォルダパス
	std::string base_str = "Res/Player/Texture/";
	std::string run_str = "Run/Unitychan_Run_";
	m_anims[AnimType::Run].LoadFrames(base_str + run_str, 18, 0.1f, exRate);

}

void PlayerAnimation::Update(){
	//	前の状態を記録
	AnimType before_anim = m_now_type;

	//	今の状態と前の状態が変わっていたら前の状態のリセットを行う
	if (before_anim != m_now_type) {
		m_anims[before_anim].Reset();
	}


	m_anims[m_now_type].Update();


}

//
void PlayerAnimation::Render(){
	auto pos = GetGameObj()->m_transform.WorldPosition();
	//	カメラ座標
	Vector2D<float> camera_pos = Camera::Instance().position();
	Vector2D<float> camera_size = Camera::Instance().area_size();
	Vector2D<float> draw = pos - camera_pos + (camera_size / 2);
	m_anims[m_now_type].Render(draw.x, draw.y);
}