#include "DinArray.h"

template <class T>
DinArray<T>::DinArray(int _n0) {
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
void DinArray<T>::add(T obj) {
	check_size();
	Array[size++] = obj;
}

template <class T>
void DinArray<T>::add(T obj, int index) {
	check_size();
	for (int i = size; i != index; i--)
		Array[i] = Array[i - 1];
	Array[index] = obj;
	size++;
}

template <class T>
void DinArray<T>::pop() {
	Array[size--] = NULL;
}

template <class T>
void DinArray<T>::pop(int index) {
	for (int i = index; i < size; i++)
		Array[i] = Array[i + 1];
	Array[size--] = NULL;
}