#pragma once
#include"Event.h"

namespace bhush {

	class BH_API KeyEvent :public Event 
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; };
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);
	protected:
		KeyEvent(int keyCode)
			:m_KeyCode(keyCode) {};
		int m_KeyCode;

	};

	class BH_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatcode)
			:KeyEvent(keycode), m_RepeatCount(repeatcode) {};

		inline int GetRepeatCount()const { return m_RepeatCount; }

		Event_CLASS_TYPE(KeyPressed);
	private:
		int m_RepeatCount;	
	};

	class BH_API KeyReleasedEvent :public KeyEvent
	{
		KeyReleasedEvent(int KeyCode)
			:KeyEvent(KeyCode) {};
		Event_CLASS_TYPE(KeyReleased);
	};

}