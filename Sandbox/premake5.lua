project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "**.cpp",
        "**.h"
    }

    includedirs {
        "src",
        "%{IncludeDir.Perform}"
    }

    links {
        "Perform"
    }

    filter "system:windows"
        defines {
            "PF_PLATFORM_WINDOWS",
        }

    filter {"configurations:Debug", "system:windows"}
        systemversion "latest"
        buildoptions "/MTd"
        runtime "Debug"
        symbols "on"

    filter {"configurations:Release", "system:windows"}
        systemversion "latest"
        buildoptions "/MT"
        runtime "Release"
        optimize "on"