//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "global_test_settings.hpp"

#include <random>

#include "truncate.hpp"

TEST( TruncatingTest, TruncateLeft ) {
	EXPECT_EQ( truncate_left( 0_mpz ), 0_mpz );
	EXPECT_EQ( truncate_left( 1_mpz ), 0_mpz );
	EXPECT_EQ( truncate_left( 21_mpz ), 1_mpz );
	EXPECT_EQ( truncate_left( 321_mpz ), 21_mpz );
	EXPECT_EQ( truncate_left( 4321_mpz ), 321_mpz );
	EXPECT_EQ( truncate_left( 54321_mpz ), 4321_mpz );
	EXPECT_EQ( truncate_left( 654321_mpz ), 54321_mpz );
	EXPECT_EQ( truncate_left( 7654321_mpz ), 654321_mpz );
	EXPECT_EQ( truncate_left( 87654321_mpz ), 7654321_mpz );
	EXPECT_EQ( truncate_left( 987654321_mpz ), 87654321_mpz );
	EXPECT_EQ( truncate_left( 10987654321_mpz ), 987654321_mpz );
	EXPECT_EQ( truncate_left( 210987654321_mpz ), 10987654321_mpz );
	EXPECT_EQ( truncate_left( 3210987654321_mpz ), 210987654321_mpz );
	EXPECT_EQ( truncate_left( 43210987654321_mpz ), 3210987654321_mpz );
	EXPECT_EQ( truncate_left( 543210987654321_mpz ), 43210987654321_mpz );
	EXPECT_EQ( truncate_left( 6543210987654321_mpz ), 543210987654321_mpz );
	EXPECT_EQ( truncate_left( 76543210987654321_mpz ), 6543210987654321_mpz );
	EXPECT_EQ( truncate_left( 876543210987654321_mpz ), 76543210987654321_mpz );
	EXPECT_EQ( truncate_left( 9876543210987654321_mpz ), 876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 109876543210987654321_mpz ), 9876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 2109876543210987654321_mpz ), 109876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 32109876543210987654321_mpz ), 2109876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 432109876543210987654321_mpz ), 32109876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 5432109876543210987654321_mpz ), 432109876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 65432109876543210987654321_mpz ), 5432109876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 765432109876543210987654321_mpz ), 65432109876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 8765432109876543210987654321_mpz ), 765432109876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 98765432109876543210987654321_mpz ), 8765432109876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 1098765432109876543210987654321_mpz ), 98765432109876543210987654321_mpz );
	EXPECT_EQ( truncate_left( 21098765432109876543210987654321_mpz ), 1098765432109876543210987654321_mpz );
}

