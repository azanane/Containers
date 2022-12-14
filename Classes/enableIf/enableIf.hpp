#ifndef ENABLEIF_HPP
# define ENABLEIF_HPP

namespace ft {

	template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> { typedef T type; };
}

#endif
