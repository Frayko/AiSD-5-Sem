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
	DinArray();
	DinArray(int _n0 = 10);
	DinArray(DinArray<T>& DA);
	~DinArray();
	void push(T obj);
	void push(T obj, int index);
	void pop();
	void pop(int index);
	void print();
	int check_size();
	void capacity_increase();
	void clear();
	bool isArrayEmpty();
	bool check_obj(T obj);
	T get_obj(int index);
	void edit_obj(T obj, int index);
	int get_index_obj(T obj);
};

template <class T>
DinArray<T>::DinArray() : n0(10), size(0) {
	capacity = n0;
	Array = new T[capacity];
}

template <class T>
DinArray<T>::DinArray(int _n0) : n0(_n0), size(0) {
	n0 = _n0;
	size = 0;
	capacity = n0;
	Array = new T[capacity];
}

template <class T>
DinArray<T>::DinArray(DinArray<T>& DA) {
	n0 = DA.n0;
	size = DA.size;
	capacity = DA.capacity;
	Array = new T[capacity];
	for (int i = 0; DA.size; i++)
		Array[i] = DA.Array[i];
}

template <class T>
DinArray<T>::~DinArray() {
	if (Array)
		delete[] Array;
	Array = nullptr;
	size = 0;
	capacity = 0;
}

template <class T>
int DinArray<T>::check_size() {
	if (size == capacity)
		capacity_increase();
	return size;
}

template <class T>
void DinArray<T>::capacity_increase() {
	T* buf = new T[capacity];
	buf = Array;
	delete[] Array;
	capacity = capacity + n0;
	Array = new T[capacity];
	for (int i = 0; i < size; i++)
		Array[i] = buf[i];
}

template <class T>
void DinArray<T>::push(T obj) {
	check_size();
	Array[size++] = obj;
}

template <class T>
void DinArray<T>::push(T obj, int index) {
	if (index > size || index < 0)
		return;
	check_size();
	for (int i = size; i != index; i--)
		Array[i] = Array[i - 1];
	Array[index] = obj;
	size++;
}

template <class T>
void DinArray<T>::pop() {
	if (size == 0)
		return;
	Array[size--] = NULL;
}

template <class T>
void DinArray<T>::pop(int index) {
	if (size == 0 || index >= size || index < 0)
		return;
	for (int i = index; i < size; i++)
		Array[i] = Array[i + 1];
	Array[size--] = NULL;
}

template <class T>
void DinArray<T>::clear() {
	if (Array)
		delete[] Array;
	Array = new int[capacity];
}

template <class T>
bool DinArray<T>::isArrayEmpty() {
	if (Array)
		return true;
	return false;
}

template <class T>
bool DinArray<T>::check_obj(T obj) {
	for (int i = 0; i < size; i++)
		if (Array[i] == obj)
			return true;
	return false;
}

template <class T>
T DinArray<T>::get_obj(int index) {
	if (index >= size || index < 0)
		return NULL;
	return Array[index];
}

template <class T>
void DinArray<T>::edit_obj(T obj, int index) {
	if (index >= size || index < 0)
		return;
	Array[index] = obj;
}

template <class T>
int DinArray<T>::get_index_obj(T obj) {
	for (int i = 0; i < size; i++)
		if (Array[i] == obj)
			return i;
	return -1;
}

template <class T>
void DinArray<T>::print() {
	for (int i = 0; i < size; i++)
		cout << Array[i] << endl;
}