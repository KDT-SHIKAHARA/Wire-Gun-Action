#include "Physics.h"
#include "GameObject.h"
#include "Time.h"
#include "InputComponent.h"
#include "SystemManager.h"
#include "PhysicsSystem.h"

Physics::Physics(float a_maxFallSpeed, Flag a_enable, Flag a_isGravity)
	:m_maxFallSpeed(a_maxFallSpeed), m_enable(a_enable), m_isGravity(a_isGravity) {

	//	�V�X�e���̎�Q�Ǝ擾
	m_system = SystemManager::Instance().GetSystem<PhysicsSystem>();
}


Physics::~Physics()
{
	//m_system.lock()->UnRegister(shared_from_this());
};

void Physics::Start()
{
	//	�V�X�e���Ɏ����������Œǉ�
	m_system.lock()->Register(shared_from_this());
}

/// <summary>
/// �d�͉����x�ƊO�͂��ړ��ʂɍ�������B
/// ���ړ��͂܂��������Ȃ�
/// </summary>
void Physics::Update(){
	if (!m_enable) return;

	const auto& deltaTime = Time::deltaTime();

	//	�d�͏��
	if (m_isGravity) {
		//	�d�͂̈ړ��ʑ���
		m_gravityVelocity += (m_gravity * deltaTime);

		//	���x����
		if (m_gravityVelocity > m_maxFallSpeed)
			m_gravityVelocity = m_maxFallSpeed;
	}
	else
	{
		m_gravityVelocity = 0.f;
	}

	//	velociry�ɊO�͂Əd�͉����x����������
	m_velocity.x += m_acceleration.x * deltaTime;
	m_velocity.y += m_gravityVelocity + m_acceleration.y * deltaTime;

	//	�R���|�[�l���g�擾
	auto inputComponent = GetGameObj()->GetComponent<InputComponent>();
	//	���݂����
	if (inputComponent) {
		//	���͂����݂��Ă��Ȃ����
		if (!(inputComponent->GetHorizontal() != 0)) {
			//	����������
			m_velocity.x *= m_friction;
			//	�ړ��ʂ����ȏ�Ȃ���Β�~����
			if (std::fabs(m_velocity.x) < 0.1f)
				m_velocity.x = 0.f;
		}

	}
}

/// <summary>
/// ���ړ��̃��\�b�h
/// �ړ��V�X�e���ł��̏������s��
/// </summary>
void Physics::Move()
{
	//	�ړ�
	GetGameObj()->m_transform.AddPosition((m_velocity * Time::deltaTime()));

	//	�O�͂̓t���[�����ƃ��Z�b�g
	m_acceleration.Clear();
}
