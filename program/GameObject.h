#pragma once
#include<memory>
#include<typeindex>
#include<type_traits>
#include<unordered_map>
#include<vector>

#include"Component.h"
#include"transform.h"
#include"flag.h"

class GameObject : public std::enable_shared_from_this<GameObject> {
	using Component_map = std::unordered_map<std::type_index, std::shared_ptr<Component>>;	//	型が長いので。
	Component_map m_components;	//	コンポーネント一覧
	std::string m_tag;	//	識別用タグ

public:
	Transform m_transform;
	Flag m_isDestory = false;

	GameObject() = default;
	virtual ~GameObject() = default;

	//	componentの追加（同じものがあると重複するので上書きする）
	//	右辺値ならムーブ、左辺値ならコピーをしたいので転送参照で右辺値かどうかのわかる状態で引数でもらう。
	//	戻り値は基本的に受け取る必要がないが、作るときにそのコンポーネントのメソッドを管理側で呼びやすくなる。
	//	別途読み込むなら別に戻り値なくてもいいけど..ねっ？
	template<typename T, typename... Args>
	std::shared_ptr<T> AddComponent(Args&&... args);

	//	componentの取得
	//	指定した型のcomponentを戻り値として返す。
	template<typename T>
	std::shared_ptr<T> GetComponent()const;

	template<typename T>
	bool HasComponent()const;

	//	全てのcomponentの更新を呼ぶ
	virtual void Update();

	//	tag
	void SetTag(const std::string& tag) { m_tag = tag; }
	const std::string& GetTag()const { return m_tag; }

};

template<typename T, typename ...Args>
inline std::shared_ptr<T> GameObject::AddComponent(Args&&... args) {
	static_assert(std::is_base_of<Component, T>::value, "その型は、class componentを継承していません");
	//	componentの生成
	//	std::forwardで右辺値ならmove、左辺値ならコピーをする
	auto comp = std::make_shared<T>(std::forward<Args>(args)...);
	//	付与したcomponentのGameObjectを自分にする。
	comp->SetGameObj(shared_from_this());
	//	スタートメソッド
	comp->Start();
	//	T型と同じキーの型の中身に入れる。(すでにあればリセットされる)
	m_components[std::type_index(typeid (T))] = comp;

	return comp;
}


template<typename T>
inline std::shared_ptr<T> GameObject::GetComponent() const {
	//	検索して、イテレータを格納 成功ならその場所のイテレータ、失敗なら.endを返す
	auto ite = m_components.find(std::type_index(typeid(T)));
	//	検索に成功しているかを判定
	if (ite != m_components.end()) {
		//	基底クラス型から派生型にポインタを変換する。
		return std::static_pointer_cast<T>(ite->second);
	}
	//	なければnullptrを返して、if分などでfalseになるようにする
	return nullptr;
}

template<typename T>
inline bool GameObject::HasComponent() const
{
	//	検索して、イテレータを格納 成功ならその場所のイテレータ、失敗なら.endを返す
	auto ite = m_components.find(std::type_index(typeid(T)));
	if (ite != m_components.end()) {
		return true;
	}

	return false;

}

