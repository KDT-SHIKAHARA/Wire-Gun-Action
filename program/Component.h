#pragma once
#include<memory>


class GameObject;
class Component{
public:
	virtual ~Component() = default;
	virtual void Update() = 0;
	void SetGameObj(const std::shared_ptr<GameObject>& a_gameObj) { m_gameObj = a_gameObj; }
	std::shared_ptr<GameObject> GetGameObj()const { return m_gameObj.lock(); }
protected:
	std::weak_ptr<GameObject> m_gameObj;
};