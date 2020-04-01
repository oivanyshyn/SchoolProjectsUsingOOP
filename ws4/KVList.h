#pragma once
#include <iostream>
#include <string>
#include <iomanip>

template<typename K, typename V, int N>
class KVList {
	K     k[N];
	V     v[N];
	size_t count = 0; //C++14

public:
	KVList()
		: count(0) //C++98
	{
		count = 0; //C++98
	}

	size_t size() const
	{
		return count;
	}

	const K& key(int i) const {
		if (i < count)
			return k[i];
	}

	const V& value(int i) const {
		if (i < count)
			return v[i];
	}
	KVList& add(const K& kk, const V& vv) {
		if (count < N) {
			k[count] = kk;
			c[count] = vv;
			count++;
		}
		return *this;

	}
	int find(const K& kk) const {
		for (size_t i = 0; i < count; i++) {
			if (kk == k[i])
				return i;
		}
		return 0;
	}
	KVList& replace(int i, const K& kk, const V& vv) {

		if (i < count) {
			k[i] = kk;
			v[i] = vv;
		}
		return this*;
	}

};


