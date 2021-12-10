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
        "%{IncludeDir.Perform}",
        "%{IncludeDir.spdlog}",
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
        defines {
            "PF_DEBUG"
        }

    filter {"configurations:Release", "system:windows"}
        systemversion "latest"
        buildoptions "/MT"
        runtime "Release"
        optimize "on"
        defines {
            "PF_RELEASE"
        }

    filter {"configurations:Dist", "system:windows"}
        systemversion "latest"
        buildoptions "/MT"
        runtime "Release"
        optimize "on"
        defines {
            "PF_DIST"
        }