#include "GameObject.h"

/// <summary>
/// �������Ă���R���|�[�l���g�̍X�V���������ׂČĂяo��
/// </summary>
void GameObject::Update()
{
	for (auto& [_, comp] : m_components) {
		if (comp) comp->Update();
	}
}
