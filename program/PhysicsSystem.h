#pragma once
#include<memory>
#include<vector>
#include"System.h"

class Physics;

class PhysicsSystem : public System {

public:
	void Register(const std::shared_ptr<Physics>& comp);
	void UnRegister(const std::shared_ptr<Physics>& comp);
	void Update()override;
private:
	std::vector<std::weak_ptr<Physics>> m_physicsComponents;
};

