//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#ifndef SAFE_QUEUE_INC_CPP
#define SAFE_QUEUE_INC_CPP
// Classic include guards because "#pragma once" isn't working

#include "safe_queue.hpp"

template <typename T, typename container = std::deque<T>>
safe_queue<T, container>::timeout_error::timeout_error( const std::string& what_arg )
	: std::runtime_error( what_arg ) {};

template <typename T, typename container = std::deque<T>>
safe_queue<T, container>::timeout_error::timeout_error( const char* what_arg )
	: std::runtime_error( what_arg ) {};

template <typename T, typename container = std::deque<T>>
void safe_queue<T, container>::push( const T & value ) {
	{
		std::unique_lock<std::mutex> lock( mutex );
		queue.push_back( value );
	}

	condition.notify_one();
}

template <typename T, typename container = std::deque<T>>
void safe_queue<T, container>::push( T && value ) {
	{
		std::unique_lock<std::mutex> lock( mutex );
		queue.push_back( std::move( value ) );
	}

	condition.notify_one();
}

template <typename T, typename container = std::deque<T>>
T safe_queue<T, container>::pop() {
	std::unique_lock<std::mutex> lock( mutex );

	condition.wait( lock, [&queue] { return !queue.empty(); } );

	T out( queue.front() );
	queue.pop_front();

	return out;
}

template <typename T, typename container = std::deque<T>>
T safe_queue<T, container>::pop( std::chrono::milliseconds timeout ) throw(timeout_error) {
	std::unique_lock<std::mutex> lock( mutex );

	if ( !condition.wait_for( lock, dur, [&queue] { return !queue.empty(); } ) ) {
		throw timeout_error("No new element was added during the specified timeout of " + timeout);
	}

	T out( queue.front() );
	queue.pop_front();

	return out;
}

template <typename T, typename container = std::deque<T>>
bool safe_queue<T, container>::tryPop( T& value, std::chrono::milliseconds timeout ) {
	std::unique_lock<std::mutex> lock( mutex );

	if ( !condition.wait_for( lock, dur, [&queue] { return !queue.empty(); } ) ) {
		return false;
	}

	value = queue.front();
	queue.pop_front();

	return true;
}

template <typename T, typename container = std::deque<T>>
size_t safe_queue<T, container>::size() const {
	std::unique_lock<std::mutex> lock( mutex );

	return queue.size();
}

#endif // #ifndef SAFE_QUEUE_INC_CPP
