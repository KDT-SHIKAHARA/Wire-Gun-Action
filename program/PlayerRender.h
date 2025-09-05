#pragma once
#include<unordered_map>

#include"Anim2D.h"
#include"Drawable.h"
#include"Component.h"
#include"PlayerState.h"


class PlayerAnimation : public Component, public Drawable {

	enum class AnimType {
		Idle,
		Run,
		Jump_up,
		Jump_fall,
		Wire,
		Attack,
		Extra,
		Damage,
		Dead,
	};

public:
	PlayerAnimation();
	void Update()override;
	void Render()override;


private:
	std::unordered_map<_PLAYER_STATE, Anim2D> m_animations;
};