#ifndef ASH_PROPERTYMANAGER_HPP
#define ASH_PROPERTYMANAGER_HPP

#include <cstddef>

namespace ash
{
	struct PropertyManager
	{
		bool sdl_initialized = false;
		std::size_t window_count = 0;
		bool sdl_cleanup_nowindow = true;
	};

	extern PropertyManager pman;
}

#endif // PROPERTYMANAGER_HPP
