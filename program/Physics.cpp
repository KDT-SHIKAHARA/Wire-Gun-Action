#include "Physics.h"
#include "GameObject.h"
#include "Time.h"
#include "InputComponent.h"
#include "SystemManager.h"
#include "PhysicsSystem.h"

Physics::Physics(float a_maxFallSpeed, Flag a_enable, Flag a_isGravity)
	:m_maxFallSpeed(a_maxFallSpeed), m_enable(a_enable), m_isGravity(a_isGravity) {

	//	システムの弱参照取得
	m_system = SystemManager::Instance().GetSystem<PhysicsSystem>();
}


Physics::~Physics()
{
	//m_system.lock()->UnRegister(shared_from_this());
};

void Physics::Start()
{
	//	システムに自分を自動で追加
	m_system.lock()->Register(shared_from_this());
}

/// <summary>
/// 重力加速度と外力を移動量に合成する。
/// 実移動はまだ何もしない
/// </summary>
void Physics::Update(){
	if (!m_enable) return;

	const auto& deltaTime = Time::deltaTime();

	//	重力状態
	if (m_isGravity) {
		//	重力の移動量増加
		m_gravityVelocity += (m_gravity * deltaTime);

		//	速度制限
		if (m_gravityVelocity > m_maxFallSpeed)
			m_gravityVelocity = m_maxFallSpeed;
	}
	else
	{
		m_gravityVelocity = 0.f;
	}

	//	velociryに外力と重力加速度を合成する
	m_velocity.x += m_acceleration.x * deltaTime;
	m_velocity.y += m_gravityVelocity + m_acceleration.y * deltaTime;

	//	コンポーネント取得
	auto inputComponent = GetGameObj()->GetComponent<InputComponent>();
	//	存在すれば
	if (inputComponent) {
		//	入力が存在していなければ
		if (!(inputComponent->GetHorizontal() != 0)) {
			//	減衰をする
			m_velocity.x *= m_friction;
			//	移動量が一定以上なければ停止する
			if (std::fabs(m_velocity.x) < 0.1f)
				m_velocity.x = 0.f;
		}

	}
}

/// <summary>
/// 実移動のメソッド
/// 移動システムでこの処理を行う
/// </summary>
void Physics::Move()
{
	//	移動
	GetGameObj()->m_transform.AddPosition((m_velocity * Time::deltaTime()));

	//	外力はフレームごとリセット
	m_acceleration.Clear();
}
