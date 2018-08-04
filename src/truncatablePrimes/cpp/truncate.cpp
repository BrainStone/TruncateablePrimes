//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "truncate.hpp"

using namespace std::literals::string_literals;

mpz_class truncate_left( const mpz_class & in ) {
	return in % find_base_power( in );
}

mpz_class truncate_right( const mpz_class& in ) {
	return in / 10;
}

template<> mpz_class append_left( const mpz_class & in, char digit ) throw(std::invalid_argument) {
	return append_left( in, convert_char_digit( digit ) );
}

template<> mpz_class append_left( const mpz_class & in, int16_t digit ) throw(std::invalid_argument) {
	if ( (digit < 1) || (digit > 9) )
		throw std::invalid_argument( std::to_string( digit ) + " is not a valid digit"s );

	if ( in == 0_mpz )
		return mpz_class( digit );
	else
		return in + (find_base_power( in ) * (digit * 10));
}

template<> mpz_class append_right( const mpz_class & in, char digit ) throw(std::invalid_argument) {
	return append_right( in, convert_char_digit( digit ) );
}

template<> mpz_class append_right( const mpz_class & in, int16_t digit ) throw(std::invalid_argument) {
	if ( (digit < 0) || (digit > 9) )
		throw std::invalid_argument( std::to_string( digit ) + " is not a valid digit"s );

	return (in * 10) + digit;
}

mpz_class find_base_power( const mpz_class & in ) {
	if ( in == 0_mpz )
		return 1_mpz;

	mpz_class mod;
	mpz_ui_pow_ui( mod.get_mpz_t(), 10, mpz_sizeinbase( in.get_mpz_t(), 10 ) - 1 );

	if ( mod > abs( in ) )
		mod /= 10;

	return mod;
}

int64_t convert_char_digit( char digit ) throw(std::invalid_argument) {
	if ( (digit >= 0) && (digit <= 9) )
		return static_cast<int64_t>(digit);
	else if ( (digit >= '0') && (digit <= '9') )
		return static_cast<short>(digit - '0');
	else
		throw std::invalid_argument( "\""s + digit + "\" is not a valid digit"s );
}
