#ifndef ASH_LOGGER_HPP
#define ASH_LOGGER_HPP

#include <iostream>
#include <vector>
#include <ash/util/constexpr_string.hpp>

namespace ash
{
	#ifdef __unix__
	constexpr bool stdout_ansi = true;
	#else
	constexpr bool stdout_ansi = false;
	#endif

	enum class LogColor
	{
		Default = 39,

		Black = 30,
		White = 97,
		DarkGray = 90,
		LightGray = 37,

		Red = 31,
		LightRed = 91,
		Green = 32,
		LightGreen = 92,
		Yellow = 33,
		LightYellow = 93,
		Blue = 34,
		LightBlue = 94,
		Magenta = 35,
		LightMagenta = 95,
		Cyan = 36,
		LightCyan = 96,
	};

	enum class LogLevel
	{
		Default = static_cast<int>(LogColor::Default),
		Warning = static_cast<int>(LogColor::LightYellow),
		Error   = static_cast<int>(LogColor::LightRed)
	};

	struct LogTarget
	{
		std::ostream* stream = nullptr;
		bool ansi_support = false;
	};

	struct Logger;

	class LogMuxer
	{
		std::vector<LogTarget>* _targets;

	public:
		LogMuxer(std::vector<LogTarget>& targets, const Logger& logger, const LogLevel level);
		LogMuxer(const LogMuxer& other) = delete;
		LogMuxer& operator=(const LogMuxer& other) = delete;
		~LogMuxer();

		template<class T>
		LogMuxer& operator<<(const T& in);
		LogMuxer& operator<<(const LogColor color);
	};

	struct Logger
	{
		const std::string prefix;
		const LogColor prefix_color;
		std::vector<LogTarget> targets;

		LogMuxer operator()(const LogLevel level = LogLevel::Default);
	};

	extern LogTarget target_cout/*, target_logfile*/;

	extern Logger cdebug, cengine, cgraphics, caudio, cgame;
}

#include <ash/util/logger.hpp>

#endif // LOGGER_HPP
