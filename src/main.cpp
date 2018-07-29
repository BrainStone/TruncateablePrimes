//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include <iostream>

#include <gmpxx.h>

#include "primality.hpp"

int main() {
	mpz_class test( 1 );

	std::cout << test << std::endl;

	for ( int i = 0; i < 100; ++i ) {
		test <<= 1;

		std::cout << test << std::endl;
	}

	mpz_class prime( "357686312646216567629137" );

	std::cout << prime << " has " << mpz_sizeinbase( prime.get_mpz_t(), 2 ) << " bits and " << (is_prime( prime ) ? "is" : "is not") << " a prime." << std::endl;
}
