project "Perform"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pfpch.h"
    pchsource "src/pfpch.cpp"

    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs {
        "src",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.Glad}",
        --"%{IncludeDir.glm}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.ImGui}",
    }

    links {
        "glfw",
        "glad",
        "ImGui",
        "opengl32",
    }

    defines {
        "GLFW_INCLUDE_NONE",
        "IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
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