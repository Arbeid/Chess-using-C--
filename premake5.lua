workspace "ChessC++"
   configurations { "Debug","Release"}
   platforms "x32"

   outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   includedirs "Vendor"

   libdirs
   {
			"Vendor/GLEW",
			"Vendor/GLFW"
   }

   links
   {
		  "opengl32.lib",
		  "glew32s.lib",
		  "glfw3.lib"
   }

   startproject "ChessGame"

   project "ChessApp"
	location "ChessApp"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs "%{prj.name}/src"

	filter "configurations:Debug"
		defines "PR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PR_RELEASE"
		optimize "On"

   project "ChessGame"
	location "ChessGame"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"ChessApp/src",
		"%{prj.name}/src",
	}

	links
	{
		"ChessApp"
	}

	filter "configurations:Debug"
		defines "PR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PR_RELEASE"
		optimize "On"
