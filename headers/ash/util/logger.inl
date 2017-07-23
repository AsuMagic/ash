#ifndef ASH_LOGGER_INL
#define ASH_LOGGER_INL

#include "logger.hpp"

namespace ash
{
	template<class T>
	LogMuxer& LogMuxer::operator<<(const T& in)
	{
		for (LogTarget& target : *_targets)
			*target.stream << in;

		return *this;
	}
}

#endif // LOGGER_INL
