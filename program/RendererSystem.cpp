#include "RendererSystem.h"
#include "Drawable.h"

/// <summary>
/// �폜����
/// </summary>
/// <param name="a_drawLayer"> ���肷��|�C���^ </param>
/// <returns> true: �폜 false: �������Ȃ� </returns>
bool RendererSystem::isErase(const std::weak_ptr<Drawable>& a_drawLayer){
	//	�Q�Ɛ悪���݂��Ă��邩�A�폜�t���O�������Ă��邩
	return a_drawLayer.expired() || a_drawLayer.lock()->m_isDestory;
}

/// <summary>
/// �R���X�g���N�^�[�ŌĂԒǉ����\�b�h
/// </summary>
/// <param name="a_drawLayer"></param>
void RendererSystem::Add(std::shared_ptr<Drawable> a_drawLayer){
	const auto& layerNum = a_drawLayer->GetLayer();
	m_drawLayers[layerNum].push_back(a_drawLayer);
}

/// <summary>
/// �R���N�V�������̃��C���[�̔ԍ���������������X�V��������
/// �폜���邩�ǂ����𔻒肵�R���N�V���������炵�Ă���
/// </summary>
void RendererSystem::Update() {
	for (auto& layer : m_drawLayers) {
		for (auto& draw : layer) {
			draw.lock()->Render();
		}
	}
}

/// <summary>
/// ���ׂẴ��C���[����s�v�ɂȂ������̂��폜����
/// </summary>
void RendererSystem::Delete()
{
	//	���C���[�P��
	for (auto& Layer : m_drawLayers) {
		//	�폜
		Layer.erase(std::remove_if(Layer.begin(), Layer.end(),[](const std::weak_ptr<Drawable>& wptr) 
			{ return wptr.expired() || wptr.lock()->m_isDestory; }),Layer.end());
	}
}
