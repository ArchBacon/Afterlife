workspace "Afterlife"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Afterlife"
    
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Afterlife"
    location "Afterlife"
    kind "ConsoleApp"
    language "C++"
    staticruntime "On"
    
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
        "ThirdParty/SDL2/SDL2/include",
        "ThirdParty/SDL2/SDL2_image/include",
        "ThirdParty/SDL2/SDL2_ttf/include",
    }

    libdirs {
        "ThirdParty/SDL2/SDL2/lib",
        "ThirdParty/SDL2/SDL2_image/lib",
        "ThirdParty/SDL2/SDL2_ttf/lib",
    }

    links {
        "SDL2.lib",
        "SDL2main.lib",
        "SDL2_image.lib",
        "SDL2_ttf.lib",
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        postbuildcommands {
            ("{COPY} ../ThirdParty/SDL2/SDL2/lib/SDL2.dll ../Binaries/" .. outputdir .. "/Afterlife"),
            ("{COPY} ../ThirdParty/SDL2/SDL2_Image/lib/SDL2_image.dll ../Binaries/" .. outputdir .. "/Afterlife"),
            ("{COPY} ../ThirdParty/SDL2/SDL2_Image/lib/libpng16-16.dll ../Binaries/" .. outputdir .. "/Afterlife"),
            ("{COPY} ../ThirdParty/SDL2/SDL2_Image/lib/zlib1.dll ../Binaries/" .. outputdir .. "/Afterlife"),
            ("{COPY} ../ThirdParty/SDL2/SDL2_ttf/lib/SDL2_ttf.dll ../Binaries/" .. outputdir .. "/Afterlife"),
        }
    
    filter "configurations:Debug"
        defines { "_DEBUG" }
        runtime "Debug"
        symbols "On"
        
    filter "configurations:Release"
        defines { "_RELEASE" }
        runtime "Release"
        optimize "On"
        