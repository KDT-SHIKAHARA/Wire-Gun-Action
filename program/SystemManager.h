#pragma once
#include"singleton.h"
#include"SystemType.h"
#include"System.h"

#include<functional>
#include<memory>
#include<map>
#include<utility>
#include<typeindex>
#include<type_traits>


class SystemManager :public Singleton<SystemManager> {
	friend class Singleton<SystemManager>;
	SystemManager() = default;
	virtual ~SystemManager() = default;

	using Systems = std::map<std::type_index, std::shared_ptr<System>>;

public:
	//	�V�X�e���̍X�V������S�ČĂяo��
	void Update() {
		for (const auto& system : m_systems) {
			system.second->Update();
		}
	}

	//	�V�X�e���ǉ�
	template<typename T, typename... Args>
	void AddSystem(Args&&... args);


	// �V�X�e���擾
	template<typename T>
	std::shared_ptr<T> GetSystem() {
		auto it = m_systems.find(std::type_index(typeid(T)));
		if (it != m_systems.end()) {
			return std::dynamic_pointer_cast<T>(it->second);
		}
		return nullptr;
	}
private:
	Systems m_systems;
};

template<typename T, typename ...Args>
inline void SystemManager::AddSystem(Args && ...args)
{
	static_assert(std::is_base_of<System, T>::value, "���̌^�́Aclass component���p�����Ă��܂���");

	//	����
	auto ite = m_systems.find(std::type_index(typeid (T)));
	if (ite != m_systems.end()) return;

	//	�ǉ�
	m_systems[std::type_index(typeid (T))] = std::make_shared<T>(std::forward<Args>(args)...);
}
