#include <iostream>
#include "Tree.h"
#include "Menu.h"
#include "Test.h"

//#define TEST

#ifdef TEST

int main() {
	setlocale(LC_ALL, "rus");

	Tree<int, int> tree;

	cout << "���� ����������� �������� ���������� BST-������" << endl;
	test_rand(1000);

	cout << endl << "���� ����������� �������� ������������ BST-������" << endl;

	test_ord(1000);

	system("pause");
	return 0;
}

#else

int main() {
	setlocale(LC_ALL, "rus");

	Tree<int, int> tree;

	Menu<int, int>::startMenu(tree);

	system("pause");
	return 0;
}

#endif