#pragma once
#include <iostream>
using namespace std;

class TreeError {
public:
	TreeError() {}

	virtual void ErrMsg() const {
		cerr << ">>> ������ ��� ������ � �������!\n";
	}
};

class TreeIsEmpty : public TreeError {
public:
	TreeIsEmpty() {}
	void ErrMsg() const {
		cerr << ">>> ������ ��� ������ � ������ �������!\n";
	}
};

class TreeFindErr : public TreeError {
public:
	TreeFindErr() {}
	void ErrMsg() const {
		cerr << ">>> ������ ������! ������� ���� �� ��� ������!\n";
	}
};

class IteratorError {
public:
	IteratorError() {}

	virtual void ErrMsg() const {
		cerr << ">>> ������ � ������ ���������!\n";
	}
};

class IteratorInactive : public IteratorError {
public:
	IteratorInactive() {}
	void ErrMsg() const {
		cerr << ">>> ������ ��� ������ � ����������! �������� ����� � ������ '���������������'" << endl;
	}
};