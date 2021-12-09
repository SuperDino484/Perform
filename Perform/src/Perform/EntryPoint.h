#pragma once
#include "Perform/Application.h"
#include "Perform/Log.h"

#ifdef PF_PLATFORM_WINDOWS

extern Perform::Application* Perform::CreateApplication();

int main(int argc, char** argv)
{
	Perform::Log::Init();
	auto app = Perform::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif