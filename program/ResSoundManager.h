#pragma once
#include<unordered_map>
#include<memory>
#include<string>

#include"singleton.h"
#include"Resource.h"


/// <summary>
/// ���\�[�X�̊Ǘ��Ɖ�����s��
/// �Q�[���̊Ǘ��N���X�̏I�������Ń��\�[�X�̊J�����\�b�h���Ăяo��
/// </summary>
class ResSoundManagaer : public Singleton<ResSoundManagaer> {
	friend class Singleton<ResSoundManagaer>;
	ResSoundManagaer() = default;
	virtual ~ResSoundManagaer () = default;

	//	����
	std::shared_ptr<Resource> create(std::string fileName) {
		int handle = LoadSoundMem(fileName.c_str());
		auto newSound = std::make_shared<Resource>(handle);
		return newSound;
	}

public:


	//	���n���h�����i�[���ꂽ�N���X�̎擾�A�Ȃ���΍쐬
	std::shared_ptr<Resource> GetSound(std::string fileName) {
		//	�t�@�C���Ō���
		auto ite = m_resContainer.find(fileName);
		//	�R���e�i���ɂ���΂��̉��N���X�|�C���^��Ԃ�
		if (ite != m_resContainer.end()) {
			return ite->second;
		}

		//	�Ȃ���Ή��N���X�̍쐬
		auto newSound = create(fileName);
		m_resContainer.insert(std::make_pair(fileName, newSound));
		//	�쐬�������N���X��Ԃ�
		return newSound;
	}


private:
	std::unordered_map<std::string, std::shared_ptr<Resource>> m_resContainer;
};