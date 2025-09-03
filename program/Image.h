#pragma once
#include<DxLib.h>
#include<string>

#include"Drawable.h"
#include"Resource.h"
#include"vector2d.h"
#include"ResGraphicManager.h"

/// <summary>
/// ‰æ‘œ‚ð•\Ž¦‚·‚é‚¾‚¯‚ÌƒNƒ‰ƒX
/// </summary>
class Image : public Drawable {
public:
	Image(const std::string& a_filePath,const Vector2Df& a_position, float a_exRate = 1.0f,int a_layer = 0, Flag a_alive = true, bool a_transFlag = false)
		:Drawable(a_layer, a_alive), m_position(a_position), m_exRate(a_exRate), m_transFlag(a_transFlag)
	{
		//	‰æ‘œ“Çž
		m_texture = ResGraphicManager::Instance().GetTexture(a_filePath);
	}

	virtual ~Image() = default;
	void Render()override
	{
		GetGraphSizeF(m_texture->GetHandle(), &m_size.x, &m_size.y);
		DrawExtendGraphF(m_position.x, m_position.y, m_position.x + (m_size.x * m_exRate), m_position.y + (m_size.y * m_exRate),
			m_texture->GetHandle(), static_cast<int>(m_transFlag));
	};

public:
	Vector2Df m_position;
	Vector2Df m_size;
	float m_exRate = 1.0f;
	bool m_transFlag;
private:
	std::shared_ptr<Resource> m_texture;
};