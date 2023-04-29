#pragma once

#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>

using complex_vector = std::vector<std::complex<double>>;

complex_vector FFT(complex_vector& input) {
	int n = input.size();
	if (n == 1) {
		return input;
	}
	auto omega = std::polar(1.0, 2.0 * M_PI / n);

	complex_vector even_part;
	complex_vector odd_part;
	std::partition_copy(input.begin(), input.end(), 
		std::back_inserter(even_part), std::back_inserter(odd_part),
		[toggle = false](std::complex<double>) mutable { return toggle = !toggle; });

	complex_vector y_even = FFT(even_part);
	complex_vector y_odd = FFT(odd_part);

	complex_vector y(n);

	for (int i = 0; i < n / 2; i++) {
		auto exp = std::pow(omega, static_cast<double>(i));
		y[i]       = y_even[i] + exp * y_odd[i];
		y[i + n/2] = y_even[i] - exp * y_odd[i];
	}
	return y;
}
