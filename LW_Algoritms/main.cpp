#include <iostream>
#include "Tree.h"
#include "Menu.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	try {

	Tree<int, int> test;
	cout << test.insert(60, 11);
	cout << test.insert(40, 9);
	cout << test.insert(50, 6);
	cout << test.insert(20, 14);
	cout << test.insert(30, 7);
	cout << test.insert(10, 2);
	cout << test.insert(80, 13);
	cout << test.insert(70, 25);
	cout << test.insert(90, 33);

	cout << endl << endl;

	cout << test.find(80) << endl;
	cout << test.set(117, 22) << endl;
	cout << test.set(40, 3) << endl << endl;
	cout << test.getSerialNumber(60) << endl;
	cout << test.getSerialNumber(40) << endl;
	cout << test.getSerialNumber(10) << endl;
	cout << test.getSerialNumber(90) << endl;
	cout << test.getSerialNumber(0) << endl;
	cout << test.getSerialNumber(100) << endl;
	cout << test.getSerialNumber(61) << endl << endl;
	test.printKeys();
	cout << endl << endl;
	test.print();
	//Menu::startMenu();

	}
	catch (TreeError& te) {
		te.ErrMsg();
	}
	catch (IteratorError& ie) {
		ie.ErrMsg();
	}
	catch (...) {
		cerr << "Error in main" << endl;
	}

	system("pause");
	return 0;
}