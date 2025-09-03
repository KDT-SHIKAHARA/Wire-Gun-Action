#include "RendererSystem.h"
#include "Drawable.h"

/// <summary>
/// 削除判定
/// </summary>
/// <param name="a_drawLayer"> 判定するポインタ </param>
/// <returns> true: 削除 false: 何もしない </returns>
bool RendererSystem::isErase(const std::weak_ptr<Drawable>& a_drawLayer){
	//	参照先が存在しているか、削除フラグが立っているか
	return a_drawLayer.expired() || a_drawLayer.lock()->m_isDestory;
}

/// <summary>
/// コンストラクターで呼ぶ追加メソッド
/// </summary>
/// <param name="a_drawLayer"></param>
void RendererSystem::Add(std::shared_ptr<Drawable> a_drawLayer){
	const auto& layerNum = a_drawLayer->GetLayer();
	m_drawLayers[layerNum].push_back(a_drawLayer);
}

/// <summary>
/// コレクション内のレイヤーの番号が小さい順から更新処理を回す
/// 削除するかどうかを判定しコレクションを減らしてから
/// </summary>
void RendererSystem::Update() {
	for (auto& layer : m_drawLayers) {
		for (auto& draw : layer) {
			draw.lock()->Render();
		}
	}
}

/// <summary>
/// すべてのレイヤーから不要になったものを削除する
/// </summary>
void RendererSystem::Delete()
{
	//	レイヤー単位
	for (auto& Layer : m_drawLayers) {
		//	削除
		Layer.erase(std::remove_if(Layer.begin(), Layer.end(),[](const std::weak_ptr<Drawable>& wptr) 
			{ return wptr.expired() || wptr.lock()->m_isDestory; }),Layer.end());
	}
}
