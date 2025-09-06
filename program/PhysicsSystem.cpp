#include "PhysicsSystem.h"
#include "Physics.h"

void PhysicsSystem::Register(const std::shared_ptr<Physics>& comp)
{
	m_physicsComponents.push_back(comp);
}

void PhysicsSystem::UnRegister(const std::shared_ptr<Physics>& comp)
{
	m_physicsComponents.erase(
		std::remove_if(m_physicsComponents.begin(), m_physicsComponents.end(), [&](const std::weak_ptr<Physics>& wptr) {
			auto sptr = wptr.lock();
			return !sptr || sptr == comp;
			}), m_physicsComponents.end());
}

void PhysicsSystem::Update()
{
	//	無効なポインタの削除
	m_physicsComponents.erase(
		std::remove_if(
			m_physicsComponents.begin(),
			m_physicsComponents.end(),
			[](const std::weak_ptr<Physics>& wp) {
				return wp.expired();  // 参照が切れているか？
			}
		),
		m_physicsComponents.end()
	);

	for (auto& it : m_physicsComponents) {
		auto physics = it.lock();
		if (!physics) continue;
		physics->Move();
	}
}
