#include "Title.h"
#include "ResTitle.h"
#include "WindowData.h"
#include "SceneManager.h"


/// <summary>
/// �C���X�^���X����
/// </summary>
TitleScene::TitleScene()
{
	/*	�w�i�摜�̓Ǎ�*/
	m_bg = std::make_shared<Image>(
		ResTitle::m_bg,
		Vector2Df{ 0,0 },
		1.0f,
		0
	);

	m_particle = std::make_shared<ParticleEffect>(
		1,
		WindowData::m_sceneW,
		WindowData::m_sceneH
	);

	m_particle->Init();
	m_bg->Init();

}

/// <summary>
/// ��ʈړ�����
/// </summary>
void TitleScene::Update(){
	if (Input::IsActionTriggered(Action::Select)) {
		_SCENE_CREATE(SceneType::MainMenu);
	}
}

/// <summary>
/// ���݂̃X�N���[���\��
/// </summary>
void TitleScene::Render(){
	DEBUG_LOG("Title Scene");
}
