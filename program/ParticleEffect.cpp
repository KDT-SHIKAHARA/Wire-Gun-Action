#include <DxLib.h>

#include "ParticleEffect.h"
#include "Time.h"

ParticleEffect::ParticleEffect(int a_layer, int a_width, int a_height, Flag a_alive)
	:Drawable(a_layer, a_alive), m_width(a_width), m_height(a_height)
{
	m_particles.reserve(500);
}

void ParticleEffect::SpawnParticle()
{
        Particle p;
        p.x = static_cast<float>(rand() % m_width);
        p.y = static_cast<float>(m_height); // 画面下
        p.vx = 0.0f;
        p.vy = -50.0f - static_cast<float>(rand() % 50); // 上方向
        p.life = 1.0f;
        p.size = 2.0f + static_cast<float>(rand() % 4);

        // 色を白～青～オレンジのランダム
        int colorType = rand() % 3;
        switch (colorType) {
        case 0: p.r = 255; p.g = 255; p.b = 255; break;       // 白
        case 1: p.r = 100; p.g = 200; p.b = 255; break;       // 青
        case 2: p.r = 255; p.g = 150 + rand() % 106; p.b = 0; break; // オレンジ
        }
        p.a = 255;

        m_particles.push_back(p);
}

void ParticleEffect::Render()
{
    SpawnParticle();

    auto dt = Time::deltaTime();
    for (size_t i = 0; i < m_particles.size(); ) {
        Particle& p = m_particles[i];
        p.x += p.vx * dt;
        p.y += p.vy * dt;
        p.life -= dt * 0.1f; // 徐々に寿命減少
        p.a = static_cast<int>(p.life * 255);

        if (p.life <= 0.0f || p.y < 0) {
            // 消えた粒子を削除
            m_particles[i] = m_particles.back();
            m_particles.pop_back();
        }
        else {
            i++;
        }
    }


    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
    for (auto& p : m_particles) {
        // 光のグラデーション風描画
        int alpha = static_cast<int>(p.life * 255);
        for (int r = static_cast<int>(p.size); r > 0; r--) {
            int a = static_cast<int>(alpha * (float)r / p.size);
            DrawCircleAA(static_cast<int>(p.x), static_cast<int>(p.y), static_cast<float>(r),
                50, GetColor(p.r, p.g, p.b), TRUE, a);
        }
    }
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
