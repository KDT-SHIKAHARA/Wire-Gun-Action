#include<cassert>

#include "GameManager.h"
#include "dxlib.h"
#include "Scene.h"
#include "Time.h"
#include "SceneManager.h"
#include "InputManager.h"

void GameManager::loadResources()
{
}

void GameManager::Initialize()
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(m_window.windowFlag);
	SetGraphMode(m_window.sceneX, m_window.sceneY, m_window.colorBit);
	SetMainWindowText("NoName");
	SetBackgroundColor(128, 128, 128);

	errno_t err = DxLib_Init();
	assert(err != -1);
	SetDrawScreen(DX_SCREEN_BACK);

	loadResources();
}

void GameManager::Run()
{
	while (!ProcessMessage()) {
		clsDx();
		ClearDrawScreen();

		m_fps.Update();
		TimeManager::Instance().Update();
		InputManager::Instance().Update();
		SceneManager::Instance().Update();
		SceneManager::Instance().Render();

		m_fps.Wait();
#ifdef _DEBUG
		m_fps.Draw();
#endif // _DEBUG
		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE) && CheckHitKey(KEY_INPUT_RETURN))
			return;
	}

}


void GameManager::Exit(){
	DxLib_End();
}
