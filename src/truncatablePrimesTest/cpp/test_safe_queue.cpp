//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#include "global_test_settings.hpp"

#include <thread>

#include "safe_queue.hpp"

using namespace std::literals::chrono_literals;

TEST( SafeQueueTest, Order ) {
	safe_queue<int> queue;

	queue.push( 1 );
	queue.push( 2 );
	queue.push( 3 );

	EXPECT_EQ( queue.pop(), 1 );
	EXPECT_EQ( queue.pop(), 2 );
	EXPECT_EQ( queue.pop(), 3 );
}

TEST( SafeQueueTest, TimeoutExcept ) {
	safe_queue<int> queue;

	EXPECT_THROW( queue.pop( 1ms ), timeout_error );
}

TEST( SafeQueueTest, TimeoutBool ) {
	safe_queue<int> queue;

	int val;

	EXPECT_FALSE( queue.tryPop( val, 1ms ) );
}

TEST( SafeQueueTest, Wakeup ) {
	safe_queue<int> queue;
	constexpr int count = 100;
	constexpr std::chrono::milliseconds delay(5ms);

	std::thread catcher( [&] {
		int val;

		for ( int i = 0; i < count; ++i ) {
			EXPECT_NO_THROW( val = queue.pop( delay * 2 ) );
			EXPECT_EQ( val, i );
		}
	} );

	for ( int i = 0; i < count; ++i ) {
		std::this_thread::sleep_for( delay );

		queue.push( i );
	}

	catcher.join();
}
