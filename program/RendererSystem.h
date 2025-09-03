#pragma once
#include<memory>
#include<vector>

#include"singleton.h"

class Drawable;
class RendererSystem : public Singleton<RendererSystem> {
	friend class Singleton<RendererSystem>;
	RendererSystem() = default;
	virtual ~RendererSystem() = default;

	//	�폜����
	bool isErase(const std::weak_ptr<Drawable>& a_drawLayer);



public:
	//	�ǉ�
	void Add(std::shared_ptr<Drawable> a_drawLayer);

	//	�X�V
	void Update();

	//	�폜
	void Delete();

private:
	//	�\������C���X�^���X�̎�Q�Ƃ̃R���N�V���������C���[�ԍ����ƂɎ���
	//	���C���[�ԍ�<�C���X�^���X>
	std::vector<std::vector<std::weak_ptr<Drawable>>> m_drawLayers;

};
