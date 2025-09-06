#include "InputComponent.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Physics.h"
#include <cassert>

InputComponent::InputComponent(float a_speed)
	:m_speed(a_speed)
{
	//	���̓e�[�u��
	m_inputVec[KEY_INPUT_A] = { Vector2Df {-m_speed	,0} };
	m_inputVec[KEY_INPUT_D] = { Vector2Df {m_speed	,0} };
	m_inputVec[KEY_INPUT_W] = { Vector2Df {0		,-m_speed} };
	m_inputVec[KEY_INPUT_S] = { Vector2Df {0		,m_speed} };
}

void InputComponent::Update()
{
	//	�ŏ��ɓ��͏�Ԃ�؂�
	m_horizontal = 0;

	//	�ړ��p�R���|�[�l���g���擾
	auto physics = GetGameObj()->GetComponent<Physics>();
	assert(physics);
	if (!physics) return;



	//	���͔���
	for (const auto& [keycode, vector] : m_inputVec) {
		if (Input::IsKeyPressed(keycode)) {
			//	�ړ��ʒǉ�
			physics->SetVelociry(vector);
			m_horizontal = 1;
		}
	}

}
