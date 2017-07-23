#ifndef ASH_TRYCALL_HPP
#define ASH_TRYCALL_HPP

namespace ash
{
	template<typename F, typename... Args>
	auto try_call_impl(char, F&& f, Args... args) -> decltype(f(args...), void())
	{
		f(args...);
	}

	template<typename F, typename... Args>
	void try_call_impl(int, F&&, Args...) {}

	template<typename F, typename... Args>
	void try_call(F&& f, Args... args)
	{
		try_call_impl('0', f, args...);
	}
}

#endif // TRYCALL_HPP
