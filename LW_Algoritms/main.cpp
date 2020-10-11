#include <iostream>
#include "Tree.h"
#include "Menu.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	Tree<int, int> test;
	cout << test.insert(110, 11);
	cout << test.insert(100, 9);
	cout << test.insert(12, 6);
	cout << test.insert(119, 14);
	cout << test.insert(116, 7);

	cout << test.getData(116) << endl;
	cout << test.setData(117, 22) << endl;
	cout << test.setData(12, 3) << endl;
	//Menu::startMenu();

	return 0;
}