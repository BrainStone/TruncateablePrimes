//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include <iostream>
#include <string>

#include <gmpxx.h>

#include "primality.hpp"

void do_primnecheck( mpz_class num );

#ifndef GOOGLE_TEST
int main() {
	const std::string number( "357686312646216567629137" );

	for ( int i = number.size() - 1; i >= 0; --i ) {
		do_primnecheck( mpz_class( std::string( number, i ) ) );
	}
}
#endif

void do_primnecheck( mpz_class num ) {
	std::cout << num << " has " << mpz_sizeinbase( num.get_mpz_t(), 2 ) << " bits" << std::flush;
	std::cout << " and " << (is_prime( num ) ? "is" : "is not") << " a prime." << std::endl;
}
