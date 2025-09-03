#pragma once
#include"DxLib.h"

/// <summary>
/// Dxlibから読み込んだリソースのハンドルを格納と解放まで
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