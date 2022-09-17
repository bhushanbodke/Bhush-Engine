#pragma once
#include "Core.h"

namespace bhush {
	class BH_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};
	/*to be defined in client*/
	bhush::Application* createApplication();
}

