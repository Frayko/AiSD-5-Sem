#pragma once
#include <iostream>
#include "listErrors.h"

using namespace std;

template <class Data = int>
class DinArray {
private:
	Data* Array;						//динамический массив
	int n0;								//базовая мощность
	int capacity;						//мощность
	int size;							//текущий размер
	int match_count;					//счётчик количества совпадений при использовании поиска по объекту
	int push_by_index_count;			//счётчик количества добавлений элемента с использованием индекса
	int pop_by_index_count;				//счётчик количества удалений элемента с использованием индекса

public:
	DinArray();
	DinArray(int _n0);
	DinArray(DinArray<Data>& DA);
	~DinArray();
	void push(Data obj);
	bool push(Data obj, int index);
	void pop();
	bool pop(int index);
	void print();
	void print_stat();
	int get_size();
	void capacity_increase();
	void clear();
	bool isEmpty();
	bool check_obj(Data obj);
	Data get_obj(int index);
	bool edit_obj(Data obj, int index);
	int get_index_obj(Data obj);
	Data* get_Array();

	class Iterator {
	private:
		DinArray<Data>* mass;
		Data* obj;
		int cur;
	public:
		Iterator(DinArray<Data>* _mass, int _cur);
		Data* operator*();
		Iterator& operator++();
		Iterator& operator--();

		int get_cur() {
			return cur;
		}
		Data get_data();
		bool operator==(Iterator other) {
			return obj == other.obj;
		}
		bool operator!=(Iterator other) {
			return obj != other.obj;
		}
		bool operator==(Iterator& other);
		bool operator!=(Iterator& other);
	};

	class rIterator {
	private:
		DinArray<Data>* mass;
		Data* obj;
		int cur;
	public:
		rIterator(DinArray<Data>* _mass, int _cur);
		Data* operator*();
		rIterator& operator++();
		rIterator& operator--();

		int get_cur() {
			return cur;
		}
		Data get_data();
		bool operator==(rIterator other) {
			return obj == other.obj;
		}
		bool operator!=(rIterator other) {
			return obj != other.obj;
		}
		bool operator==(rIterator& other);
		bool operator!=(rIterator& other);
	};

	friend class Iterator;
	friend class rIterator;

	Iterator begin();
	Iterator end();

	rIterator rbegin();
	rIterator rend();
};

template <class Data>
DinArray<Data>::DinArray() : n0(10), size(0), match_count(0), push_by_index_count(0), pop_by_index_count(0) {
	capacity = n0;
	Array = new Data[capacity];
}

template <class Data>
DinArray<Data>::DinArray(int _n0) : n0(_n0), size(0), match_count(0), push_by_index_count(0), pop_by_index_count(0) {
	n0 = _n0;
	size = 0;
	capacity = n0;
	Array = new Data[capacity];
}

template <class Data>
DinArray<Data>::DinArray(DinArray<Data>& DA) {
	n0 = DA.n0;
	size = DA.size;
	capacity = DA.capacity;
	match_count = DA.match_count;
	push_by_index_count = DA.push_by_index_count;
	pop_by_index_count = DA.pop_by_index_count;
	Array = new Data[capacity];
	for (int i = 0; DA.size; i++)
		Array[i] = DA.Array[i];
}

template <class Data>
DinArray<Data>::~DinArray() {
	if (Array)
		delete[] Array;
	Array = nullptr;
	size = 0;
	capacity = 0;
	match_count = 0;
	push_by_index_count = 0;
	pop_by_index_count = 0;
}

template <class Data>
int DinArray<Data>::get_size() {
	return size;
}

template <class Data>
void DinArray<Data>::capacity_increase() {
	Data* buf = new Data[capacity];
	buf = Array;
	delete[] Array;
	capacity = capacity + n0;
	Array = new Data[capacity];
	for (int i = 0; i < size; i++)
		Array[i] = buf[i];
}

template <class Data>
void DinArray<Data>::push(Data obj) {
	if (size >= capacity)
		capacity_increase();

	Array[size++] = obj;
}

template <class Data>
bool DinArray<Data>::push(Data obj, int index) {
	try {
		if (index > size || index < 0)
			throw ArrayRangedErr(size, index);
	}
	catch (ArrayRangedErr& err) {
		err.ErrMsg();
		system("pause");
		return false;
	}
	catch (...) {

	}

	if (size >= capacity)
		capacity_increase();

	for (int i = size; i != index; i--)
		Array[i] = Array[i - 1];
	Array[index] = obj;
	size++;
	push_by_index_count++;
	return true;
}

template <class Data>
void DinArray<Data>::pop() {
	if (size == 0)
		throw ArrayDelErr();

	Array[size--] = NULL;
}

template <class Data>
bool DinArray<Data>::pop(int index) {
	try {
		if (size == 0)
			throw ArrayDelErr();
		if (index >= size || index < 0)
			throw ArrayRangedErr(size - 1, index);
	}
	catch (ArrayRangedErr& err) {
		err.ErrMsg();
		system("pause");
		return false;
	}
	catch (...) {

	}

	for (int i = index; i < size; i++)
		Array[i] = Array[i + 1];
	Array[size--] = NULL;
	pop_by_index_count++;
	return true;
}

