//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#pragma once

// DOCME: Add documentation
// TODO: Add Logging!

#include "global_settings.hpp"

#include <array>
#include <functional>
#include <stdexcept>

#include <mpirxx.h>

#include "number_list.hpp"
#include "primality.hpp"
#include "safe_queue.hpp"
#include "truncate.hpp"

typedef number_list<mpz_class> prime_list;
typedef safe_queue<mpz_class> candidate_queue;

template<size_t count>
class truncatble_prime_worker {
public:
	typedef uint16_t digit_int;
	typedef std::function<mpz_class( mpz_class, digit_int )> appender_func;

protected:
	appender_func appender;
	const std::array<digit_int, count> digits;
	prime_list& primes;
	candidate_queue& canditates;

public:
	truncatble_prime_worker( appender_func appender, const std::array<digit_int, count> digits, prime_list& primes, candidate_queue& canditates );

	void operator()();

	void init_candidates();

	bool finished();
	size_t candidates_in_queue();
};

class left_truncatble_prime_worker : public truncatble_prime_worker<9> {
public:
	inline left_truncatble_prime_worker( prime_list& primes, candidate_queue& canditates ) :
		truncatble_prime_worker( append_left<digit_int>, { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, primes, canditates ) {};
};

class right_truncatble_prime_worker : public truncatble_prime_worker<4> {
public:
	inline right_truncatble_prime_worker( prime_list& primes, candidate_queue& canditates ) :
		truncatble_prime_worker( append_right<digit_int>, { 1, 3, 7, 9 }, primes, canditates ) {};
};

// Implementation

template<size_t count>
truncatble_prime_worker<count>::truncatble_prime_worker( appender_func appender, const std::array<digit_int, count> digits, prime_list& primes, candidate_queue& canditates ) :
	appender( appender ),
	digits( digits ),
	primes( primes ),
	canditates( canditates ) {}

template<size_t count>
void truncatble_prime_worker<count>::operator()() {
	using std::chrono_literals;

	mpz_class candidate;

	while ( canditates.tryPop( candidate, 1000ms ) ) {
		if ( !is_prime( candidate ) )
			continue;

		primes.insert( canditates );

		for ( digit_int digit : digits )
			canditates.push( appender( candidate, digit ) );
	}
}

template<size_t count>
void truncatble_prime_worker<count>::init_candidates() {
	if ( !canditates.empty() )
		throw std::invalid_argument("Canidates list needs to be empty in order to be initialized!");

	canditates.push( 2_mpz );
	canditates.push( 3_mpz );
	canditates.push( 5_mpz );
	canditates.push( 7_mpz );
}

template<size_t count>
bool truncatble_prime_worker<count>::finished() {
	return !canditates.empty();
}

template<size_t count>
size_t truncatble_prime_worker<count>::candidates_in_queue() {
	return canditates.size();
}
