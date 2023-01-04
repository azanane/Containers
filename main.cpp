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

	// ft::vector<std::string>	vec;

	// vec.push_back("5");
	// vec.push_back("efhkfhkfjk fsm");
	// vec.push_back("f `,fsfsmfs");

	// ft::vector<std::string>::iterator it;
	
	// for (it = vec.begin(); it != vec.end(); ++it) {

	// 	PRINT( *it )
	// }

	// vec.clear();
	// PRINT(std::endl << "size: " << vec.size())


	// ft::vector<int> v1(10, 0);
    // // Prefer container.data() over &container[0]
    // pointer_func(v1.data(), v1.size());

	// ft::vector<int> v2(v1.begin(), v1.end());
	// PRINT("hey")
	// pointer_func(v2.data(), v2.size());


	// ft::vector<char> characters;
 
 
    // characters.assign(5, 'a');
    // pointer_func(characters.data(), characters.size());
 
    // const std::string extra(6, 'b');
    // characters.assign(extra.begin(), extra.end());
    // pointer_func(characters.data(), characters.size());

	ft::vector<int> a1(1, 3);
	ft::vector<int> a2(4, 5);
 
    ft::vector<int>::iterator it1 = a1.begin();
    ft::vector<int>::iterator it2 = a2.begin();
 
	int& ref1 = a1.front();
	int& ref2 = a2.front();

	pointer_func(a1.data(), a1.size());
	pointer_func(a2.data(), a2.size());
	std::cout << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';

	a1.swap(a2);

	pointer_func(a1.data(), a1.size());
	pointer_func(a2.data(), a2.size());
	std::cout << *it1 << ' ' << *it2 << ' ' << ref1 << ' ' << ref2 << '\n';

	return 0;
}
