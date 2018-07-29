//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "primality.hpp"

bool is_prime( const mpz_class& number ) {
	int reps = 8;
	int result;

	do {
		reps *= 2;
		result = mpz_probab_prime_p( number.get_mpz_t(), reps );
	} while ( result == 1 );

	return result;
}
