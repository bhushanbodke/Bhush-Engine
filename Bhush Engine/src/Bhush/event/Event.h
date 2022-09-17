#pragma once

#include<string.h>
#include<functional>
#include "../Core.h"

namespace bhush
{

	enum class EventType
	{
		None = 0,
		WindowClose,WindowResize,WindowFocous,WindowLostFocus,WindowMoved,
		AppTick,Appupdate,AppRender,
		KeyPressed,KeyReleased,
		MouseButtonPressed, MouseButtonReleased,MouseMoved,MouseScrolled
	};
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput		 = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	/*GetStaticEvent Need To get Event type at runtime it is static so that we don't need instance of class*/
	/*GetEventType is needed to get Event Type if we have Event class instance*/
#define Event_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::##type;}\
								virtual EventType GetEventType() const override{return GetStaticType();}\
								virtual const char* GetName()const override{return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlag()const override{return category;}

	class BH_API Event
	{
	public:
		virtual EventType GetEventType()const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlag() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlag() & category;
		}
	protected:
		bool m_handled = false;



	};
}