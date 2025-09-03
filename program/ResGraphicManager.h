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

	/// �摜�N���X�̐���
	/// <param name="fileName">	�t�@�C���̃t���p�X			</param>
	/// <returns>				�摜�N���X��share�|�C���^	</returns>		
	std::shared_ptr<Resource> createTexture(std::string fileName) {
		int handle = LoadGraph(fileName.c_str());
		auto newTexture = std::make_shared<Resource>(handle);
		return newTexture;
	}


public:

	//	�摜�N���X�̎擾
	std::shared_ptr<Resource> GetTexture(std::string fileName) {
		//	�t�@�C�����ŉ摜����
		auto ite = textureContainer.find(fileName);

		//	�R���e�i���ɂ���΂��̉摜�N���X�|�C���^��Ԃ��B
		if (ite != textureContainer.end()) {
			return ite->second;
		}

		//	�R���e�i���ɂȂ���ΐV���ɉ摜�N���X�𐶐����ăR���e�i�ɓo�^
		auto newTexture = createTexture(fileName);
		textureContainer.insert(std::make_pair(fileName, newTexture));
		return newTexture;
	}
};