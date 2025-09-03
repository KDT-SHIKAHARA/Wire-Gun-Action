#pragma once
#include<unordered_map>
#include<unordered_set>
#include<array>

#include"ActionMap.h"
#include"singleton.h"
#include"vector2d.h"

class InputManager : public Singleton<InputManager> {
	friend class Singleton<InputManager>;
	InputManager();
	virtual ~InputManager() = default;

	/// <summary>
	/// ���͎��
	/// </summary>
	enum class Device {
		Keyboard,
		Mouse,
		Pad,
	};

	//	���͎�ʂƃL�[�R�[�h�̃o�C���h	K = ���͎�� V= �L�[�R�[�h���X�g
	using InputBinding = std::unordered_map<Device, std::unordered_set<int>>;
	//	�A�N�V�����ƃo�C���h�̃O���[�v��	K = �A�N�V������� V = InputBinding;
	using ActionList = std::unordered_map<Action, InputBinding>;

	//	�L�[���͔���
	bool anyKey()const {
		for (auto key : m_keyStates) {
			if (key) return true;
		}
		return false;
	}


public:
	//	�S�̍X�V
	void Update();

	//	���͎擾�n
	bool IsKeyOn(int a_keyCode)const;
	bool IsKeyPressed(int a_keyCode)const;
	bool IsMouseOn(int a_mouseCode)const;
	bool IsMousePressed(int a_mouseCode)const;
	bool IsPadOn(int a_padCode)const;
	bool IsPadPressed(int a_padCode)const;
	int GetMouseScroll()const;

	//	�}�E�X���W
	Vector2Di GetMousePos()const;

	//	�A�N�V�����ɑ΂��ē��͂����邩�ǂ����𔻒肷��
	bool IsActionTriggered(Action a_action)const;
	bool IsActionPressed(Action a_action)const;
private:
	Device m_currentDevice = Device::Keyboard;			//	���݂̓��̓f�o�C�X
	int m_mouseState = 0, m_prevMouseState = 0;			//	�}�E�X���͏�ԗp
	int m_padState = 0, m_prevPadState = 0;				//	pad���͏�ԗp
	Vector2Di m_mouse;									//	�}�E�X���W
	int m_mouseWheel = 0;									//	�}�E�X�z�C�[���̉�]��
	std::array<char, 256> m_keyStates, m_prevKeyState;	//	�L�[���͏�ԗp
	ActionList m_action;								//	�A�N�V�����}�b�v
};


/// <summary>
/// ���͊Ǘ��N���X�̃A�N�Z�X�p�̃��b�p�[
/// </summary>
class Input {
public:
	static bool IsKeyOn(int a_keyCode) { return InputManager::Instance().IsKeyOn(a_keyCode); };
	static bool IsKeyPressed(int a_keyCode) { return InputManager::Instance().IsKeyPressed(a_keyCode); };
	static bool IsMouseOn(int a_mouseCode) { return InputManager::Instance().IsMouseOn(a_mouseCode); };
	static bool IsMousePressed(int a_mouseCode) { return InputManager::Instance().IsMousePressed(a_mouseCode); };
	static bool IsPadOn(int a_padCode) { return InputManager::Instance().IsPadOn(a_padCode); };
	static bool IsPadPressed(int a_padCode) { return InputManager::Instance().IsPadPressed(a_padCode); };
	static int GetMouseScroll() { return InputManager::Instance().GetMouseScroll(); };
	static Vector2Di GetMousePos() { return InputManager::Instance().GetMousePos(); };
	static bool IsActionTriggered(Action a_action) { return InputManager::Instance().IsActionTriggered(a_action); };
	static bool IsActionPressed(Action a_action) { return InputManager::Instance().IsActionPressed(a_action); };

};
