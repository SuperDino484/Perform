#pragma once


#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory>

namespace Perform {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define PF_CORE_TRACE(...)		::Perform::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PF_CORE_INFO(...)		::Perform::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PF_CORE_WARN(...)		::Perform::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PF_CORE_ERROR(...)		::Perform::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PF_CORE_CRITICAL(...)	::Perform::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define PF_TRACE(...)			::Perform::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PF_INFO(...)			::Perform::Log::GetClientLogger()->info(__VA_ARGS__)
#define PF_WARN(...)			::Perform::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PF_ERROR(...)			::Perform::Log::GetClientLogger()->error(__VA_ARGS__)
#define PF_CRITICAL(...)		::Perform::Log::GetClientLogger()->critical(__VA_ARGS__)

