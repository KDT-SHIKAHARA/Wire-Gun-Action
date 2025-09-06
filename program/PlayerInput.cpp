#include "PlayerInput.h"
#include "InputManager.h"
#include "GameObject.h"
#include "Physics.h"
#include <cassert>



PlayerInput::PlayerInput(float a_speed)
	:m_speed(a_speed)
{
	//	入力テーブル
	m_inputVec[KEY_INPUT_A] = { Vector2Df {-m_speed	,0} };
	m_inputVec[KEY_INPUT_D] = { Vector2Df {m_speed	,0} };
	m_inputVec[KEY_INPUT_W] = { Vector2Df {0		,-m_speed} };
	m_inputVec[KEY_INPUT_S] = { Vector2Df {0		,m_speed} };
}

void PlayerInput::Update()
{
	//	最初に移動フラグを折る
	m_isInput = false;

	//	移動用コンポーネントを取得
	auto physics = GetGameObj()->GetComponent<Physics>();
	assert(physics);
	if (!physics) return;


	//	入力判定
	for (const auto& [keycode, vector] : m_inputVec) {
		if (Input::IsKeyPressed(keycode)) {
			//	移動量追加
			physics->SetVelociry(vector);

			//	入力フラグを立てる
			m_isInput = true;
		}
	}

	//	何か入力が押されてたら移動フラグを立てて
	//	入力に応じて移動量を追加する

	//	左右で反転フラグを確認する



}
