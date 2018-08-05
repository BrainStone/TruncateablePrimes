//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#pragma once

#include "global_settings.hpp"

#include <list>
#include <mutex>
#include <set>

#include <mpirxx.h>

template<typename T = mpz_class>
class prime_list {
private:
	std::mutex                   mutex;
	std::set<T, std::greater<T>> list;

public:
	typename typedef std::set<T, std::greater<T>>::const_iterator iterator;
	typename typedef std::set<T, std::greater<T>>::const_reverse_iterator reverse_iterator;

	std::pair<iterator, bool> insert( const T& value );
	std::pair<iterator, bool> insert( T&& value );

	iterator begin() const;
	iterator end() const;

	reverse_iterator rbegin() const;
	reverse_iterator rend() const;

	bool empty() const noexcept;
	size_type size() const noexcept;
};

// Implementation

template<typename T>
std::pair<iterator, bool> prime_list<T>::insert( const T& value ) {
	std::unique_lock<std::mutex> lock( mutex );

	return list.insert( val );
}

template<typename T>
std::pair<iterator, bool> prime_list<T>::insert( T&& value ) {
	std::unique_lock<std::mutex> lock( mutex );

	return list.insert( val );
}

template<typename T>
iterator prime_list<T>::begin() const {
	return list.cbegin();
}

template<typename T>
iterator prime_list<T>::end() const {
	return list.cend();
}

template<typename T>
reverse_iterator prime_list<T>::rbegin() const {
	return list.crbegin();
}

template<typename T>
reverse_iterator prime_list<T>::rend() const {
	return list.crend();
}

template<typename T>
bool prime_list<T>::empty() const noexcept {
	return list.empty();
}

template<typename T>
size_type prime_list<T>::size() const noexcept {
	return list.size();
}
