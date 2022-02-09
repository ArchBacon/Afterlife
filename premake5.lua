workspace "Afterlife"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Afterlife"
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Afterlife"
    location "Afterlife"
    kind "ConsoleApp"
    language "C++"
    staticruntime "Off"
    
    targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")
    
    files {
        "%{prj.name}/main.cpp",
        "%{prj.name}/Engine/**.h",
        "%{prj.name}/Engine/**.cpp",
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp",
        "%{prj.name}/Assets/**",
    }
    
    includedirs {
        "%{prj.name}/Engine/Public",
        "%{prj.name}/Source/Public",
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"
    
    filter "configurations:Debug"
        defines { "AE_DEBUG" }
        runtime "Debug"
        symbols "On"
        
    filter "configurations:Release"
        defines { "AE_RELEASE" }
        runtime "Release"
        optimize "On"
        