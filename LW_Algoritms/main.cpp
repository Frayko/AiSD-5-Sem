#include <iostream>

using namespace std;

void printMenu() {
	cout << "���� ���������:" << endl
		<< "[1] " << endl
		<< "[0] �����" << endl
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
			cout << ">>> ������ �����!\n>>> ";
			system("pause");
			break;
		}
		}
	}

	return 0;
}