//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "global_test_settings.hpp"

#include <mpirxx.h>

TEST( MPIRTest, uint64ToMpz ) {
	// A few random uints
	EXPECT_EQ( mpz_class( 9681666858668565181LLU ), 9681666858668565181_mpz );
	EXPECT_EQ( mpz_class( 4245223178035231249LLU ), 4245223178035231249_mpz );
	EXPECT_EQ( mpz_class( 15797971957385167003LLU ), 15797971957385167003_mpz );
	EXPECT_EQ( mpz_class( 5078330763103564715LLU ), 5078330763103564715_mpz );
	EXPECT_EQ( mpz_class( 10777124245617543848LLU ), 10777124245617543848_mpz );
}

TEST( MPIRTest, mpzToUint64 ) {
	// A few random uints
	EXPECT_EQ( (9681666858668565181_mpz).get_ui(), 9681666858668565181LLU );
	EXPECT_EQ( (4245223178035231249_mpz).get_ui(), 4245223178035231249LLU );
	EXPECT_EQ( (15797971957385167003_mpz).get_ui(), 15797971957385167003LLU );
	EXPECT_EQ( (5078330763103564715_mpz).get_ui(), 5078330763103564715LLU );
	EXPECT_EQ( (10777124245617543848_mpz).get_ui(), 10777124245617543848LLU );
}
