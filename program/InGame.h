#pragma once
#include"Scene.h"

class InGame : public Scene {
public:
	InGame();
	virtual ~InGame() = default;

	void Update()override;
	void Render()override;
private:

};