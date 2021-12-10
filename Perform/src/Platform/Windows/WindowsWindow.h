#pragma once

#include "Perform/Window.h"
#include "GLFW/glfw3.h"

namespace Perform {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const std::string& title, unsigned int width, unsigned int height);
		~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override;
		unsigned int GetHeight() const override;

		void SetEventCallback(const EventCallbackFn& callback) override;
		void SetVsync(bool enabled) override;
		bool GetVsync() const override;

	private:
		void Init(const std::string& title, unsigned int width, unsigned int height);
		void Shutdown();

	private:
		GLFWwindow* m_Window;
		
		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;
			bool Vsync;

			EventCallbackFn EventCallback;
		};

		WindowData m_WindowData;
	};

}

