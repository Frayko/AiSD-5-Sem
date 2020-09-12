#pragma once
#include <iostream>
using namespace std;

class ArrayError {
public:
	ArrayError() {}

	virtual void ErrMsg() const {
		cerr << ">>> ������ ������ ������������� �������!\n";
	}

	void Continue() const {
		cerr << ">>> ��������� ���������� ��������.\n>>> ";
	}
};

class ArrayRangedErr : public ArrayError {
public:
	ArrayRangedErr(int _count, int _actual) : count(_count), actual(_actual) {}
	void ErrMsg() const {
		cerr << ">>> ������ �������: ��������� ������ �� 0 �� " << count << ". ���������� ������: " << actual << endl;
		Continue();
	}
private:
	int count, actual;
};

class ArrayDelErr : public ArrayError {
public:
	ArrayDelErr() {}
	void ErrMsg() const {
		cerr << ">>> ������ ��������! ������ ����!\n";
		Continue();
	}
};

class IteratorError {
public:
	IteratorError() {}

	virtual void ErrMsg() const {
		cerr << ">>> ������ ������ ���������!\n";
	}

	void Continue() const {
		cerr << ">>> ��������� ���������� ��������.\n >>> ";
	}
};

class IteratorRangedErr : public IteratorError {
public:
	IteratorRangedErr(int _count, int _actual) : count(_count), actual(_actual) {}
	void ErrMsg() const {
		cerr << ">>> ������ ����������������: ��������� ������� �� 0 �� " << count << ". ���������� �������: " << actual << endl;
		Continue();
	}
private:
	int count;
	int actual;
};