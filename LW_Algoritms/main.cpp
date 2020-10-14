#include <iostream>
#include "Tree.h"
#include "Menu.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	try {

	Tree<int, int> test;
	cout << test.insert(110, 11);
	cout << test.insert(100, 9);
	cout << test.insert(12, 6);
	cout << test.insert(119, 14);
	cout << test.insert(119, 7);

	cout << endl << endl;

		cout << test.find(116) << endl;
		cout << test.set(117, 22) << endl;
		cout << test.set(12, 3) << endl;
		//Menu::startMenu();

	}
	catch (TreeError& te) {
		te.ErrMsg();
	}
	catch (...) {
		cerr << "Error in main" << endl;
	}

	system("pause");
	return 0;
}