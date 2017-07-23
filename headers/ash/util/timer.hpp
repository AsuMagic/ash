#ifndef ASH_TIMER_HPP
#define ASH_TIMER_HPP

#include <chrono>

namespace ash
{
	class Timer
	{
		std::chrono::time_point<std::chrono::system_clock> _start, _end;

	public:
		Timer();

		float restart();
		float peek();
	};
}

#endif // TIMER_HPP
