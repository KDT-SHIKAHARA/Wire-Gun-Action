#pragma once
#include<string>
#include<unordered_map>
#include<memory>

#include"singleton.h"
#include"Resource.h"

class ResGraphicManager : Singleton<ResGraphicManager> {
	friend class Singleton<ResGraphicManager>;
	ResGraphicManager() = default;
	virtual ~ResGraphicManager() = default;

	//	(K,V) = (fileName, Texture)
	std::unordered_map<std::string, std::shared_ptr<Resource>> textureContainer;

	/// 画像クラスの生成
	/// <param name="fileName">	ファイルのフルパス			</param>
	/// <returns>				画像クラスのshareポインタ	</returns>		
	std::shared_ptr<Resource> createTexture(std::string fileName) {
		int handle = LoadGraph(fileName.c_str());
		auto newTexture = std::make_shared<Resource>(handle);
		return newTexture;
	}


public:

	//	画像クラスの取得
	std::shared_ptr<Resource> GetTexture(std::string fileName) {
		//	ファイル名で画像検索
		auto ite = textureContainer.find(fileName);

		//	コンテナ内にあればその画像クラスポインタを返す。
		if (ite != textureContainer.end()) {
			return ite->second;
		}

		//	コンテナ内になければ新たに画像クラスを生成してコンテナに登録
		auto newTexture = createTexture(fileName);
		textureContainer.insert(std::make_pair(fileName, newTexture));
		return newTexture;
	}
};