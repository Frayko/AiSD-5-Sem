#include <iostream>
#include "DinArray.h"
#include "listErrors.h"
#include "Menu.h"

 using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	DinArray<int> DA(10);
	Menu::startMenu(DA);

	return 0;
}