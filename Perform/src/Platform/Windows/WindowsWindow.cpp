#include "pfpch.h"
#include "WindowsWindow.h"
#include "Perform/Events/ApplicationEvent.h"
#include "Perform/Events/KeyEvent.h"
#include "Perform/Events/MouseEvent.h"

namespace Perform {

	Window* Window::Create(const std::string& title /* = "Perform" */, unsigned int width /* = 720 */, unsigned int height /* = 480 */)
	{
		return new WindowsWindow(title, width, height);
	}

	WindowsWindow::WindowsWindow(const std::string& title, unsigned int width, unsigned int height)
	{
		Init(title, width, height);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	unsigned int WindowsWindow::GetWidth() const
	{
		return m_WindowData.Width;
	}

	unsigned int WindowsWindow::GetHeight() const
	{
		return m_WindowData.Height;
	}

	void WindowsWindow::SetEventCallback(const EventCallbackFn& callback)
	{
		m_WindowData.EventCallback = callback;
	}

	void WindowsWindow::SetVsync(bool enabled)
	{
		m_WindowData.Vsync = enabled;
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	bool WindowsWindow::GetVsync() const
	{
		return m_WindowData.Vsync;
	}

	void WindowsWindow::Init(const std::string& title, unsigned int width, unsigned int height)
	{
		m_WindowData.Title = title;
		m_WindowData.Width = width;
		m_WindowData.Height = height;

		PF_CORE_INFO("Initialized Window(title={0}, width={1}, height={2})", title, width, height);

		int success = glfwInit();
		PF_CORE_ASSERT(success, "Could not initialize glfw");

		m_Window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowData);
		SetVsync(true);

		/* Sets up glfw callbacks */
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
				data.Width = width;
				data.Height = height;
				WindowResizeEvent e(width, height);
				data.EventCallback(e);
			});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
				WindowCloseEvent e;
				data.EventCallback(e);
			});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent e(key, 0);
						data.EventCallback(e);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent e(key);
						data.EventCallback(e);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent e(key, 1);
						data.EventCallback(e);
						break;
					}
				}
			});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent e(button);
					data.EventCallback(e);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent e(button);
					data.EventCallback(e);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
				MouseScrollEvent e((float)xoffset, (float)yoffset);
				data.EventCallback(e);
			});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
			{
				WindowData& data = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
				MouseMovedEvent e((float)xpos, (float)ypos);
				data.EventCallback(e);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

}
