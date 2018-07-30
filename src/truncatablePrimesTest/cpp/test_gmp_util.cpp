//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include <gtest/gtest.h>

#include "gmp_util.hpp"

TEST( GMPUtilTest, uint64ToMpz ) {
	// A few random uints
	EXPECT_EQ( uint64_t_to_mpz_class( 9681666858668565181LLU ), 9681666858668565181_mpz );
	EXPECT_EQ( uint64_t_to_mpz_class( 4245223178035231249LLU ), 4245223178035231249_mpz );
	EXPECT_EQ( uint64_t_to_mpz_class( 15797971957385167003LLU ), 15797971957385167003_mpz );
	EXPECT_EQ( uint64_t_to_mpz_class( 5078330763103564715LLU ), 5078330763103564715_mpz );
	EXPECT_EQ( uint64_t_to_mpz_class( 10777124245617543848LLU ), 10777124245617543848_mpz );
}
