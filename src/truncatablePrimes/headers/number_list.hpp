//
// Copyright (c) 2018 Yannick Schinko. All rights reserved.
// Licensed under the GPLv3 License. See LICENSE file in the project root for full license information.
//
#pragma once

// DOCME: Add documentation

#include "global_settings.hpp"

#include <mutex>
#include <set>

template<typename T>
class number_list {
private:
	typedef typename std::set<T, std::less<T>> list_type;

	std::mutex mutex;
	list_type  list;

public:
	typedef typename list_type::const_iterator iterator;
	typedef typename list_type::const_reverse_iterator reverse_iterator;

	std::pair<iterator, bool> insert( const T& value );
	std::pair<iterator, bool> insert( T&& value );

	iterator begin() const;
	iterator end() const;

	reverse_iterator rbegin() const;
	reverse_iterator rend() const;

	bool empty() const noexcept;
	size_t size() const noexcept;
};

// Implementation

template<typename T>
std::pair<typename number_list<T>::iterator, bool> number_list<T>::insert( const T& value ) {
	std::unique_lock<std::mutex> lock( mutex );

	return list.insert( value );
}

template<typename T>
std::pair<typename number_list<T>::iterator, bool> number_list<T>::insert( T&& value ) {
	std::unique_lock<std::mutex> lock( mutex );

	return list.insert( value );
}

template<typename T>
typename number_list<T>::iterator number_list<T>::begin() const {
	return list.cbegin();
}

template<typename T>
typename number_list<T>::iterator number_list<T>::end() const {
	return list.cend();
}

template<typename T>
typename number_list<T>::reverse_iterator number_list<T>::rbegin() const {
	return list.crbegin();
}

template<typename T>
typename number_list<T>::reverse_iterator number_list<T>::rend() const {
	return list.crend();
}

template<typename T>
bool number_list<T>::empty() const noexcept {
	return list.empty();
}

template<typename T>
size_t number_list<T>::size() const noexcept {
	return list.size();
}
