#pragma once
#include"Scene.h"

class MainMenu : public Scene {
public:
	MainMenu();
	virtual ~MainMenu() =default;
	void Update()override;
	void Render()override;

};