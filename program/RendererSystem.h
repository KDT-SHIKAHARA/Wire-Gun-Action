#pragma once
#include<memory>
#include<vector>

#include"singleton.h"

class Drawable;
class RendererSystem : public Singleton<RendererSystem> {
	friend class Singleton<RendererSystem>;
	RendererSystem() = default;
	virtual ~RendererSystem() = default;

	//	削除判定
	bool isErase(const std::weak_ptr<Drawable>& a_drawLayer);



public:
	//	追加
	void Add(std::shared_ptr<Drawable> a_drawLayer);

	//	更新
	void Update();

	//	削除
	void Delete();

private:
	//	表示するインスタンスの弱参照のコレクションをレイヤー番号ごとに持つ
	//	レイヤー番号<インスタンス>
	std::vector<std::vector<std::weak_ptr<Drawable>>> m_drawLayers;

};
