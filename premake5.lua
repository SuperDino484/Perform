workspace "Perform"
    architecture "x64"
    startproject "Sandbox"
    configurations { "Debug", "Release", "Dist" }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["Perform"] = "%{wks.location}/Perform/src"
IncludeDir["glfw"] = "%{wks.location}/Dependencies/glfw/include"
IncludeDir["glad"] = "%{wks.location}/Dependencies/glad/include"
IncludeDir["glm"] = "%{wks.location}/Dependencies/glm/include"
IncludeDir["spdlog"] = "%{wks.location}/Dependencies/spdlog/include"

group "Dependencies"
    --include "Dependencies/glfw"
    --include "Dependencies/glad"
group ""

include "Perform"
include "Sandbox"