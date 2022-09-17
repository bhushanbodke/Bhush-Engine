#pragma once

#ifdef  BH_PLATFORM_WINDOWS
	#ifdef BH_BUILD_DLL
		#define BH_API __declspec(dllexport)
	#else
		#define BH_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#error Bhush Engine only support Windows os
#endif //  HZ_PLATFORM_WINDOWS

#define BIT(x) (1 << x)