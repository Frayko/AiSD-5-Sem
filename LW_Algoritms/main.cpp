#include <iostream>
#include "AVLTree.h"
#include "Menu.h"

int main() {
	setlocale(LC_ALL, "rus");

	AVLTree<int, int> tree;

	Menu<int, int>::startMenu(tree);
	return 0;
}