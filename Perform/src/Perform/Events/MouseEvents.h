#pragma once
#include "Event.h"

namespace Perform {

	class MouseButtonEvent : public Event
	{
	public:
		int GetMouseButton() const { return m_Button; }

		EVENT_FILTERS(EventFilter::EventTypeInput | EventFilter::EventTypeMouse);

	protected:
		MouseButtonEvent(int button)
			: m_Button(button) {}

		int m_Button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		EVENT_SETUP(MouseButtonPressed);

	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		EVENT_SETUP(MouseButtonReleased);

	};

	class MouseScrollEvent : public Event
	{
	public:
		MouseScrollEvent(float xOffset, float yOffset)
			: m_OffsetX(xOffset), m_OffsetY(yOffset) {}

		float GetOffsetX() const { return m_OffsetX; }
		float GetOffsetY() const { return m_OffsetY; }

		EVENT_SETUP(MouseScrolled);
		EVENT_FILTERS(EventFilter::EventTypeInput | EventFilter::EventTypeMouse);


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << "(xOffset=" << m_OffsetX << " yOffset=" << m_OffsetY << ")";
			return ss.str();
		}

	private:
		float m_OffsetX;
		float m_OffsetY;
	};

	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float xpos, float ypos)
			: m_PosX(xpos), m_PosY(ypos) {}

		float GetX() const { return m_PosX; }
		float GetY() const { return m_PosY; }

		EVENT_SETUP(MouseMoved);
		EVENT_FILTERS(EventFilter::EventTypeInput | EventFilter::EventTypeMouse);

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetEventName() << "(xPosition= " << m_PosX << " yPosition= " << m_PosY << ")";
			return ss.str();
		}

	private:
		float m_PosX;
		float m_PosY;
	};

}