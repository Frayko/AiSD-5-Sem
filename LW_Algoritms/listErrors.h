#pragma once
#include <iostream>
using namespace std;

class TreeError {
public:
	TreeError() {}

	virtual void ErrMsg() const {
		cerr << ">>> Ошибка при работе с деревом!\n";
	}
};

class TreeIsEmpty : public TreeError {
public:
	TreeIsEmpty() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка при работе с пустым деревом!\n";
	}
};

class TreeFindErr : public TreeError {
public:
	TreeFindErr() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка поиска! Искомый узел не был найден!\n";
	}
};

class IteratorError {
public:
	IteratorError() {}

	virtual void ErrMsg() const {
		cerr << ">>> Ошибка в работе итератора!\n";
	}
};

class IteratorInactive : public IteratorError {
public:
	IteratorInactive() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка при работе с итератором! Итератор стоит в режиме 'неустановленный'" << endl;
	}
};