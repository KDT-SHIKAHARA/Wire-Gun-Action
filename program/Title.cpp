#include "Title.h"
#include "ResTitle.h"

TitleScene::TitleScene()
{
	//	”wŒi‰æ‘œ‚Ì“Ç
	m_bg = std::make_shared<Image>(
		ResTitle::m_bg,
		Vector2Df{ 0,0 },
		1.0f,
		0
	);
}

void TitleScene::Update(){

}

void TitleScene::Render(){

}
