#include "InputComponent.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Physics.h"
#include <cassert>

InputComponent::InputComponent(float a_speed)
	:m_speed(a_speed)
{
	//	入力テーブル
	m_inputVec[KEY_INPUT_A] = { Vector2Df {-m_speed	,0} };
	m_inputVec[KEY_INPUT_D] = { Vector2Df {m_speed	,0} };
	m_inputVec[KEY_INPUT_W] = { Vector2Df {0		,-m_speed} };
	m_inputVec[KEY_INPUT_S] = { Vector2Df {0		,m_speed} };
}

void InputComponent::Update()
{
	//	最初に入力状態を切る
	m_horizontal = 0;

	//	移動用コンポーネントを取得
	auto physics = GetGameObj()->GetComponent<Physics>();
	assert(physics);
	if (!physics) return;



	//	入力判定
	for (const auto& [keycode, vector] : m_inputVec) {
		if (Input::IsKeyPressed(keycode)) {
			//	移動量追加
			physics->SetVelociry(vector);
			m_horizontal = 1;
		}
	}

}
