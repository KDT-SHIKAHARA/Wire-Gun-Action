#include"dxlib.h"
#include"GameManager.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	GameManager::Instance().Initialize();
	GameManager::Instance().Run();
	GameManager::Instance().Exit();
}

