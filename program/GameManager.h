#pragma once
#include<memory>

#include"singleton.h"
#include"WindowData.h"
#include "RemFPS.h"

class GameManager :public Singleton<GameManager>{
	friend class Singleton<GameManager>;
	void loadResources();
public:
	void Initialize();
	void Run();
	void Exit();

private:
	CRemFPS m_fps;
	WindowData m_window;
};

