#pragma once
#include<unordered_map>
#include<memory>
#include<string>

#include"singleton.h"
#include"Resource.h"


/// <summary>
/// リソースの管理と解放を行う
/// ゲームの管理クラスの終了処理でリソースの開放メソッドを呼び出す
/// </summary>
class ResSoundManagaer : public Singleton<ResSoundManagaer> {
	friend class Singleton<ResSoundManagaer>;
	ResSoundManagaer() = default;
	virtual ~ResSoundManagaer () = default;

	//	生成
	std::shared_ptr<Resource> create(std::string fileName) {
		int handle = LoadSoundMem(fileName.c_str());
		auto newSound = std::make_shared<Resource>(handle);
		return newSound;
	}

public:


	//	音ハンドルが格納されたクラスの取得、なければ作成
	std::shared_ptr<Resource> GetSound(std::string fileName) {
		//	ファイルで検索
		auto ite = m_resContainer.find(fileName);
		//	コンテナ内にあればその音クラスポインタを返す
		if (ite != m_resContainer.end()) {
			return ite->second;
		}

		//	なければ音クラスの作成
		auto newSound = create(fileName);
		m_resContainer.insert(std::make_pair(fileName, newSound));
		//	作成した音クラスを返す
		return newSound;
	}


private:
	std::unordered_map<std::string, std::shared_ptr<Resource>> m_resContainer;
};