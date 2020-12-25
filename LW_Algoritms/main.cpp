#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include "Hashtable.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите число элементов (например: 128): ";
	cin >> n;
	HashTableOA <char*, int> htoa(n);
	HashTableCC <char*, int> htcc(n);
	Menu::start(htoa, htcc, n);

	return 0;
}