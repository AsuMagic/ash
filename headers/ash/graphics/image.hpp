#ifndef ASH_IMAGE_HPP
#define ASH_IMAGE_HPP

#include <vector>
#include <cstdint>
#include <cstddef>
#include "color.hpp"

namespace ash
{
	class Image
	{
		std::vector<ColorU> _image;
		std::size_t _width, _height;

	public:
		Image(const std::size_t width, const std::size_t height);

		uint8_t* data();

		ColorU& at(const std::size_t x, const std::size_t y);

		// Resize the image canvas (crop/extend with black pixels on border)
		Image& resize(const std::size_t new_width, const std::size_t new_height);

		std::size_t width() const;
		std::size_t height() const;
	};
}

#endif // IMAGE_HPP
