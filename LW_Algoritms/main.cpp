#include <iostream>
#include "Tree.h"
#include "Menu.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	Tree<int, int> tree;

	Menu<int, int>::startMenu(tree);

	return 0;
}