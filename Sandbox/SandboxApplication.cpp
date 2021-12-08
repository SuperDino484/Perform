#include <Perform.h>

class Sandbox : public Perform::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Perform::Application* Perform::CreateApplication()
{
	return new Sandbox();
}