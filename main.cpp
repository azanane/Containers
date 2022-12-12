#include "Classes/vector/vectorClass/vector.hpp"
#include "Classes/vector/vectorIterator/vectorIterator.hpp"
#include <vector>

int	main() {

	ft::vector<int>	vec;

	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);

	ft::vector<int>::iterator it;
	
	for (it = vec.begin(); it != vec.end(); ++it) {

		PRINT( *it )
	}

	return	0;
}