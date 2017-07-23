#include <ash/util/file.hpp>
#include <fstream>

namespace ash
{
	std::string load_file(const std::string filename)
	{
		std::ifstream in{filename, std::ios::in};
		in.exceptions(std::ios::badbit | std::ios::failbit);

		std::string ret;
		in.seekg(0, std::ios::end);
		ret.resize(static_cast<std::size_t>(in.tellg()));
		in.seekg(0, std::ios::beg);
		in.read(&(ret[0]), static_cast<long>(ret.size()));
		return ret;
	}
}
