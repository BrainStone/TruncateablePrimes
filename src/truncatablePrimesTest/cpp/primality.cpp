//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include <gtest/gtest.h>

#include "primality.hpp"

TEST( PrimalityTest, SimplePrimes ) {
	EXPECT_FALSE( is_prime( 123_mpz ) );
	EXPECT_FALSE( is_prime( 121_mpz ) );
	EXPECT_TRUE( is_prime( 127_mpz ) );

	EXPECT_FALSE( is_prime( 566547_mpz ) );
	EXPECT_TRUE( is_prime( 566549_mpz ) );

	EXPECT_FALSE( is_prime( 2147483641_mpz ) );
	EXPECT_TRUE( is_prime( 2147483647_mpz ) );

	EXPECT_FALSE( is_prime( 566547_mpz ) );
	EXPECT_TRUE( is_prime( 2305843009213693951_mpz ) );
}

TEST( PrimalityTest, TwinPrimeProducts ) {
	// 1st twin prime pair
	EXPECT_FALSE( is_prime( 3_mpz * 5_mpz ) );
	// 12th twin prime pair
	EXPECT_FALSE( is_prime( 149_mpz * 151_mpz ) );
	// 123th twin prime pair
	EXPECT_FALSE( is_prime( 4787_mpz * 4789_mpz ) );
	// 1234th twin prime pair
	EXPECT_FALSE( is_prime( 101207_mpz * 101209_mpz ) );
	// 12345th twin prime pair
	EXPECT_FALSE( is_prime( 1612181_mpz * 1612183_mpz ) );
}
