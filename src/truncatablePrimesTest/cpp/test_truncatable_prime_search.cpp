//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "global_test_settings.hpp"

#include <thread>

#include "truncatable_prime_search.hpp"

TEST( TruncatablePrimeSearch, LeftTruncatable ) {
	prime_list primes;
	candidate_queue queue;

	left_truncatble_prime_worker worker( primes, queue );

	// TODO: Test an example
}

TEST( TruncatablePrimeSearch, RightTruncatable ) {
	prime_list primes;
	candidate_queue queue;

	right_truncatble_prime_worker worker( primes, queue );

	// TODO: Test an example
}
