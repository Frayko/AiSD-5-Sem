#pragma once
#include <iostream>
#include "listErrors.h"

using namespace std;

template <class Key = int, class Data = int>
class Tree {
private:
	Key key;
	Data obj;
	Tree* l, r;

public:
	Tree();
	bool push(Data _obj, Key _key);
	bool pop(Key _key);
	Data get_obj(Key _key);
	bool set_obj(Data _obj, Key _key);
	bool isEmpty();
	void clear();
	int get_size();
	void print();
	int get_serial_number(Key _key);

	class Iterator {

	};

	class rIterator {

	};

	friend class Iterator;
	friend class rIterator;

	Iterator begin();
	rIterator rbegin();

	Iterator end();
	rIterator rend();
};