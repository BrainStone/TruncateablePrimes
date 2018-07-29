//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "primality.hpp"

bool is_prime( const mpz_class& number ) {
	uint64_t prime;
	uint64_t root = sqrt( number ).get_val().get_ui();
	primesieve::iterator it;

	std::clog << "\tRoot:" << root << std::endl;

	while ( (prime = it.next_prime()) <= root )
		std::clog << "\t\tPrime:" << prime << std::endl;

		if ( number % prime == 0 )
			return false;

	return true;
}
