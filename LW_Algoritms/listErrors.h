#pragma once
#include <iostream>
using namespace std;

class TreeError {
public:
	TreeError() {}

	virtual void ErrMsg() const {
		cerr << ">>> ������ � ������ � �������!\n";
	}

	void Continue() const {
		cerr << ">>> ��������� ���������� ��������.\n>>> ";
	}
};

class TreeDelErr : public TreeError {
public:
	TreeDelErr() {}
	void ErrMsg() const {
		cerr << ">>> ������ ��������! ������ �����!\n";
		Continue();
	}
};

class IteratorError {
public:
	IteratorError() {}

	virtual void ErrMsg() const {
		cerr << ">>> ������ � ������ ���������!\n";
	}

	void Continue() const {
		cerr << ">>> ��������� ���������� ��������.\n>>> ";
	}
};

class IteratorInactive : public IteratorError {
public:
	IteratorInactive() {}
	void ErrMsg() const {
		cerr << ">>> �������� ��������� � ������ '���������������'.\n>>> ��� ������������ ������������� ��������� �������������� �������� begin/rbegin." << endl;
		Continue();
	}
};