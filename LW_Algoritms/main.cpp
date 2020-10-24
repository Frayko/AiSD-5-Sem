#include <iostream>
#include "Tree.h"
#include "Menu.h"
#include "Test.h"

//#define TEST

#ifdef TEST

int main() {
	setlocale(LC_ALL, "rus");

	Tree<int, int> tree;

	cout << "Тест трудоёмкости операций случайного BST-дерева" << endl;
	test_rand(1000);

	cout << endl << "Тест трудоёмкости операций вырожденного BST-дерева" << endl;

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