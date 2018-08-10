//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "global_test_settings.hpp"

#include <thread>

#include "truncatable_prime_search.hpp"

using namespace std::literals::chrono_literals;

TEST( TruncatablePrimeSearch, Init ) {
	prime_list primes;
	candidate_queue queue;
	left_truncatble_prime_worker worker( primes, queue );

	EXPECT_NO_THROW( worker.init_candidates() );
	EXPECT_EQ( worker.candidates_in_queue(), 4 );
}

TEST( TruncatablePrimeSearch, InitExcept ) {
	prime_list primes;
	candidate_queue queue;
	left_truncatble_prime_worker worker( primes, queue );

	queue.push( 0_mpz );

	EXPECT_THROW( worker.init_candidates(), std::invalid_argument );
}

TEST( TruncatablePrimeSearch, LeftTruncatable ) {
	prime_list primes;
	candidate_queue queue;
	left_truncatble_prime_worker worker( primes, queue );

	queue.push( 318443_mpz );
	worker.set_timeout( 0ms );

	worker();

	prime_list::iterator it( primes.begin() );

	EXPECT_EQ( primes.size(), 5 );
	EXPECT_EQ( *it++, 318443_mpz );
	EXPECT_EQ( *it++, 9318443_mpz );
	EXPECT_EQ( *it++, 59318443_mpz );
	EXPECT_EQ( *it++, 89318443_mpz );
	EXPECT_EQ( *it++, 489318443_mpz );
	EXPECT_EQ( it, primes.end() );
}

TEST( TruncatablePrimeSearch, RightTruncatable ) {
	prime_list primes;
	candidate_queue queue;
	right_truncatble_prime_worker worker( primes, queue );

	queue.push( 739391_mpz );
	worker.set_timeout( 0ms );

	worker();

	prime_list::iterator it( primes.begin() );

	EXPECT_EQ( primes.size(), 3 );
	EXPECT_EQ( *it++, 739391_mpz );
	EXPECT_EQ( *it++, 7393913_mpz );
	EXPECT_EQ( *it++, 73939133_mpz );
	EXPECT_EQ( it, primes.end() );
}
