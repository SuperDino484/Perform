#pragma once
#include "Perform/Application.h"

#ifdef PF_PLATFORM_WINDOWS

extern Perform::Application* Perform::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Perform::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif