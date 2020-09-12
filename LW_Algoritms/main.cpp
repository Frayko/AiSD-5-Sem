#include <iostream>
#include "DinArray.h"
#include "listErrors.h"

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

		try {
			switch (input) {
			case 1: {
				DinArray <double> test(10);
				cout << "size: " << test.check_size() << endl;
				test.print_stat();
				test.push(2);
				test.push(10, 0);
				test.check_obj(2);
				test.push(3, 1);
				cout << "size: " << test.check_size() << endl;
				test.print_stat();
				test.print();
				//DinArray<double>::rIterator iter(test);
				//rIterator<double> iter2(test);
				//cout << (iter != iter2) << endl;
				cout << *iter << endl;
				++iter;
				cout << *iter << endl;
				++iter;
				cout << *iter << endl;
				++iter;
				cout << *iter << endl;

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

		catch (ArrayError& err) {
			err.ErrMsg();
		}
		catch (...) {
			cout << "Непредвиденная ошибка в while(exit)!" << endl;
		}
	}

	return 0;
}