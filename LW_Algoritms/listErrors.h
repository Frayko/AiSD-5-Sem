#pragma once
#include <iostream>
using namespace std;

class ArrayError {
public:
	ArrayError() {}

	virtual void ErrMsg() const {
		cerr << ">>> ������ ������ ������������� �������!\n";
	}
};

class ArrayRangedErr : public ArrayError {
public:
	ArrayRangedErr() {}
	void ErrMsg() const {
		cerr << ">>> ������ ��� ������ � ��������" << endl;
	}
};

class IteratorError {
public:
	IteratorError() {}

	virtual void ErrMsg() const {
		cerr << ">>> ������ ������ ���������!\n";
	}
};

class IteratorInactive : public IteratorError {
public:
	IteratorInactive() {}
	void ErrMsg() const {
		cerr << ">>> ������ ��� ������ � ����������" << endl;
	}
};