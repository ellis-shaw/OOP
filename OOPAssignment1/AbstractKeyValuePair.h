#pragma once

template <typename K, typename V>
struct AbstractKeyValuePair {
	K key;
	V value;
};

template <typename K, typename V>
void
