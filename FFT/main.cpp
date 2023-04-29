#include <iostream>
#include "FFT.h"

int main()
{
	complex_vector input = { 1,2,3,4,5,6,7,8 };
	auto output = FFT(input);
	for (auto elem : output) {
		std::cout << elem;
	}	
	return 0;
}