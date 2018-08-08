//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#pragma once

#include "global_settings.hpp"

#include <mpirxx.h>
#include <primesieve.hpp>

/*!
 * \brief Checks if the input is a prime number
 *
 * This method uses the prime sieving method to determine whether the input number is prime or not.
 *
 * \param number the number to be checked for primality
 * \return <code>true</code> if number is prime, <code>false</code> if not.
 */
bool is_prime( const mpz_class& number );
