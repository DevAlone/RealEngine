#include "../src/math/includes.h"

#include <iostream>

template <typename T, size_t D>
void printVector(const math::Vector<T, D>& vector)
{
	for(const auto& value : vector.getData())
		std::cout << value << ", ";
	std::cout << std::endl;
}

int main()
{
	auto v1 = math::Vector<int, 10>(1);
	auto v2 = math::Vector<int, 10>(7);
	auto v3 = v1 + v2;

	printVector(v3);

	auto v4 = v3 + math::Vector<int, 10>(2);

	printVector(v4);

	auto v5 = math::Vector<int, 10>(5) + v4;
	printVector(v5);
	v5 *= 10;
	printVector(v5);

//	ambiguous overload
//	auto v6 = math::Vector<int, 10>(100) + math::Vector<int, 10>(99);

	return 0;
}
