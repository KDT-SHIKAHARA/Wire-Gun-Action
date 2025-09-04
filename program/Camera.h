#pragma once
#include"vector2d.h"
#include "flag.h"

//	���������݂��Ȃ��I�u�W�F�N�g�Ȃ̂ō���̓������������
//	����̊g�����ƃo�N�̋N���肸�炳���d��
//	�����\���ɂ��Ă����J�������v���C��ɒx��Ĉړ�����Ȃǂ̍\����ǉ�����Ƃ���
//	���Ƃ��炵�₷���悤�ɂƉ�ʔ͈͂̐�������₷������


enum class CameraMode {
	Follow,	//	�Ǐ]
	Fixed,	//	�Œ�
	Script,	//	�O������
	None,	//	�������Ȃ�
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

	//	���[�h�ݒ�
	void SetMode(CameraMode mode) { m_mode = mode; }

	//	�e���[�h�p�ݒ�
	void SetFollowPos(const Vector2D<float>& follow) { m_follow_position = follow; }
	void SetFixedPos(const Vector2D<float>& fixed) { m_fixed_position = fixed; }
	void SetScriptPos(const Vector2D<float>& script) { m_script_position = script; }
	void SetMapSize(const Vector2D<float>& a_mapSize) { m_map_size = a_mapSize; }

	void SetFollowSpeed(float follow_speed) { m_follow_speed = follow_speed; }

	Flag m_isTargetCam = true;	//	�J�����̒Ǐ]�t���O	true: �Ǐ]���� false: �Ǐ]���Ȃ� 

	//	�X�V
	void Update();

	//	�J�������W��ݒ肷��
	void SetPosition(const Vector2D<float>& position) { m_position = position; }



	//	��ʓ��̔���
private:
	//	�J�������W�A�\���͈�
	Vector2D<float> m_position;				//	�J�����̍��W
	Vector2D<float> m_area_size;				//	�\������T�C�Y
	Vector2D<float> m_map_size;				//	�\���ł���̈�͈̔�

	//	���[�h�p�f�[�^�@
	Vector2D<float> m_follow_position;		//	�Ǐ]����I�u�W�F�N�g���W
	Vector2D<float> m_fixed_position;		//	�Œ���W
	Vector2D<float> m_script_position;		//	�X�N���v�g������W


	//	���
	CameraMode m_mode = CameraMode::Follow;	//	�J�����̃��[�h

	//	���x
	float m_follow_speed = 5.0f;				//	�J�����̈ړ����x



};

void DrawRotaGraphCam(const Vector2D<float>& pos, float exRate, float angle, int GrHandle, int TransFlag, int ReverseFlagX, int ReverseFlagY);