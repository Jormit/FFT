#include <iostream>
#include "FFT.h"

int main()
{
	complex_vector input = { 1,-1,1,-1,1,-1,1,-1 };
	auto output = FFT(input);
	for (auto elem : output) {
		std::cout << elem;
	}	
	return 0;
}