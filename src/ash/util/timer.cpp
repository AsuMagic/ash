#include <ash/util/timer.hpp>

namespace ash
{
	Timer::Timer()
	{
		_start = std::chrono::system_clock::now();
	}

	float Timer::restart()
	{
		_end = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsed = _end - _start;
		_start = _end;

		return elapsed.count();
	}

	float Timer::peek()
	{
		_end = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsed = _end - _start;
		return elapsed.count();
	}
}
