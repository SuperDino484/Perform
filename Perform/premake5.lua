project "Perform"
    kind "StaticLib"
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
        --"%{IncludeDir.glfw}",
        --"%{IncludeDir.glad}",
        --"%{IncludeDir.glm}",
        --"%{IncludeDir.spdlog}"
    }

    links {
        --"glfw",
        --"glad",
        --"opengl32"
    }

    defines {
        "GLFW_INCLUDE_NONE"
    }

    filter "system:windows"
        defines {
            "PF_PLATFORM_WINDOWS"
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