//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#pragma once

#include "global_settings.hpp"

#include <stdexcept>

#include <mpirxx.h>

// Trucation
mpz_class truncate_left( const mpz_class& in );

mpz_class truncate_right( const mpz_class& in );

// Appendation
mpz_class append_left( const mpz_class& in, char digit ) throw(std::invalid_argument);
mpz_class append_left( const mpz_class& in, int16_t digit ) throw(std::invalid_argument);
mpz_class append_left( const mpz_class& in, int32_t digit ) throw(std::invalid_argument);
mpz_class append_left( const mpz_class& in, int64_t digit ) throw(std::invalid_argument);

mpz_class append_right( const mpz_class& in, char digit ) throw(std::invalid_argument);
mpz_class append_right( const mpz_class& in, int16_t digit ) throw(std::invalid_argument);
mpz_class append_right( const mpz_class& in, int32_t digit ) throw(std::invalid_argument);
mpz_class append_right( const mpz_class& in, int64_t digit ) throw(std::invalid_argument);

// Helper methods
mpz_class find_base_power( const mpz_class& in );

int64_t convert_char_digit( char digit ) throw(std::invalid_argument);
