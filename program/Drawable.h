#pragma once
#include<memory>
#include "flag.h"

class Drawable :public std::enable_shared_from_this<Drawable>{
protected:
	int m_layer;
public:
	Flag m_isDestory;
	Flag m_alive;
public:
	Drawable(int a_layer = 0, Flag a_alive = true, Flag a_isDestory = false);
	virtual ~Drawable() = default;
	void Init();
	int GetLayer()const { return m_layer; }
	virtual void Render() = 0;
};