#include <Perform.h>

class SandboxLayer : public Perform::Layer
{
public:
	SandboxLayer()
		: Layer("Sandbox Layer") {}

	void OnUpdate() override
	{
		PF_INFO("UPDATE");
	}


	void OnEvent(Perform::Event& e) override
	{
		PF_INFO(e.ToString());
	}

};

class Sandbox : public Perform::Application
{
public:
	Sandbox()
	{
		PushLayer(new SandboxLayer());
	}

	~Sandbox()
	{

	}
};

Perform::Application* Perform::CreateApplication()
{
	return new Sandbox();
}