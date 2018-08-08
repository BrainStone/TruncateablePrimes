//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#pragma once

// DOCME: Add documentation

#include "global_settings.hpp"

#include <stdexcept>
#include <string>

#include <mpirxx.h>

// Trucation
mpz_class truncate_left( const mpz_class& in );

mpz_class truncate_right( const mpz_class& in );

// Appendation
template<class T>
mpz_class append_left( const mpz_class& in, T digit ) throw(std::invalid_argument) {
	return append_left( in, static_cast<int16_t>(digit) );
}
template<> mpz_class append_left( const mpz_class& in, char digit ) throw(std::invalid_argument);
template<> mpz_class append_left( const mpz_class& in, int16_t digit ) throw(std::invalid_argument);

template<class T>
mpz_class append_right( const mpz_class& in, T digit ) throw(std::invalid_argument) {
	return append_right( in, static_cast<int16_t>(digit) );
}
template<> mpz_class append_right( const mpz_class& in, char digit ) throw(std::invalid_argument);
template<> mpz_class append_right( const mpz_class& in, int16_t digit ) throw(std::invalid_argument);

// Helper methods
mpz_class find_base_power( const mpz_class& in );

int64_t convert_char_digit( char digit ) throw(std::invalid_argument);
