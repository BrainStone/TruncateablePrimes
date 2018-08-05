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

template <typename T, typename container = std::deque<T>>
class safe_queue {
public:
	class timeout_error : public std::runtime_error {
	public:
		timeout_error( const std::string& what_arg );
		timeout_error( const char* what_arg );
	};

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
};

#include "safe_queue.inc.cpp"