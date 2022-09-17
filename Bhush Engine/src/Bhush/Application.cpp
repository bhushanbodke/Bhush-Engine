#include <iostream>
#include "Application.h"
#include "event/ApplicationEvents.h"

namespace bhush {

	Application::Application() {

	}
	Application::~Application() {

	}
	void Application::Run() {
		WindowResizeEvent e(100, 250);
		std::cout << e.GetName() << std::endl;
		while (true);
	}
}
