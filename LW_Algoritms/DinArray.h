#pragma once
#include <iostream>

using namespace std;

template <class T>
class DinArray {
private:
	T* Array;
	int capacity;
	int size;
	int n0;

public:
	DinArray(int _n0);
	DinArray(DinArray<T>& DA);
	~DinArray();
	void add(T obj);
	void add(T obj, int index);
	void pop();
	void pop(int index);
	int check_size();
	void capacity_increase();
	void clear();
	bool isArrayEmpty();
	bool check_obj(T obj);
	T find_obj(int index);
	void edit_obf(T obj, int index);
	void get_index_obj(T obj);
};