//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "gmp_util.hpp"

constexpr size_t uint64_size = sizeof( uint64_t );

mpz_class uint64_t_to_mpz_class( const uint64_t& in ) {
	mpz_class out;

	mpz_import( out.get_mpz_t(), 1, 1, uint64_size, 0, 0, &in );

	return out;
}

uint64_t mpz_class_to_uint64_t( const mpz_class& in ) throw(std::out_of_range) {
	if ( in < 0 )
		throw std::out_of_range( "The number cannot negative: " + in.get_str() );

	size_t word_count = 0;
	void* raw_result = mpz_export( nullptr, &word_count, 1, uint64_size, 0, 0, in.get_mpz_t() );
	auto delete_raw_result = finally([raw_result, word_count] {
		void( *freeFunction )(void*, size_t);
		mp_get_memory_functions( nullptr, nullptr, &freeFunction );
		freeFunction( raw_result, word_count * uint64_size );
	});

	if ( word_count > 1 ) {
		throw std::out_of_range( "The number cannot be stored in a uint64_t: " + in.get_str() );
	} else if ( word_count == 0 ) {
		return 0;
	} else {
		return *static_cast<uint64_t*>(raw_result);
	}
}
