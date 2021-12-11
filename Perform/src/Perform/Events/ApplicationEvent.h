#pragma once
#include "Event.h"

namespace Perform {

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		EVENT_SETUP(WindowResize);
		EVENT_FILTERS(EventTypeApplication);

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << "(width= " << m_Width << " height=" << m_Height << ")";
			return ss.str();
		}

	private:
		unsigned int m_Width;
		unsigned int m_Height;

	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_SETUP(WindowClose);
		EVENT_FILTERS(EventTypeApplication);

	};

	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}

		EVENT_SETUP(WindowFocus);
		EVENT_FILTERS(EventTypeApplication);
	};

	class WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}

		EVENT_SETUP(WindowLostFocus);
		EVENT_FILTERS(EventTypeApplication);
	};

	class WindowMoveEvent : public Event
	{
	public:
		WindowMoveEvent(unsigned int xpos, unsigned int ypos)
			: m_PosX(xpos), m_PosY(ypos) {}

		EVENT_SETUP(WindowMoved);
		EVENT_FILTERS(EventTypeApplication);

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << "(x=" << m_PosX << " y=" << m_PosY << ")";
			return ss.str();
		}

	private:
		unsigned int m_PosX;
		unsigned int m_PosY;
	};

}