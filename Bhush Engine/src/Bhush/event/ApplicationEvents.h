#pragma once
#include "Event.h"
namespace bhush
{
	class BH_API WindowResizeEvent :public Event
	{
	private:
		unsigned int m_Width, m_Height;
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) {};

		inline unsigned int GetWidth()const { return m_Width; };
		inline unsigned int GetHeight()const { return m_Height; };
		Event_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
	class BH_API WindowCloseEvent :public Event
	{
		WindowCloseEvent() {};
		Event_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}