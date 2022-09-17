#pragma once
#include"Event.h"

namespace bhush {

	class BH_API MouseMovedEvent :public Event
	{
	public:
		MouseMovedEvent(float mouseX, float mouseY)
			:m_MouseX(mouseX), m_MouseY(mouseY) {};
		inline float GetX()const { return m_MouseX; };
		inline float GetY()const { return m_MouseY; };
		Event_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	private:
		float m_MouseX, m_MouseY;
	};

	class BH_API MouseScrolledEvent :public Event
	{
	private:
		float m_xOffset, m_yOffset;
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			:m_xOffset(xOffset), m_yOffset(yOffset) {};
		inline float GetXOffset()const { return m_xOffset; }
		inline float GetYOffset()const { return m_yOffset; }
		Event_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
	};
	class BH_API MouseButtonEvent :public Event
	{
	private:
		int m_Button;
	public:
		inline int GetMouseEvent()const { return m_Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse| EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {};
	};
	class BH_API MouseButtonPressedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {};
		Event_CLASS_TYPE(MouseButtonPressed);
	};
	class BH_API MouseButtonReleasedEvent :public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {};
		Event_CLASS_TYPE(MouseButtonReleased);
	};
}