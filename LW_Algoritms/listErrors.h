#pragma once
#include <iostream>
using namespace std;

class ArrayError {
public:
	ArrayError() {}

	virtual void ErrMsg() const {
		cerr << ">>> Ошибка работы динамического массива!\n";
	}

	void Continue() const {
		cerr << ">>> Программа продолжает работать.\n>>> ";
	}
};

class ArrayRangedErr : public ArrayError {
public:
	ArrayRangedErr(int _count, int _actual) : count(_count), actual(_actual) {}
	void ErrMsg() const {
		cerr << ">>> Ошибка индекса: возможный индекс от 0 до " << count << ". Переданный индекс: " << actual << endl;
		Continue();
	}
private:
	int count, actual;
};

class ArrayDelErr : public ArrayError {
public:
	ArrayDelErr() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка удаления! Список пуст!\n";
		Continue();
	}
};

class IteratorError {
public:
	IteratorError() {}

	virtual void ErrMsg() const {
		cerr << ">>> Ошибка работы итератора!\n";
	}

	void Continue() const {
		cerr << ">>> Программа продолжает работать.\n >>> ";
	}
};

class IteratorRangedErr : public IteratorError {
public:
	IteratorRangedErr(int _count, int _actual) : count(_count), actual(_actual) {}
	void ErrMsg() const {
		cerr << ">>> Ошибка позиционирования: возможная позиция от 0 до " << count << ". Переданная позиция: " << actual << endl;
		Continue();
	}
private:
	int count;
	int actual;
};