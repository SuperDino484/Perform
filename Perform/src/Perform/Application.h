#pragma once

#include "Perform/Core.h"
#include "Perform/Window.h"
#include "Perform/Events/Event.h"
#include "Perform/Events/ApplicationEvent.h"
#include "Perform/Events/KeyEvent.h"
#include "Perform/Events/MouseEvents.h"

namespace Perform {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running;
	};

	Application* CreateApplication();

}

