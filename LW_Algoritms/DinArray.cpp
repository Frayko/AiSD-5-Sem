#include "DinArray.h"

//template <typename T>
//DinArray<T>::DinArray() : n0(10), size(0) {
//	capacity = n0;
//	Array = new T[capacity];
//}

template <typename T>
DinArray<T>::DinArray(int _n0) : n0(_n0), size(0) {
	n0 = _n0;
	size = 0;
	capacity = n0;
	Array = new T[capacity];
}

template <typename T>
DinArray<T>::DinArray(DinArray<T>& DA) {
	n0 = DA.n0;
	size = DA.size;
	capacity = DA.capacity;
	Array = new T[capacity];
	for (int i = 0; DA.size; i++)
		Array[i] = DA.Array[i];
}

template <typename T>
DinArray<T>::~DinArray() {
	if (Array)
		delete[] Array;
	Array = nullptr;
	size = 0;
	capacity = 0;
}

template <typename T>
int DinArray<T>::check_size() {
	if (size == capacity)
		capacity_increase();
	return size;
}

template <typename T>
void DinArray<T>::capacity_increase() {
	T* buf = new T[capacity];
	buf = Array;
	delete[] Array;
	capacity = capacity + n0;
	Array = new T[capacity];
	for (int i = 0; i < size; i++)
		Array[i] = buf[i];
}

template <typename T>
void DinArray<T>::add(T obj) {
	check_size();
	Array[size++] = obj;
}

template <typename T>
void DinArray<T>::add(T obj, int index) {
	if (index > size || index < 0)
		return;
	check_size();
	for (int i = size; i != index; i--)
		Array[i] = Array[i - 1];
	Array[index] = obj;
	size++;
}

template <typename T>
void DinArray<T>::pop() {
	if (size == 0)
		return;
	Array[size--] = NULL;
}

template <typename T>
void DinArray<T>::pop(int index) {
	if (size == 0 || index >= size || index < 0)
		return;
	for (int i = index; i < size; i++)
		Array[i] = Array[i + 1];
	Array[size--] = NULL;
}

template <typename T>
void DinArray<T>::clear() {
	if (Array)
		delete[] Array;
	Array = new int[capacity];
}

template <typename T>
bool DinArray<T>::isArrayEmpty() {
	if (Array)
		return true;
	return false;
}

template <typename T>
bool DinArray<T>::check_obj(T obj) {
	for (int i = 0; i < size; i++)
		if (Array[i] == obj)
			return true;
	return false;
}

template <typename T>
T DinArray<T>::get_obj(int index) {
	if (index >= size || index < 0)
		return NULL;
	return Array[index];
}

template <typename T>
void DinArray<T>::edit_obj(T obj, int index) {
	if (index >= size || index < 0)
		return;
	Array[index] = obj;
}

template <typename T>
int DinArray<T>::get_index_obj(T obj) {
	for (int i = 0; i < size; i++)
		if (Array[i] == obj)
			return i;
	return -1;
}

template <typename T>
void DinArray<T>::print() {
	for (int i = 0; i < size; i++)
		cout << Array[i] << endl;
}