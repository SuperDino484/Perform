#pragma once
#include "pfpch.h"
#include "Perform/Core.h"

namespace Perform {


	/* Specifies which type of event it is specifically (more for getting the name as a string) */
	enum class EventType
	{
		None = 0,
		WindowResize, WindowClose, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		AppTick, AppUpdate, AppRender
	};

	/* Specifies the type of filters possible for each event type (useful to check for certain events) */
	/* It does so in a bitfield to be able to add multiple filters for events */
	enum EventFilter
	{
		None = 0,
		EventTypeApplication = BIT(0),
		EventTypeInput = BIT(1),
		EventTypeKeyBoard = BIT(2),
		EventTypeMouse = BIT(3)
	};

	/* Macros to construct the classes */
#define EVENT_SETUP(event_type) static EventType GetStaticEventType() { return EventType::##event_type; } \
								EventType GetEventType() const override { return GetStaticEventType(); } \
								const char* GetEventName() const override { return #event_type; } \
								
#define EVENT_FILTERS(filters)  int GetFilterFlags() const { return EventFilter::##filters; }

	class Event
	{
		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetEventName() const = 0;
		virtual int GetFilterFlags() const = 0;
		virtual std::string ToString() const { return GetEventName(); }

		inline bool IsHandled() { return m_Handled; }

		inline bool IsInCategory(EventFilter filter)
		{
			return GetFilterFlags() & filter;
		}

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		/* Event binding using reference that will return bool if successful or if should stop */
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& e)
			: m_Event(e) {};

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticEventType())
			{
				/* Run the function on event and set the event to handled if it handled it */
				/* Cast the event to the new event type if they are equal to be able to pass it in parameter */
				m_Event.m_Handled = func(*(reinterpret_cast<T*>(&m_Event)));
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

}