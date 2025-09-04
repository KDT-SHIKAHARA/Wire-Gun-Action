#include "Camera.h"
#include "Time.h"
#include "WindowData.h"
#include <algorithm>

Camera::Camera(){
	//	初期座標の設定
	m_position = { (float)WindowData::m_sceneW / 2 , (float)WindowData::m_sceneH/ 2 };
	//	表示範囲の設定
	m_area_size = { (float)WindowData::m_sceneW ,(float)WindowData::m_sceneH };
	m_map_size = m_area_size;
	//	
	m_follow_position = m_position;
}


/// <summary>
/// モードによってカメラの座標を追従させるかを変更させる
/// 追従状態などの状態を一括管理したいので
/// </summary>
void Camera::Update() {

	switch (m_mode) {
	case CameraMode::Follow:
		m_position.x = m_follow_position.x;
		// 画面端で制御
		m_position.x = std::clamp(m_position.x, m_area_size.x / 2.f, m_map_size.x - m_area_size.x / 2.f);
		m_position.y = std::clamp(m_position.y, m_area_size.y / 2.f, m_map_size.y - m_area_size.y / 2.f);
		//position_ = { position_.x,(float)WINDOW_H / 2 + 100 };
		break;
	case CameraMode::Fixed: 
		m_position = { (float)WindowData::m_sceneW / 2 , (float)WindowData::m_sceneH / 2 };

		break;
	case CameraMode::Script:
		break;
	case CameraMode::None:
		break;
	}

}

/// <summary>
///	カメラ座標を考慮して画像を描画する
/// </summary>
/// <param name="pos"></param>
/// <param name="exRate"></param>
/// <param name="angle"></param>
/// <param name="GrHandle"></param>
/// <param name="TransFlag"></param>
/// <param name="ReverseFlagX"></param>
/// <param name="ReverseFlagY"></param>
void DrawRotaGraphCam(const Vector2D<float>& pos, float exRate, float angle, int GrHandle, int TransFlag, int ReverseFlagX, int ReverseFlagY)
{
	auto draw = pos - Camera::Instance().position() + (Camera::Instance().area_size() / 2);
	DrawRotaGraphF(draw.x, draw.y, exRate, angle, GrHandle, TransFlag, ReverseFlagX, ReverseFlagY);
}
