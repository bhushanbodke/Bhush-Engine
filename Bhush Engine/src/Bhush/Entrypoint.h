#pragma once

#ifdef BH_PLATFORM_WINDOWS

extern bhush::Application* bhush::createApplication();

int main(int argc,char** argv) {
	bhush::Log::Init();
	HZ_CORE_WARN("Initialized ");
	HZ_INFO("Initialized ");
	auto app = bhush::createApplication();
	app->Run();
	delete app;
}

#endif