#include "Classes/vector/vectorClass/vector.hpp"
#include "Classes/vector/vectorIterator/vectorIterator.hpp"
#include <vector>

void pointer_func(const int* p, std::size_t size)
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << '\n';
}

int	main() {

	ft::vector<std::string>	vec;

	vec.push_back("5");
	vec.push_back("efhkfhkfjk fsm");
	vec.push_back("f,fsfsmfs");

	ft::vector<std::string>::iterator it;
	
	for (it = vec.begin(); it != vec.end(); ++it) {

		PRINT( *it )
	}

	vec.clear();
	PRINT(std::endl << "size: " << vec.size())


	ft::vector<int> v1(10, 0);
    // Prefer container.data() over &container[0]
    pointer_func(v1.data(), v1.size());



	return	0;
}
