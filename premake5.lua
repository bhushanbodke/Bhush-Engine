workspace "Bhush Engine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}
output_Dir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
dir = "bin/Debug-windows-x86_64"
project "Bhush Engine"
	location "Bhush Engine"
	kind "SharedLib"
	language "c++"
	targetdir ("bin/"..output_Dir.."/%{prj.name}")
	objdir	  ("bin-int/"..output_Dir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	file_name = "Bhush Engine.dll"
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		"BH_PLATFORM_WINDOWS",
		"BH_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "BH_DEBUG"
		symbols "On"
 
	filter "configurations:Release"
		defines "BH_Release"
		optimize "On"
		
	filter "configurations:Dist"
		defines "BH_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "c++"
	targetdir ("bin/"..output_Dir.."/%{prj.name}")
	objdir	  ("bin-int/"..output_Dir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"Bhush Engine/vendor/spdlog/include",
		"Bhush Engine/src"
	}
	links
	{
		"Bhush Engine"
	}
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		"BH_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BH_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BH_Release"
		optimize "On"
		
	filter "configurations:Dist"
		defines "BH_DIST"
		optimize "On"

	