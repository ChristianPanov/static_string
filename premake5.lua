workspace "static_string"
	architecture "x64"
	startproject "Sandbox"

	configurations { 
		"Debug", "Release" 
	}

	flags { 
		"MultiProcessorCompile" 
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "static_string"
	location "static_string"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs { 
		"%{prj.name}/src",
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "STATIC_STRING_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "STATIC_STRING_RELEASE"
		runtime "Release"
		optimize "speed"

project "examples"
	location "examples"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	includedirs {
		"static_string/src"
	}

	links {
		"static_string"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "STATIC_STRING_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "STATIC_STRING_RELEASE"
		runtime "Release"
		optimize "on"