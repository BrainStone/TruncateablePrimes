//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include <iostream>

#include <gmpxx.h>

#include "primality.hpp"

int main() {
	mpz_class prime1( "216567629137" );
	mpz_class prime2( "357686312646216567629137" );

	std::cout << prime1 << " has " << mpz_sizeinbase( prime1.get_mpz_t(), 2 ) << " bits" << std::flush;
	std::cout << " and " << (is_prime( prime1 ) ? "is" : "is not") << " a prime." << std::endl;

	std::cout << prime2 << " has " << mpz_sizeinbase( prime2.get_mpz_t(), 2 ) << " bits" << std::flush;
	std::cout << " and " << (is_prime( prime2 ) ? "is" : "is not") << " a prime." << std::endl;
}
