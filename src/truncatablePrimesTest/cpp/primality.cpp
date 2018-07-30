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

TEST( PrimalityTest, ExpectTestCase ) {
	EXPECT_TRUE( true );
	EXPECT_TRUE( true );
	EXPECT_TRUE( false );
	EXPECT_TRUE( true );
	EXPECT_TRUE( true );
	EXPECT_TRUE( false );
}

TEST( PrimalityTest, AssertTestCase ) {
	ASSERT_TRUE( true );
	ASSERT_TRUE( true );
	ASSERT_TRUE( false );
	ASSERT_TRUE( true );
	ASSERT_TRUE( true );
	ASSERT_TRUE( false );
}
