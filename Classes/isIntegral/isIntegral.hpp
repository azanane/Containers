#ifndef ISINTEGRAL_HPP
# define ISINTEGRAL_HPP

# include <iostream>

namespace ft {

	template< const bool _value >
	struct integral_constant {

		static const bool value = _value;
	};

	typedef integral_constant<true> true_type;
	typedef integral_constant<false> false_type;

	template<typename T>
	struct is_integral : false_type {};

	template<typename T>
	struct is_integral<const T> : is_integral<T> {};


	template<>
	struct is_integral<int> : true_type {};

	template<>
	struct is_integral<long> : true_type {};

	template<>
	struct is_integral<char16_t> : true_type {};

	template<>
	struct is_integral<char32_t> : true_type {};

	template<>
	struct is_integral<wchar_t> : true_type {};

	template<>
	struct is_integral<short> : true_type {};

	template<>
	struct is_integral<long long> : true_type {};


}

#endif
