//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#pragma once

#include "global_settings.hpp"

#include <condition_variable>
#include <deque>
#include <mutex>
#include <stdexcept>

class timeout_error : public std::runtime_error {
public:
	timeout_error( const std::string& what_arg );
	timeout_error( const char* what_arg );
};

template <typename T, typename container = std::deque<T>>
class safe_queue {
private:
	std::mutex              mutex;
	std::condition_variable condition;
	container               queue;
public:
	void push( const T& value );
	void push( T&& value );
	T pop();
	T pop( std::chrono::milliseconds timeout ) throw(timeout_error);
	bool tryPop( T& value, std::chrono::milliseconds timeout );
	size_t size() const;
	bool empty() const;
};

// Implementation

timeout_error::timeout_error( const std::string& what_arg )
	: std::runtime_error( what_arg ) {};

timeout_error::timeout_error( const char* what_arg )
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

	condition.wait( lock, [this] { return !this->queue.empty(); } );

	T out( queue.front() );
	queue.pop_front();

	return out;
}

template <typename T, typename container = std::deque<T>>
T safe_queue<T, container>::pop( std::chrono::milliseconds timeout ) throw(timeout_error) {
	std::unique_lock<std::mutex> lock( mutex );

	if ( !condition.wait_for( lock, timeout, [this] { return !this->queue.empty(); } ) ) {
		using namespace std::literals::string_literals;

		throw timeout_error( "No new element was added during the specified timeout of "s + std::to_string( timeout.count() ) + "ms"s );
	}

	T out( queue.front() );
	queue.pop_front();

	return out;
}

template <typename T, typename container = std::deque<T>>
bool safe_queue<T, container>::tryPop( T& value, std::chrono::milliseconds timeout ) {
	std::unique_lock<std::mutex> lock( mutex );

	if ( !condition.wait_for( lock, timeout, [this] { return !this->queue.empty(); } ) )
		return false;

	value = queue.front();
	queue.pop_front();

	return true;
}

template <typename T, typename container = std::deque<T>>
size_t safe_queue<T, container>::size() const {
	std::unique_lock<std::mutex> lock( mutex );

	return queue.size();
}

template<typename T, typename container>
bool safe_queue<T, container>::empty() const {
	std::unique_lock<std::mutex> lock( mutex );

	return queue.empty();
}
