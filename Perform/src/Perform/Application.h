#pragma once

#include "Perform/Core.h"

namespace Perform {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}