TEST( TruncatingTest, TruncateRight ) {
	EXPECT_EQ( truncate_right( 0_mpz ), 0_mpz );
	EXPECT_EQ( truncate_right( 1_mpz ), 0_mpz );
	EXPECT_EQ( truncate_right( 12_mpz ), 1_mpz );
	EXPECT_EQ( truncate_right( 123_mpz ), 12_mpz );
	EXPECT_EQ( truncate_right( 1234_mpz ), 123_mpz );
	EXPECT_EQ( truncate_right( 12345_mpz ), 1234_mpz );
	EXPECT_EQ( truncate_right( 123456_mpz ), 12345_mpz );
	EXPECT_EQ( truncate_right( 1234567_mpz ), 123456_mpz );
	EXPECT_EQ( truncate_right( 12345678_mpz ), 1234567_mpz );
	EXPECT_EQ( truncate_right( 123456789_mpz ), 12345678_mpz );
	EXPECT_EQ( truncate_right( 1234567890_mpz ), 123456789_mpz );
	EXPECT_EQ( truncate_right( 12345678901_mpz ), 1234567890_mpz );
	EXPECT_EQ( truncate_right( 123456789012_mpz ), 12345678901_mpz );
	EXPECT_EQ( truncate_right( 1234567890123_mpz ), 123456789012_mpz );
	EXPECT_EQ( truncate_right( 12345678901234_mpz ), 1234567890123_mpz );
	EXPECT_EQ( truncate_right( 123456789012345_mpz ), 12345678901234_mpz );
	EXPECT_EQ( truncate_right( 1234567890123456_mpz ), 123456789012345_mpz );
	EXPECT_EQ( truncate_right( 12345678901234567_mpz ), 1234567890123456_mpz );
	EXPECT_EQ( truncate_right( 123456789012345678_mpz ), 12345678901234567_mpz );
	EXPECT_EQ( truncate_right( 1234567890123456789_mpz ), 123456789012345678_mpz );
	EXPECT_EQ( truncate_right( 12345678901234567890_mpz ), 1234567890123456789_mpz );
	EXPECT_EQ( truncate_right( 123456789012345678901_mpz ), 12345678901234567890_mpz );
	EXPECT_EQ( truncate_right( 1234567890123456789012_mpz ), 123456789012345678901_mpz );
	EXPECT_EQ( truncate_right( 12345678901234567890123_mpz ), 1234567890123456789012_mpz );
	EXPECT_EQ( truncate_right( 123456789012345678901234_mpz ), 12345678901234567890123_mpz );
	EXPECT_EQ( truncate_right( 1234567890123456789012345_mpz ), 123456789012345678901234_mpz );
	EXPECT_EQ( truncate_right( 12345678901234567890123456_mpz ), 1234567890123456789012345_mpz );
	EXPECT_EQ( truncate_right( 123456789012345678901234567_mpz ), 12345678901234567890123456_mpz );
	EXPECT_EQ( truncate_right( 1234567890123456789012345678_mpz ), 123456789012345678901234567_mpz );
	EXPECT_EQ( truncate_right( 12345678901234567890123456789_mpz ), 1234567890123456789012345678_mpz );
	EXPECT_EQ( truncate_right( 123456789012345678901234567890_mpz ), 12345678901234567890123456789_mpz );
	EXPECT_EQ( truncate_right( 1234567890123456789012345678901_mpz ), 123456789012345678901234567890_mpz );
}

TEST( TruncatingTest, AppendLeft ) {
	EXPECT_EQ( append_left( 0_mpz, 1 ), 1_mpz );
	EXPECT_EQ( append_left( 1_mpz, 2 ), 21_mpz );
	EXPECT_EQ( append_left( 21_mpz, 3 ), 321_mpz );
	EXPECT_EQ( append_left( 321_mpz, 4 ), 4321_mpz );
	EXPECT_EQ( append_left( 4321_mpz, 5 ), 54321_mpz );
	EXPECT_EQ( append_left( 54321_mpz, 6 ), 654321_mpz );
	EXPECT_EQ( append_left( 654321_mpz, 7 ), 7654321_mpz );
	EXPECT_EQ( append_left( 7654321_mpz, 8 ), 87654321_mpz );
	EXPECT_EQ( append_left( 87654321_mpz, 9 ), 987654321_mpz );
	EXPECT_EQ( append_left( 987654321_mpz, 1 ), 1987654321_mpz );
	EXPECT_EQ( append_left( 10987654321_mpz, 2 ), 210987654321_mpz );
	EXPECT_EQ( append_left( 210987654321_mpz, 3 ), 3210987654321_mpz );
	EXPECT_EQ( append_left( 3210987654321_mpz, 4 ), 43210987654321_mpz );
	EXPECT_EQ( append_left( 43210987654321_mpz, 5 ), 543210987654321_mpz );
	EXPECT_EQ( append_left( 543210987654321_mpz, 6 ), 6543210987654321_mpz );
	EXPECT_EQ( append_left( 6543210987654321_mpz, 7 ), 76543210987654321_mpz );
	EXPECT_EQ( append_left( 76543210987654321_mpz, 8 ), 876543210987654321_mpz );
	EXPECT_EQ( append_left( 876543210987654321_mpz, 9 ), 9876543210987654321_mpz );
	EXPECT_EQ( append_left( 9876543210987654321_mpz, 1 ), 19876543210987654321_mpz );
	EXPECT_EQ( append_left( 109876543210987654321_mpz, 2 ), 2109876543210987654321_mpz );
	EXPECT_EQ( append_left( 2109876543210987654321_mpz, 3 ), 32109876543210987654321_mpz );
	EXPECT_EQ( append_left( 32109876543210987654321_mpz, 4 ), 432109876543210987654321_mpz );
	EXPECT_EQ( append_left( 432109876543210987654321_mpz, 5 ), 5432109876543210987654321_mpz );
	EXPECT_EQ( append_left( 5432109876543210987654321_mpz, 6 ), 65432109876543210987654321_mpz );
	EXPECT_EQ( append_left( 65432109876543210987654321_mpz, 7 ), 765432109876543210987654321_mpz );
	EXPECT_EQ( append_left( 765432109876543210987654321_mpz, 8 ), 8765432109876543210987654321_mpz );
	EXPECT_EQ( append_left( 8765432109876543210987654321_mpz, 9 ), 98765432109876543210987654321_mpz );
	EXPECT_EQ( append_left( 98765432109876543210987654321_mpz, 1 ), 198765432109876543210987654321_mpz );
	EXPECT_EQ( append_left( 1098765432109876543210987654321_mpz, 2 ), 21098765432109876543210987654321_mpz );
}

