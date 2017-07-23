#ifndef ASH_RANDOM_HPP
#define ASH_RANDOM_HPP

#include <random>
#include <type_traits>

namespace ash
{
	extern std::random_device rd;
	extern std::mt19937 rd_generator;

	template<class T>
	using distrib = std::conditional_t<std::is_integral<T>::value,
									   std::uniform_int_distribution<T>,
									   std::uniform_real_distribution<T>>;

	// random integer of type T in range [begin..end]
	// uniform distribution by default
	// supports integral and real T
	template<class T = int>
	T random(const T begin, const T end)
	{
		return distrib<T>{begin, end}(rd_generator);
	}

	// random integer of type T in range [0..end]
	// same characteristics as random(begin, end)
	template<class T = int>
	T random(const T end)
	{
		return random<T>(0., end);
	}

	// return a random floating point value in range [0..1]
	template<class T = float, std::enable_if_t<std::is_floating_point<T>::value>>
	T random()
	{
		return random<T>(0., 1.);
	}

	// random boolean {false, true}
	// user-provided probaility, defaults to 1/2 to get true
	// if p > 0.5 then true is more likely to be the result
	template<class RT>
	bool random_bool(const RT probability = 0.5)
	{
		return std::bernoulli_distribution{probability}(rd_generator);
	}
}

#endif // RANDOM_HPP
