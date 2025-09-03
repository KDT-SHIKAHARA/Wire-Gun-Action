#pragma once
#include"DxLib.h"

/// <summary>
/// Dxlib����ǂݍ��񂾃��\�[�X�̃n���h�����i�[�Ɖ���܂�
/// </summary>
class Resource {
public:
	Resource(int a_handle)
		:m_handle(a_handle){ }
	virtual ~Resource() = default;

	int GetHandle()const { return m_handle; }
	void DeleteHandle() { DeleteGraph(m_handle); }

private:
	int m_handle = -1;
};