#pragma once
#include"Component.h"


class PlayerState : public Component {
public:
	enum class State {
		Idle,
		Move,
		Jump,
		Attack,
		Damage,
		Dead,
	}; // enum class

	//	各コンポーネントの終了状態を見て待機状態に戻す
	void Update()override;


	//	状態変更可能確認


	//	状態変更リクエスト


	//	現在の状態が指定した状態と同じかどうか
	bool CheckState(State a_state) { return m_state == a_state; }

private:
	State m_state = State::Idle;

};	//	class