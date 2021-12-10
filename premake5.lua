workspace "Perform"
    architecture "x64"
    startproject "Sandbox"
    configurations { "Debug", "Release", "Dist" }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["Perform"] = "%{wks.location}/Perform/src"
IncludeDir["glfw"] = "%{wks.location}/Perform/vendor/glfw/include"
IncludeDir["glad"] = "%{wks.location}/Perform/vendor/glad/include"
IncludeDir["glm"] = "%{wks.location}/Perform/vendor/glm/include"
IncludeDir["spdlog"] = "%{wks.location}/Perform/vendor/spdlog/include"

group "Dependencies"
    include "Dependencies/glfw"
    --include "Dependencies/glad"
group ""

include "Perform"
include "Sandbox"