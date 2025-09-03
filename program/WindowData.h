#pragma once

struct WindowData
{
	int sceneX, sceneY, colorBit;
	bool windowFlag;
	WindowData(int a_sceneX = 1280,int a_sceneY = 720,int a_colorBit = 32, bool a_windowFlag = true)
		:sceneX(a_sceneX), sceneY(a_sceneY), colorBit(a_colorBit), windowFlag(a_windowFlag){ }
};