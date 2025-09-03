#include "Drawable.h"
#include "RendererSystem.h"

Drawable::Drawable(int a_layer, Flag a_isDestory, Flag a_alive)
	:m_layer(a_layer), m_isDestory(a_isDestory), m_alive(a_alive)
{
	RendererSystem::Instance().Add(shared_from_this());
}