template <class Data>
void DinArray<Data>::clear() {
	if (Array)
		delete[] Array;
	capacity = n0;
	Array = new int[capacity];
	size = 0;
}

template <class Data>
bool DinArray<Data>::isEmpty() {
	if (size == 0)
		return true;
	return false;
}

template <class Data>
bool DinArray<Data>::check_obj(Data obj) {
	for (int i = 0; i < size; i++)
		if (Array[i] == obj) {
			match_count++;
			return true;
		}
	return false;
}

template <class Data>
Data DinArray<Data>::get_obj(int index) {
	if (index >= size || index < 0)
		throw ArrayRangedErr(size - 1, index);

	return Array[index];
}

template <class Data>
bool DinArray<Data>::edit_obj(Data obj, int index) {
	try {
		if (index >= size || index < 0)
			throw ArrayRangedErr(size - 1, index);
	}
	catch (ArrayRangedErr& err) {
		err.ErrMsg();
		system("pause");
		return false;
	}
	catch (...) {}

	Array[index] = obj;
}

template <class Data>
int DinArray<Data>::get_index_obj(Data obj) {
	for (int i = 0; i < size; i++)
		if (Array[i] == obj)
			return i;
	return -1;
}

template <class Data>
void DinArray<Data>::print() {
	if(size > 0)
		for (int i = 0; i < size; i++)
			cout << Array[i] << ", ";
}

template <class Data>
void DinArray<Data>::print_stat() {
	cout << endl << "Статистика:" << endl;
	cout << "Количество просмотренных элементов: " << match_count << endl;
	cout << "Количество добавленных элементов по индексу: " << push_by_index_count << endl;
	cout << "Количество удалённых элементов по индексу: " << pop_by_index_count << endl;
}

template <class Data>
Data* DinArray<Data>::get_Array() {
	return Array;
}

template <class Data>
typename DinArray<Data>::Iterator DinArray<Data>::begin() {
	return Iterator(this, 0);
}

template <class Data>
typename DinArray<Data>::Iterator DinArray<Data>::end() {
	return Iterator(this, size);
}

template <class Data>
typename DinArray<Data>::rIterator DinArray<Data>::rbegin() {
	return rIterator(this, size - 1);
}

template <class Data>
typename DinArray<Data>::rIterator DinArray<Data>::rend() {
	return rIterator(this, -1);
}

////----------------------------------Итераторы-------------------------------------------\\\\

template <class Data>
DinArray<Data>::Iterator::Iterator(DinArray<Data>* _mass, int _cur) {
	mass = _mass;
	cur = _cur;

	if (cur >= mass->get_size())
		obj = nullptr;
	else
		obj = mass->get_Array() + cur;
}

template <class Data>
typename Data* DinArray<Data>::Iterator::operator*() {
	return obj;
}

template <class Data>
typename Data DinArray<Data>::Iterator::get_data() {
	if (obj == nullptr)
		throw IteratorInactive();
	return *obj;
}

template <class Data>
typename DinArray<Data>::Iterator& DinArray<Data>::Iterator::operator++() {
	if (obj == nullptr)
		throw IteratorInactive();

	++cur;
	if (cur >= mass->get_size()) {
		obj = nullptr;
		return *this;
	}

	++obj;
	return *this;
}

template <class Data>
typename DinArray<Data>::Iterator& DinArray<Data>::Iterator::operator--() {
	if (obj == nullptr)
		throw IteratorInactive();

	--cur;
	if (cur < 0) {
		obj = nullptr;
		return *this;
	}

	--obj;
	return *this;
}

template <class Data>
typename bool DinArray<Data>::Iterator::operator==(DinArray<Data>::Iterator& other) {
	return (obj == other.obj);
}

template <class Data>
typename bool DinArray<Data>::Iterator::operator!=(DinArray<Data>::Iterator& other) {
	return (obj != other.obj);
}



template <class Data>
DinArray<Data>::rIterator::rIterator(DinArray<Data>* _mass, int _cur) {
	mass = _mass;
	cur = _cur;

	if (cur <= -1)
		obj = nullptr;
	else
		obj = mass->get_Array() + cur;
}

template <class Data>
typename Data* DinArray<Data>::rIterator::operator*() {
	return obj;
}

template <class Data>
typename Data DinArray<Data>::rIterator::get_data() {
	if (obj == nullptr)
		throw IteratorInactive();
	return *obj;
}

template <class Data>
typename DinArray<Data>::rIterator& DinArray<Data>::rIterator::operator++() {
	if (obj == nullptr)
		throw IteratorInactive();

	--cur;
	if (cur < 0) {
		obj = nullptr;
		return *this;
	}

	--obj;
	return *this;
}

template <class Data>
typename DinArray<Data>::rIterator& DinArray<Data>::rIterator::operator--() {
	if (obj == nullptr)
		throw IteratorInactive();

	++cur;
	if (cur >= mass->get_size()) {
		obj = nullptr;
		return *this;
	}

	++obj;
	return *this;
}

template <class Data>
typename bool DinArray<Data>::rIterator::operator==(DinArray<Data>::rIterator& other) {
	return (obj == other.obj);
}

template <class Data>
typename bool DinArray<Data>::rIterator::operator!=(DinArray<Data>::rIterator& other) {
	return (obj != other.obj);
}