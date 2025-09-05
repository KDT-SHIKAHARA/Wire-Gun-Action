#pragma once
#include<unordered_map>

#include"Anim2D.h"
#include"Drawable.h"
#include"Component.h"
#include"PlayerState.h"
#include"Resource.h"

class PlayerAnimation : public Component, public Drawable {
	enum class AnimType {
		Idle,
		Run,
		Jump,
	};

public:
	PlayerAnimation();
	void Update()override;
	void Render()override;


private:
	std::unordered_map<AnimType, Anim2D> m_anims;
	AnimType m_now_type = AnimType::Run;
};