TEST( TruncatingTest, AppendLeftInvalid ) {
	EXPECT_THROW( append_left( 1234_mpz, -1 ), std::invalid_argument );
	EXPECT_THROW( append_left( 1234_mpz, 0 ), std::invalid_argument );
	EXPECT_THROW( append_left( 1234_mpz, 10 ), std::invalid_argument );
}

TEST( TruncatingTest, AppendRight ) {
	EXPECT_EQ( append_right( 0_mpz, 1 ), 1_mpz );
	EXPECT_EQ( append_right( 1_mpz, 2 ), 12_mpz );
	EXPECT_EQ( append_right( 12_mpz, 3 ), 123_mpz );
	EXPECT_EQ( append_right( 123_mpz, 4 ), 1234_mpz );
	EXPECT_EQ( append_right( 1234_mpz, 5 ), 12345_mpz );
	EXPECT_EQ( append_right( 12345_mpz, 6 ), 123456_mpz );
	EXPECT_EQ( append_right( 123456_mpz, 7 ), 1234567_mpz );
	EXPECT_EQ( append_right( 1234567_mpz, 8 ), 12345678_mpz );
	EXPECT_EQ( append_right( 12345678_mpz, 9 ), 123456789_mpz );
	EXPECT_EQ( append_right( 123456789_mpz, 0 ), 1234567890_mpz );
	EXPECT_EQ( append_right( 1234567890_mpz, 1 ), 12345678901_mpz );
	EXPECT_EQ( append_right( 12345678901_mpz, 2 ), 123456789012_mpz );
	EXPECT_EQ( append_right( 123456789012_mpz, 3 ), 1234567890123_mpz );
	EXPECT_EQ( append_right( 1234567890123_mpz, 4 ), 12345678901234_mpz );
	EXPECT_EQ( append_right( 12345678901234_mpz, 5 ), 123456789012345_mpz );
	EXPECT_EQ( append_right( 123456789012345_mpz, 6 ), 1234567890123456_mpz );
	EXPECT_EQ( append_right( 1234567890123456_mpz, 7 ), 12345678901234567_mpz );
	EXPECT_EQ( append_right( 12345678901234567_mpz, 8 ), 123456789012345678_mpz );
	EXPECT_EQ( append_right( 123456789012345678_mpz, 9 ), 1234567890123456789_mpz );
	EXPECT_EQ( append_right( 1234567890123456789_mpz, 0 ), 12345678901234567890_mpz );
	EXPECT_EQ( append_right( 12345678901234567890_mpz, 1 ), 123456789012345678901_mpz );
	EXPECT_EQ( append_right( 123456789012345678901_mpz, 2 ), 1234567890123456789012_mpz );
	EXPECT_EQ( append_right( 1234567890123456789012_mpz, 3 ), 12345678901234567890123_mpz );
	EXPECT_EQ( append_right( 12345678901234567890123_mpz, 4 ), 123456789012345678901234_mpz );
	EXPECT_EQ( append_right( 123456789012345678901234_mpz, 5 ), 1234567890123456789012345_mpz );
	EXPECT_EQ( append_right( 1234567890123456789012345_mpz, 6 ), 12345678901234567890123456_mpz );
	EXPECT_EQ( append_right( 12345678901234567890123456_mpz, 7 ), 123456789012345678901234567_mpz );
	EXPECT_EQ( append_right( 123456789012345678901234567_mpz, 8 ), 1234567890123456789012345678_mpz );
	EXPECT_EQ( append_right( 1234567890123456789012345678_mpz, 9 ), 12345678901234567890123456789_mpz );
	EXPECT_EQ( append_right( 12345678901234567890123456789_mpz, 0 ), 123456789012345678901234567890_mpz );
	EXPECT_EQ( append_right( 123456789012345678901234567890_mpz, 1 ), 1234567890123456789012345678901_mpz );
}

