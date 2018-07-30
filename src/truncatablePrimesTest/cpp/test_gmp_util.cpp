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

TEST( GMPUtilTest, mpzToUint64General ) {
	// A few random uints
	EXPECT_EQ( mpz_class_to_uint64_t( 9681666858668565181_mpz ), 9681666858668565181LLU );
	EXPECT_EQ( mpz_class_to_uint64_t( 4245223178035231249_mpz ), 4245223178035231249LLU );
	EXPECT_EQ( mpz_class_to_uint64_t( 15797971957385167003_mpz ), 15797971957385167003LLU );
	EXPECT_EQ( mpz_class_to_uint64_t( 5078330763103564715_mpz ), 5078330763103564715LLU );
	EXPECT_EQ( mpz_class_to_uint64_t( 10777124245617543848_mpz ), 10777124245617543848LLU );
}

TEST( GMPUtilTest, mpzToUint64Zero ) {
	EXPECT_EQ( mpz_class_to_uint64_t( 0_mpz ), 0LLU );
}

TEST( GMPUtilTest, mpzToUint64Negative ) {
	try {
		mpz_class_to_uint64_t( -1_mpz );

		ADD_FAILURE();
	} catch ( const std::out_of_range& e ) {
		EXPECT_STREQ( e.what(), "The number cannot negative: -1" );
	} catch ( ... ) {
		ADD_FAILURE();
	}

	try {
		mpz_class_to_uint64_t( -123456789_mpz );

		ADD_FAILURE();
	} catch ( const std::out_of_range& e ) {
		EXPECT_STREQ( e.what(), "The number cannot negative: -123456789" );
	} catch ( ... ) {
		ADD_FAILURE();
	}
}

TEST( GMPUtilTest, mpzToUint64OutOfRange) {
	try {
		mpz_class_to_uint64_t( 18446744073709551616_mpz );

		ADD_FAILURE();
	} catch ( const std::out_of_range& e ) {
		EXPECT_STREQ( e.what(), "The number cannot be stored in a uint64_t: 18446744073709551616" );
	} catch ( ... ) {
		ADD_FAILURE();
	}

	try {
		mpz_class_to_uint64_t( 75836894769847637687899681666858668565181489789673548789376878394567987583689476984763768789968166685866856518184467440737095516161489789673548789376878394567987583689476984763768789968166685866856518148978967354878937687839456798758368947698476376878996816668586685651818446744073709551616148978967354878937687839456798_mpz );

		ADD_FAILURE();
	} catch ( const std::out_of_range& e ) {
		EXPECT_STREQ( e.what(), "The number cannot be stored in a uint64_t: 75836894769847637687899681666858668565181489789673548789376878394567987583689476984763768789968166685866856518184467440737095516161489789673548789376878394567987583689476984763768789968166685866856518148978967354878937687839456798758368947698476376878996816668586685651818446744073709551616148978967354878937687839456798" );
	} catch ( ... ) {
		ADD_FAILURE();
	}
}
