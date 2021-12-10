#pragma once
#include "Event.h"

namespace Perform {

	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_FILTERS(EventTypeInput | EventTypeKeyBoard);

	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatcount)
			: KeyEvent(keycode), m_RepeatCount(repeatcount) {}
		
		inline int GetRepeatCount() const { return m_RepeatCount; }

		EVENT_SETUP(KeyPressed);


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << "(key=" << m_KeyCode << " repeat=" << m_RepeatCount << ")";
			return ss.str();
		}

	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		EVENT_SETUP(KeyReleased);

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << "(key=" << m_KeyCode << ")";
			return ss.str();
		}
	};

}