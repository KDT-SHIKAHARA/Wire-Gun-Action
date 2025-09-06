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
	using Component_map = std::unordered_map<std::type_index, std::shared_ptr<Component>>;	//	�^�������̂ŁB
	Component_map m_components;	//	�R���|�[�l���g�ꗗ
	std::string m_tag;	//	���ʗp�^�O

public:
	Transform m_transform;
	Flag m_isDestory = false;

	GameObject() = default;
	virtual ~GameObject() = default;

	//	component�̒ǉ��i�������̂�����Əd������̂ŏ㏑������j
	//	�E�Ӓl�Ȃ烀�[�u�A���Ӓl�Ȃ�R�s�[���������̂œ]���Q�ƂŉE�Ӓl���ǂ����̂킩���Ԃň����ł��炤�B
	//	�߂�l�͊�{�I�Ɏ󂯎��K�v���Ȃ����A���Ƃ��ɂ��̃R���|�[�l���g�̃��\�b�h���Ǘ����ŌĂт₷���Ȃ�B
	//	�ʓr�ǂݍ��ނȂ�ʂɖ߂�l�Ȃ��Ă���������..�˂��H
	template<typename T, typename... Args>
	std::shared_ptr<T> AddComponent(Args&&... args);

	//	component�̎擾
	//	�w�肵���^��component��߂�l�Ƃ��ĕԂ��B
	template<typename T>
	std::shared_ptr<T> GetComponent()const;

	template<typename T>
	bool HasComponent()const;

	//	�S�Ă�component�̍X�V���Ă�
	virtual void Update();

	//	tag
	void SetTag(const std::string& tag) { m_tag = tag; }
	const std::string& GetTag()const { return m_tag; }

};

template<typename T, typename ...Args>
inline std::shared_ptr<T> GameObject::AddComponent(Args&&... args) {
	static_assert(std::is_base_of<Component, T>::value, "���̌^�́Aclass component���p�����Ă��܂���");
	//	component�̐���
	//	std::forward�ŉE�Ӓl�Ȃ�move�A���Ӓl�Ȃ�R�s�[������
	auto comp = std::make_shared<T>(std::forward<Args>(args)...);
	//	�t�^����component��GameObject�������ɂ���B
	comp->SetGameObj(shared_from_this());
	//	�X�^�[�g���\�b�h
	comp->Start();
	//	T�^�Ɠ����L�[�̌^�̒��g�ɓ����B(���łɂ���΃��Z�b�g�����)
	m_components[std::type_index(typeid (T))] = comp;

	return comp;
}


template<typename T>
inline std::shared_ptr<T> GameObject::GetComponent() const {
	//	�������āA�C�e���[�^���i�[ �����Ȃ炻�̏ꏊ�̃C�e���[�^�A���s�Ȃ�.end��Ԃ�
	auto ite = m_components.find(std::type_index(typeid(T)));
	//	�����ɐ������Ă��邩�𔻒�
	if (ite != m_components.end()) {
		//	���N���X�^����h���^�Ƀ|�C���^��ϊ�����B
		return std::static_pointer_cast<T>(ite->second);
	}
	//	�Ȃ����nullptr��Ԃ��āAif���Ȃǂ�false�ɂȂ�悤�ɂ���
	return nullptr;
}

template<typename T>
inline bool GameObject::HasComponent() const
{
	//	�������āA�C�e���[�^���i�[ �����Ȃ炻�̏ꏊ�̃C�e���[�^�A���s�Ȃ�.end��Ԃ�
	auto ite = m_components.find(std::type_index(typeid(T)));
	if (ite != m_components.end()) {
		return true;
	}

	return false;

}

