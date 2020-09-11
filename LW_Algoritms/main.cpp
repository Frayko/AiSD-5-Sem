#include <iostream>

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