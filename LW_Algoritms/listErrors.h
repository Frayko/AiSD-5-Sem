#pragma once
#include <iostream>
using namespace std;

class ArrayError {
public:
	ArrayError() {}

	virtual void ErrMsg() const {
		cerr << ">>> Ошибка работы динамического массива!\n";
	}
};

class ArrayRangedErr : public ArrayError {
public:
	ArrayRangedErr() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка при работе с индексом" << endl;
	}
};

class IteratorError {
public:
	IteratorError() {}

	virtual void ErrMsg() const {
		cerr << ">>> Ошибка работы итератора!\n";
	}
};

class IteratorInactive : public IteratorError {
public:
	IteratorInactive() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка при работе с итератором" << endl;
	}
};