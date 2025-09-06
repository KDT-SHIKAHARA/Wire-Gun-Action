#pragma once
#include<unordered_map>

#include"Anim2D.h"
#include"Drawable.h"
#include"Component.h"
#include"PlayerState.h"
#include"Resource.h"

class PlayerAnimation : public Component, public Drawable {
public:
	PlayerAnimation();
	void Start()override;
	void Update()override;
	void Render()override;


private:
	std::unordered_map<_PLAYER_STATE, Anim2D> m_anims;
	std::shared_ptr<PlayerState> m_state;
	_PLAYER_STATE m_now_state;
};