#include "InputManager.h"
#include "DxLib.h"

InputManager::InputManager() {
	m_action[Action::Select][Device::Pad] = {PAD_INPUT_1};
	m_action[Action::Select][Device::Keyboard] = { KEY_INPUT_0 };
}

void InputManager::Update()
{
	m_prevKeyState = m_keyStates;	//	�O����͏�ԕێ�
	GetHitKeyStateAll(m_keyStates.data());	//	�S���͏�Ԏ擾

	m_prevMouseState = m_mouseState;	//	�O����͕ێ�
	m_mouseState = GetMouseInput();	//	�S���͎擾

	m_mouseWheel = GetMouseWheelRotVol();	//	�}�E�X�z�C�[���̓��͎擾
	GetMousePoint(&m_mouse.x, &m_mouse.y);	//	�}�E�X���W�擾

	m_prevPadState = m_padState;	//	�O����͕ێ�
	if (GetJoypadNum() > 0) m_padState = GetJoypadInputState(DX_INPUT_PAD1);	//	pad���q�����Ă���Ƃ������S�擾

	//	���݂̓��̓f�o�C�X����
	if (m_padState != 0) m_currentDevice = Device::Pad;
	else if (m_mouseState != 0) m_currentDevice = Device::Mouse;
	else if (anyKey()) m_currentDevice = Device::Keyboard;

}

bool InputManager::IsKeyOn(int a_keyCode) const
{
	return m_keyStates[a_keyCode] && !m_prevKeyState[a_keyCode];
}

bool InputManager::IsKeyPressed(int a_keyCode) const
{
	return m_keyStates[a_keyCode];
}

bool InputManager::IsMouseOn(int a_mouseCode) const
{
	return (m_mouseState & a_mouseCode) && !(m_prevMouseState & a_mouseCode);
}

bool InputManager::IsMousePressed(int a_mouseCode) const
{
	return (m_mouseState & a_mouseCode) != 0;
}

bool InputManager::IsPadOn(int a_padCode) const
{
	return (m_padState & a_padCode) && !(m_prevPadState & a_padCode);
}

bool InputManager::IsPadPressed(int a_padCode) const
{
	return (m_padState & a_padCode) != 0;
}

int InputManager::GetMouseScroll() const
{
	return m_mouseWheel;
}

Vector2Di InputManager::GetMousePos() const
{
	return m_mouse;
}


bool InputManager::IsActionTriggered(Action a_action) const
{
	// �A�N�V�����Ɋ֘A������̓f�o�C�X�ƃL�[�R�[�h���擾
	const auto& actionBinding = m_action.at(a_action);

	for (const auto& [device, keyCodes] : actionBinding)
	{
		// ���̓f�o�C�X���ƂɃ`�F�b�N
		for (int keyCode : keyCodes)
		{
			switch (device)
			{
			case Device::Keyboard:
				// �L�[�������ꂽ�u�Ԃ��`�F�b�N
				if (IsKeyOn(keyCode)) return true;
				break;

			case Device::Mouse:
				// �}�E�X�������ꂽ�u�Ԃ��`�F�b�N
				if (IsMouseOn(keyCode)) return true;
				break;

			case Device::Pad:
				// �Q�[���p�b�h�������ꂽ�u�Ԃ��`�F�b�N
				if (IsPadOn(keyCode)) return true;
				break;
			}
		}
	}
	return false; 
}

bool InputManager::IsActionPressed(Action a_action) const
{
	// �A�N�V�����Ɋ֘A������̓f�o�C�X�ƃL�[�R�[�h���擾
	const auto& actionBinding = m_action.at(a_action);

	for (const auto& [device, keyCodes] : actionBinding)
	{
		// ���̓f�o�C�X���ƂɃ`�F�b�N
		for (int keyCode : keyCodes)
		{
			switch (device)
			{
			case Device::Keyboard:
				// �L�[�������ꑱ���Ă��邩�`�F�b�N
				if (IsKeyPressed(keyCode)) return true;
				break;

			case Device::Mouse:
				// �}�E�X�������ꑱ���Ă��邩�`�F�b�N
				if (IsMousePressed(keyCode)) return true;
				break;

			case Device::Pad:
				// �Q�[���p�b�h�������ꑱ���Ă��邩�`�F�b�N
				if (IsPadPressed(keyCode)) return true;
				break;
			}
		}
	}

	return false;  // �ǂ̃f�o�C�X�ł��A�N�V�������������Ă��Ȃ�
}
