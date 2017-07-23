#include <ash/graphics/image.hpp>

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
		// TODO not implemented
		std::terminate();

		_width = new_width;
		_height = new_height;

		return *this;
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
