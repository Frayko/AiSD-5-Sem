#pragma once
#include <iostream>
#include "listErrors.h"

using namespace std;

template <class T>
class DinArray {
private:
	T* Array;
	int capacity;
	int size;
	int n0;
	int match_count;
	int push_by_index_count;
	int pop_by_index_count;

public:
	DinArray();
	DinArray(int _n0);
	DinArray(DinArray<T>& DA);
	~DinArray();
	void push(T obj);
	void push(T obj, int index);
	void pop();
	void pop(int index);
	void print();
	void print_stat();
	int check_size();
	void capacity_increase();
	void clear();
	bool isEmpty();
	bool check_obj(T obj);
	T get_obj(int index);
	void edit_obj(T obj, int index);
	int get_index_obj(T obj);

	//class Iterator {
	//private:
	//	T* obj;
	//public:
	//	Iterator(DinArray<T>& arr) {
	//		//obj = 
	//	}
	//	T operator*() {
	//		return *obj;
	//	}
	//	T& begin() {
	//		return getArray();
	//	}
	//	T& end() {
	//		return getArray() + check_size();
	//	}
	//	Iterator<T>& operator++() {
	//		if (cur > check_size() || cur < 0)
	//			throw IteratorRangedErr(check_size(), cur);
	//		++obj;
	//		return *this;
	//	}
	//	Iterator<T>& operator--() {
	//		if (cur > check_size() || cur < 0)
	//			throw IteratorRangedErr(check_size(), cur);
	//		--obj;
	//		return *this;
	//	}
	//	bool operator==(Iterator<T>& _obj) {
	//		return (*obj == *_obj);
	//	}
	//	bool operator!=(Iterator<T>& _obj) {
	//		return (*obj != *_obj);
	//	}
	//};

	/*class rIterator {
	private:
		DinArray<T>* obj;

		int cur;
	public:
		rIterator(DinArray<T>& arr) {
			obj = arr.getArray + check_size() - 1;
			cur = 0;
		}
		T operator*() {
			return *obj;
		}
		T& rbegin() {
			return getArray() + check_size() - 1;
		}
		T& rend() {
			return getArray() - 1;
		}
		rIterator<T>& operator++() {
			if (cur > check_size() || cur < 0)
				throw IteratorRangedErr(check_size(), cur);
			--obj;
			--cur;
			return *this;
		}
		rIterator<T>& operator--() {
			if (cur > check_size() || cur < 0)
				throw IteratorRangedErr(check_size(), cur);
			++obj;
			++cur;
			return *this;
		}
		bool operator==(rIterator<T>& _obj) {
			return (*obj == *_obj);
		}
		bool operator!=(rIterator<T>& _obj) {
			return (*obj != *_obj);
		}
	};*/

	//friend class Iterator;
	//friend class rIterator;

	//Iterator begin();
	//Iterator end();

	//rIterator rbegin();
	//rIterator rend();
};

template <class T>
DinArray<T>::DinArray() : n0(10), size(0), match_count(0), push_by_index_count(0), pop_by_index_count(0) {
	capacity = n0;
	Array = new T[capacity];
}

template <class T>
DinArray<T>::DinArray(int _n0) : n0(_n0), size(0), match_count(0), push_by_index_count(0), pop_by_index_count(0) {
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
	match_count = DA.match_count;
	push_by_index_count = DA.push_by_index_count;
	pop_by_index_count = DA.pop_by_index_count;
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
	match_count = 0;
	push_by_index_count = 0;
	pop_by_index_count = 0;
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
		throw ArrayRangedErr(size, index);

	check_size();
	for (int i = size; i != index; i--)
		Array[i] = Array[i - 1];
	Array[index] = obj;
	size++;
	push_by_index_count++;
}

template <class T>
void DinArray<T>::pop() {
	if (size == 0)
		throw ArrayDelErr();

	Array[size--] = NULL;
}

template <class T>
void DinArray<T>::pop(int index) {
	if (size == 0)
		throw ArrayDelErr();
	if (index >= size || index < 0)
		throw ArrayRangedErr(size - 1, index);

	for (int i = index; i < size; i++)
		Array[i] = Array[i + 1];
	Array[size--] = NULL;
	pop_by_index_count++;
}

template <class T>
void DinArray<T>::clear() {
	if (Array)
		delete[] Array;
	Array = new int[capacity];
}

template <class T>
bool DinArray<T>::isEmpty() {
	if (size == 0)
		return true;
	return false;
}

template <class T>
bool DinArray<T>::check_obj(T obj) {
	for (int i = 0; i < size; i++)
		if (Array[i] == obj) {
			match_count++;
			return true;
		}
	return false;
}

template <class T>
T DinArray<T>::get_obj(int index) {
	if (index >= size || index < 0)
		throw ArrayRangedErr(size - 1, index);
	return Array[index];
}

template <class T>
void DinArray<T>::edit_obj(T obj, int index) {
	if (index >= size || index < 0)
		throw ArrayRangedErr(size - 1, index);
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
	cout << endl << "Список элементов:" << endl;
	for (int i = 0; i < size; i++)
		cout << Array[i] << endl;
}

template <class T>
void DinArray<T>::print_stat() {
	cout << endl << "Статистика:" << endl;
	cout << "Количество просмотренных элементов: " << match_count << endl;
	cout << "Количество добавленных элементов по индексу: " << push_by_index_count << endl;
	cout << "Количество удалённых элементов по индексу: " << pop_by_index_count << endl;
}

////----------------------------------Итераторы-------------------------------------------\\\\

//template <class T>
//class Iterator {
//private:
//	T* obj;
//	Iterator();
//
//public:
//	Iterator(DinArray<T>& arr) {
//		obj = arr.begin();
//	}
//
//	T operator*() {
//		return *this->obj;
//	}
//
//	Iterator<T>& operator++() {
//		++obj;
//		return *this;
//	}
//
//	Iterator<T>& operator--() {
//		--obj;
//		return *this;
//	}
//
//	bool operator==(Iterator& _obj) {
//		return *obj == *_obj;
//	}
//
//	bool operator!=(Iterator& _obj) {
//		return *obj != *_obj;
//	}
//};
//
//template <class T>
//class rIterator {
//private:
//	T* obj;
//	rIterator();
//
//public:
//	rIterator(DinArray<T>& arr) {
//		obj = arr.rbegin();
//	}
//
//	T operator*() {
//		return *this->obj;
//	}
//
//	rIterator<T>& operator++() {
//		--obj;
//		return *this;
//	}
//
//	rIterator<T>& operator--() {
//		++obj;
//		return *this;
//	}
//
//	bool operator==(rIterator& _obj) {
//		return *obj == *_obj;
//	}
//
//	bool operator!=(rIterator& _obj) {
//		return *obj != *_obj;
//	}
//};