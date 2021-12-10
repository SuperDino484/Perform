workspace "Perform"
    architecture "x64"
    startproject "Sandbox"
    configurations { "Debug", "Release", "Dist" }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["Perform"] = "%{wks.location}/Perform/src"
IncludeDir["glfw"] = "%{wks.location}/Perform/vendor/glfw/include"
IncludeDir["Glad"] = "%{wks.location}/Perform/vendor/Glad/include"
IncludeDir["glm"] = "%{wks.location}/Perform/vendor/glm/include"
IncludeDir["spdlog"] = "%{wks.location}/Perform/vendor/spdlog/include"

group "Dependencies"
    include "Perform/vendor/glfw"
    include "Perform/vendor/Glad"
group ""

include "Perform"
include "Sandbox"