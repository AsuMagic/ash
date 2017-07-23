#include <ash/util/random.hpp>

namespace ash
{
	std::random_device rd;
	std::mt19937 rd_generator(rd());
}