TEST( TruncatingTest, AppendRightInvalid ) {
	EXPECT_THROW( append_right( 1234_mpz, -1 ), std::invalid_argument );
	EXPECT_THROW( append_right( 1234_mpz, 10 ), std::invalid_argument );
}

TEST( TruncatingTest, ConvertCharDigitInt ) {
	EXPECT_EQ( convert_char_digit( 0 ), 0 );
	EXPECT_EQ( convert_char_digit( 1 ), 1 );
	EXPECT_EQ( convert_char_digit( 2 ), 2 );
	EXPECT_EQ( convert_char_digit( 3 ), 3 );
	EXPECT_EQ( convert_char_digit( 4 ), 4 );
	EXPECT_EQ( convert_char_digit( 5 ), 5 );
	EXPECT_EQ( convert_char_digit( 6 ), 6 );
	EXPECT_EQ( convert_char_digit( 7 ), 7 );
	EXPECT_EQ( convert_char_digit( 8 ), 8 );
	EXPECT_EQ( convert_char_digit( 9 ), 9 );
}

TEST( TruncatingTest, ConvertCharDigitChar ) {
	EXPECT_EQ( convert_char_digit( '0' ), 0 );
	EXPECT_EQ( convert_char_digit( '1' ), 1 );
	EXPECT_EQ( convert_char_digit( '2' ), 2 );
	EXPECT_EQ( convert_char_digit( '3' ), 3 );
	EXPECT_EQ( convert_char_digit( '4' ), 4 );
	EXPECT_EQ( convert_char_digit( '5' ), 5 );
	EXPECT_EQ( convert_char_digit( '6' ), 6 );
	EXPECT_EQ( convert_char_digit( '7' ), 7 );
	EXPECT_EQ( convert_char_digit( '8' ), 8 );
	EXPECT_EQ( convert_char_digit( '9' ), 9 );
}

TEST( TruncatingTest, FindBasePower ) {
	EXPECT_EQ( find_base_power( 0_mpz ), 1_mpz ) << "Special case";
	EXPECT_EQ( find_base_power( 654321_mpz ), 100000_mpz );
	EXPECT_EQ( find_base_power( 87654321_mpz ), 10000000_mpz );
	EXPECT_EQ( find_base_power( 987654321_mpz ), 100000000_mpz );

	constexpr int iterations = 500;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> all_digits( 0, 9 );
	std::uniform_int_distribution<int> no_zero( 1, 9 );

	for ( int i = 0; i < iterations; ++i ) {
		generator.seed( i );
		mpz_class num( no_zero( generator ) );
		mpz_class base( 1 );

		for ( int j = 0; j < iterations; ++j ) {
			num = append_right( num, all_digits( generator ) );
			base *= 10;

			EXPECT_EQ( find_base_power( num ), base ) << "Number is " << num;
		}
	}
}

TEST( TruncatingTest, ConvertCharDigitInvalid ) {
	EXPECT_THROW( convert_char_digit( -1 ), std::invalid_argument );
	EXPECT_THROW( convert_char_digit( 10 ), std::invalid_argument );
	EXPECT_THROW( convert_char_digit( '/' ), std::invalid_argument );
	EXPECT_THROW( convert_char_digit( ':' ), std::invalid_argument );
}

