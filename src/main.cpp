//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include <iostream>

#include <gmpxx.h>

int main() {
	mpz_class test( 1 );

	std::cout << test << std::endl;

	for ( int i = 0; i < 100; ++i ) {
		test <<= 1;

		std::cout << test << std::endl;
	}
}
