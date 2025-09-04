#pragma once
#include<DxLib.h>
#include<string>

#include"Drawable.h"
#include"Resource.h"
#include"vector2d.h"
#include"ResGraphicManager.h"

enum class Anchor {
	TopLeft,
	Center,
};

/// <summary>
/// 画像を表示するだけのクラス
/// </summary>
class Image : public Drawable {
public:
	Image(const std::string& a_filePath,const Vector2Df& a_position, float a_exRate = 1.0f,int a_layer = 0, Anchor a_anchor = Anchor::TopLeft ,Flag a_alive = true, bool a_transFlag = false)
		:Drawable(a_layer, a_alive), m_position(a_position), m_exRate(a_exRate), m_transFlag(a_transFlag),m_anchor(a_anchor)
	{
		//	画像読込
		m_texture = ResGraphicManager::Instance().GetTexture(a_filePath);
	}

	virtual ~Image() = default;
	void Render()override
	{
		//	内部で持っている座標は中心基準
		//	デフォルトは左上基準描画なので状態を見て変更する
		GetGraphSizeF(m_texture->GetHandle(), &m_size.x, &m_size.y);
		auto draw = m_position;

		switch (m_anchor)
		{
		case Anchor::TopLeft:
			draw = draw + (m_size / 2.f);
			break;
		case Anchor::Center:
			break;
		default:
			break;
		}

		DrawRotaGraphF(draw.x, draw.y,m_exRate, m_angle,
			m_texture->GetHandle(), static_cast<int>(m_transFlag));
	};

	void SetAngle(float a_angle) {
		m_angle = a_angle;
	}

public:
	Vector2Df m_position;
	Vector2Df m_size;
	float m_exRate = 1.0f;
	float m_angle = 0;
	bool m_transFlag;
private:
	std::shared_ptr<Resource> m_texture;
	Anchor m_anchor;
};