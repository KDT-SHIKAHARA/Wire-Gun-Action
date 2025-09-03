#include "GameObject.h"

/// <summary>
/// 所持しているコンポーネントの更新処理をすべて呼び出す
/// </summary>
void GameObject::Update()
{
	for (auto& [_, comp] : m_components) {
		if (comp) comp->Update();
	}
}
