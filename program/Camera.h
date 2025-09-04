#pragma once
#include"vector2d.h"
#include "flag.h"

//	いつしか存在しないオブジェクトなので今回はメモリ効率より
//	今後の拡張性とバクの起こりずらさを重視
//	分離構造にしてもしカメラがプレイやに遅れて移動するなどの構造を追加するときに
//	あとからしやすいようにと画面範囲の制御を入れやすくする


enum class CameraMode {
	Follow,	//	追従
	Fixed,	//	固定
	Script,	//	外部制御
	None,	//	何もしない
};

class Camera {
	Camera();
	virtual ~Camera() = default;


public:
	Camera(const Camera&) = delete;
	Camera& operator=(const Camera&) = delete;

	static Camera& Instance() {
		static Camera instance;
		return instance;
	}

	Vector2D<float> position()const { return m_position; }
	Vector2D<float> area_size()const { return m_area_size; }

	//	モード設定
	void SetMode(CameraMode mode) { m_mode = mode; }

	//	各モード用設定
	void SetFollowPos(const Vector2D<float>& follow) { m_follow_position = follow; }
	void SetFixedPos(const Vector2D<float>& fixed) { m_fixed_position = fixed; }
	void SetScriptPos(const Vector2D<float>& script) { m_script_position = script; }
	void SetMapSize(const Vector2D<float>& a_mapSize) { m_map_size = a_mapSize; }

	void SetFollowSpeed(float follow_speed) { m_follow_speed = follow_speed; }

	Flag m_isTargetCam = true;	//	カメラの追従フラグ	true: 追従する false: 追従しない 

	//	更新
	void Update();

	//	カメラ座標を設定する
	void SetPosition(const Vector2D<float>& position) { m_position = position; }



	//	画面内の判定
private:
	//	カメラ座標、表示範囲
	Vector2D<float> m_position;				//	カメラの座標
	Vector2D<float> m_area_size;				//	表示するサイズ
	Vector2D<float> m_map_size;				//	表示できる領域の範囲

	//	モード用データ　
	Vector2D<float> m_follow_position;		//	追従するオブジェクト座標
	Vector2D<float> m_fixed_position;		//	固定座標
	Vector2D<float> m_script_position;		//	スクリプト制御座標


	//	状態
	CameraMode m_mode = CameraMode::Follow;	//	カメラのモード

	//	速度
	float m_follow_speed = 5.0f;				//	カメラの移動速度



};

void DrawRotaGraphCam(const Vector2D<float>& pos, float exRate, float angle, int GrHandle, int TransFlag, int ReverseFlagX, int ReverseFlagY);