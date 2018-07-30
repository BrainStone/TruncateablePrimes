//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#pragma once

#include <stdexcept>

#include <gmpxx.h>

mpz_class uint64_t_to_mpz_class( const uint64_t& in );
uint64_t mpz_class_to_uint64_t( const mpz_class& in ) throw(std::out_of_range);