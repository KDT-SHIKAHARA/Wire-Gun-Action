#pragma once
#include<vector>

#include"Drawable.h"

class ParticleEffect : public Drawable {
	struct Particle
	{
		float x, y;       // 位置
		float vx, vy;     // 速度
		float life;       // 残り寿命 (0.0～1.0)
		float size;       // サイズ
		int r, g, b, a;  // 色
	};

public:
	ParticleEffect(int a_layer = 0, int a_width = 1280, int a_height = 720, Flag a_alive = true);
	virtual ~ParticleEffect() = default;
	void SpawnParticle( );
	void Render()override;

private:
	std::vector<Particle> m_particles;
	int m_width;
	int m_height;

};


