#include <iostream>
#include "DinArray.h"

using namespace std;

void printMenu() {
	cout << "Меню программы:" << endl
		<< "[1] " << endl
		<< "[0] Выход" << endl
		<< endl << ">>> ";
}

int main() {
	setlocale(LC_ALL, "rus");
	int input;
	bool exit = false;
	while (!exit) {
		system("cls");
		printMenu();
		cin >> input;
		switch (input) {
		case 1: {
			DinArray <double> test(10);
			cout << "size: " << test.check_size() << endl;
			test.push(2);
			test.push(0, 0);
			test.push(3, 1);
			test.print();
			cout << endl;
			test.pop();
			test.pop(2);
			test.pop(1);
			test.print();
			system("pause");
			break;
		}
		case 0: { exit = true; break; }
		default: {
			cout << ">>> Ошибка ввода!\n>>> ";
			system("pause");
			break;
		}
		}
	}

	return 0;
}