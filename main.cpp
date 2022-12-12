#include "Classes/vector/vectorClass/vector.hpp"
#include "Classes/vector/vectorIterator/vectorIterator.hpp"

int	main() {

	ft::vector<int>	vec;
	ft::vector<int>::vectorIterator it;

	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);

	return	0;
}