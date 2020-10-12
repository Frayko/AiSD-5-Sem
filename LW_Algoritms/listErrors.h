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

class ArrayDelErr : public ArrayError {
public:
	ArrayDelErr() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка удаления! Список пуст!\n";
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