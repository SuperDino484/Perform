#pragma once
#include "pfpch.h"
#include "Events/Event.h"

namespace Perform {

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVsync(bool enabled) = 0;
		virtual bool GetVsync() const = 0;

		static Window* Create(const std::string& title = "Perform", unsigned int width = 1080, unsigned int height = 720);
	};

}