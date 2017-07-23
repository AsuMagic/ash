#include <ash/util/logger.hpp>
#include <iomanip>
#include <ctime>

namespace ash
{
	LogMuxer::LogMuxer(std::vector<LogTarget>& targets, const Logger& logger, const LogLevel level) :
		_targets(&targets)
	{
		std::time_t time = std::time(nullptr);
		std::tm* tm = std::localtime(&time);
		*this << LogColor::DarkGray << std::setfill('0') << '[' << std::setw(2) << tm->tm_hour << ':' << std::setw(2) << tm->tm_min << ':' << std::setw(2) << tm->tm_sec << "] "
			  << logger.prefix_color << '[' << logger.prefix << ']'
			  << static_cast<LogColor>(level) << ' ';
	}

	LogMuxer::~LogMuxer()
	{
		for (LogTarget& target : *_targets)
			*target.stream << std::endl;
	}

	LogMuxer& LogMuxer::operator<<(const LogColor color)
	{
		for (LogTarget& target : *_targets)
		{
			if (target.ansi_support)
				*target.stream << "\033[" << static_cast<int>(color) << "m";
		}

		return *this;
	}

	LogTarget log_cout{&std::cout, stdout_ansi};

	Logger cdebug{"dbg", LogColor::LightMagenta, {log_cout}},
		   cengine{"ash", LogColor::LightBlue, {log_cout}},
		   cgraphics{"gfx", LogColor::LightGreen, {log_cout}},
		   caudio{"snd", LogColor::LightCyan, {log_cout}},
		   cgame{"app", LogColor::LightYellow, {log_cout}};

	LogMuxer Logger::operator()(const LogLevel level)
	{
		return {targets, *this, level};
	}
}
