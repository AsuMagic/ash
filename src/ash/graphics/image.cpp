#include <ash/graphics/image.hpp>
#include <cstring> // memcpy

namespace ash
{
	Image::Image(const std::size_t width, const std::size_t height) :
		_image(width * height),
		_width{width}, _height{height}
	{}

	uint8_t* Image::data()
	{
		return reinterpret_cast<uint8_t*>(_image.data());
	}

	ColorU& Image::at(const std::size_t x, const std::size_t y)
	{
		return _image[x + (y * _width)];
	}

	Image& Image::resize(const std::size_t new_width, const std::size_t new_height)
	{
		Image resized(new_width, new_height);
		
		for (std::size_t y = 0; y < std::min(_height, resized._height); ++y)
			std::memcpy(&resized._image[y * resized._width], &_image[y * _height], std::min(_width, resized._width));

		return (*this = std::move(resized));
	}

	std::size_t Image::width() const
	{
		return _width;
	}

	std::size_t Image::height() const
	{
		return _height;
	}
}
