//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "global_test_settings.hpp"

#include <random>
#include <thread>

#include "number_list.hpp"
#include "truncate.hpp"

std::uniform_int_distribution<int> all_digits( 0, 9 );

TEST( NumberListTest, Order ) {
	number_list<int> list;

	list.insert( 48 );
	list.insert( -425 );
	list.insert( 78 );
	list.insert( 4652 );

	number_list<int>::iterator it( list.begin() );

	EXPECT_EQ( *it++, -425 );
	EXPECT_EQ( *it++, 48 );
	EXPECT_EQ( *it++, 78 );
	EXPECT_EQ( *it++, 4652 );
	EXPECT_EQ( it, list.end() );

	number_list<int>::reverse_iterator rit( list.rbegin() );

	EXPECT_EQ( *rit++, 4652 );
	EXPECT_EQ( *rit++, 78 );
	EXPECT_EQ( *rit++, 48 );
	EXPECT_EQ( *rit++, -425 );
	EXPECT_EQ( rit, list.rend() );
}

constexpr int count = 1000;

void helper( number_list<mpz_class>& list, int digit ) {
	std::default_random_engine generator( digit );
	mpz_class num( digit );

	EXPECT_TRUE( list.insert( num ).second );

	for ( int i = 0; i < count; ++i ) {
		num = append_right( num, all_digits( generator ) );

		EXPECT_TRUE( list.insert( num ).second );
	}
}

TEST( NumberListTest, Concurrency ) {
	number_list<mpz_class> list;

	std::thread early_threads[7];

	for ( int i = 0; i < 7; ++i ) {
		early_threads[i] = std::thread( helper, std::ref( list ), i + 1 );
	}

	for ( std::thread& thread : early_threads ) {
		thread.join();
	}

	std::thread late_threads[2];

	for ( int i = 0; i < 2; ++i ) {
		late_threads[i] = std::thread( helper, std::ref( list ), i + 8 );
	}

	for ( std::thread& thread : late_threads ) {
		thread.join();
	}

	mpz_class zero( 0 );
	const mpz_class* last_val = &zero;

	for ( const mpz_class& val : list ) {
		EXPECT_GT( val, *last_val );

		last_val = &val;
	}

	EXPECT_EQ( list.size(), (count + 1) * 9 );
}
