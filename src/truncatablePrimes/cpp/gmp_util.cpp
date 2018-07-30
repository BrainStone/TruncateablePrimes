//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "gmp_util.hpp"

mpz_class uint64_t_to_mpz_class( uint64_t in ) {
	mpz_class out;

	mpz_import( out.get_mpz_t(), 1, 1, sizeof( uint64_t ), 0, 0, &in );

	return out;
}
