#pragma once

#include "Perform/Core.h"
#include "Perform/Window.h"
#include "Perform/LayerStack.h"
#include "Perform/Events/Event.h"
#include "Perform/Events/ApplicationEvent.h"


namespace Perform {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		void PushOverlay(Layer* overlay);
		void PushLayer(Layer* layer);

		inline const Window& GetWindow() const { return *m_Window; }

		inline static Application* Get() { return s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool m_Running;
		static Application* s_Instance;
	};

	Application* CreateApplication();

}

