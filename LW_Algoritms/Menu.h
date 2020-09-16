#pragma once
#include <iostream>
#include "DinArray.h"

using namespace std;

typedef int selectType;

class Menu {
public:
	static void printMainMenu() {
		cout << "Меню программы:" << endl
			<< "[1]	Узнать размер массива" << endl
			<< "[2]	Очистка массива" << endl
			<< "[3]	Проверить массив на пустоту" << endl
			<< "[4]	Узнать наличие заданного значения" << endl
			<< "[5]	Прочитать значение по индексу" << endl
			<< "[6]	Изменить значение по индексу" << endl
			<< "[7]	Получить позицию в массиве с заданным значением" << endl
			<< "[8]	Добавить новый элемент" << endl
			<< "[9]	Добавить новый элемент по индексу" << endl
			<< "[10]	Удалить элемент" << endl
			<< "[11]	Удалить элемент по индексу" << endl
			<< "[12]	Запрос прямого итератора" << endl
			<< "[13]	Запрос обратного итератора" << endl
			<< "[14]	Запрос неустановленного прямого итератора" << endl
			<< "[15]	Запрос неустановленного обратного итератора" << endl
			<< "[16]	Вывести статистику по индексам" << endl
			<< "[17]	Вывести массив" << endl
			<< "[18]	Iterator == rIterator" << endl
			<< "[19]	Iterator == end()" << endl
			<< "[20]	rIterator == rend()" << endl
			<< "[0]	Выход" << endl
			<< endl << ">>> ";
	}
	static void printIteratorMenu(bool l) {
		if (l == true)
			cout << "Меню прямого итератора:" << endl;
		else
			cout << "Меню обратного итератора:" << endl;

		cout << "[1] Следующий" << endl
			<< "[2] Предыдущий" << endl
			<< "[3] Получить текущее значение" << endl
			<< "[4] Изменить текущее значение" << endl
			<< "[5] В начало" << endl
			<< "[6] В конец" << endl
			<< "[0] Выход" << endl
			<< endl << ">>> ";
	}

	static void startMenu(DinArray<>& DA) {
		DinArray<>::Iterator iter = DA.end();
		DinArray<>::rIterator riter = DA.rend();

		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			cout << "Массив элементов: ";
			if (DA.get_size() == 0)
				cout << "Пуст";
			else
				DA.print();

			cout << endl << "Размер массива: " << DA.get_size() << endl << endl;
			printMainMenu();
			cin >> input;

			try {
				switch (input) {
				case 1: {
					cout << ">>> Размер массива: " << DA.get_size() << endl;
					system("pause");
					break;
				}

				case 2: {
					DA.clear();
					cout << ">>> Массив очищен!" << endl;
					system("pause");
					break;
				}

				case 3: {
					if (DA.isEmpty())
						cout << ">>> Массив пуст!" << endl;
					else
						cout << ">>> Массив не пуст!" << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << ">>> Введите значение: ";
					cin >> buf;
					cout << ">>> Результат: " << DA.check_obj(buf) << endl;
					system("pause");
					break;
				}

				case 5: {
					int index;
					cout << ">>> Введите индекс: ";
					cin >> index;
					cout << ">>> Значение: " << DA.get_obj(index) << endl;
					system("pause");
					break;
				}

				case 6: {
					selectType buf;
					int index;
					cout << "Введите индекс: ";
					cin >> index;
					cout << ">>> Текущее значение: " << DA.get_obj(index) << endl << "Новое значение: ";
					cin >> buf;
					cout << endl << DA.edit_obj(buf, index);
					system("pause");
					break;
				}

				case 7: {
					selectType buf;
					cout << "Введите значение: ";
					cin >> buf;
					cout << "Индекс в массиве: " << DA.get_index_obj(buf) << endl;
					system("pause");
					break;
				}

				case 8: {
					selectType buf;
					cout << ">>> Введите новое значение: ";
					cin >> buf;
					DA.push(buf);
					system("pause");
					break;
				}

				case 9: {
					selectType buf;
					int index;
					cout << ">>> Введите новое значение: ";
					cin >> buf;
					cout << ">>> Введите индекс: ";
					cin >> index;
					cout << endl << DA.push(buf, index) << endl;
					system("pause");
					break;
				}

				case 10: {
					DA.pop();
					cout << ">>> Удаление успешно!" << endl;
					system("pause");
					break;
				}

				case 11: {
					int index;
					cout << ">>> Удаление" << endl << ">>> Введите индекс: ";
					cin >> index;
					cout << endl << DA.pop(index) << endl;
					system("pause");
					break;
				}

				case 12: {
					iter = DA.begin();
					Menu::iteratorMenu(&DA, &iter);
					system("pause");
					break;
				}

				case 13: {
					riter = DA.rbegin();
					Menu::riteratorMenu(&DA, &riter);
					system("pause");
					break;
				}

				case 14: {
					iter = DA.end();
					Menu::iteratorMenu(&DA, &iter);
					system("pause");
					break;
				}

				case 15: {
					riter = DA.rend();
					Menu::riteratorMenu(&DA, &riter);
					system("pause");
					break;
				}

				case 16: {
					DA.print_stat();
					system("pause");
					break;
				}

				case 17: {
					cout << ">>> Массив элементов: ";
					if (DA.get_size() == 0)
						cout << "Пуст";
					else
						DA.print();
					cout << endl;
					system("pause");
					break;
				}

				case 18: {
					cout << ">>> Результат: " << ((*iter) == (*riter)) << endl;
					system("pause");
					break;
				}

				case 19: {
					cout << ">>> Результат: " << (iter == DA.end()) << endl;
					system("pause");
					break;
				}

				case 20: {
					cout << ">>> Результат: " << (riter == DA.rend()) << endl;
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
				system("pause");
			}
			catch (IteratorError& err) {
				err.ErrMsg();
				system("pause");
			}
			catch (...) {
				cout << ">>> Непредвиденная ошибка в главном меню!" << endl;
				system("pause");
			}
		}
	}

	static void iteratorMenu(DinArray<>* DA, DinArray<>::Iterator* iter) {
		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			printIteratorMenu(true);
			cin >> input;

			try {
				switch (input) {
				case 1: {
					++(*iter);
					system("pause");
					break;
				}

				case 2: {
					--(*iter);
					system("pause");
					break;
				}

				case 3: {
					cout << "Текущее значение: " << **iter << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << "Текущее значение: " << **iter << endl;
					cout << "Новое значение: ";
					cin >> buf;
					DA->edit_obj(buf, iter->get_cur());
					system("pause");
					break;
				}

				case 5: {
					*iter = DA->begin();
					system("pause");
					break;
				}

				case 6: {
					*iter = DA->end();
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

			catch (IteratorError& err) {
				err.ErrMsg();
				system("pause");
			}
			catch (...) {
				cout << ">>> Непредвиденная ошибка в меню итератора!" << endl;
				system("pause");
			}
		}
	}

	static void riteratorMenu(DinArray<>* DA, DinArray<>::rIterator* riter) {
		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			printIteratorMenu(true);
			cin >> input;

			try {
				switch (input) {
				case 1: {
					++(*riter);
					system("pause");
					break;
				}

				case 2: {
					--(*riter);
					system("pause");
					break;
				}

				case 3: {
					cout << "Текущее значение: " << **riter << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << "Текущее значение: " << **riter << endl;
					cout << "Новое значение: ";
					cin >> buf;
					DA->edit_obj(buf, riter->get_cur());
					system("pause");
					break;
				}

				case 5: {
					*riter = DA->rbegin();
					system("pause");
					break;
				}

				case 6: {
					*riter = DA->rend();
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

			catch (IteratorError& err) {
				err.ErrMsg();
				system("pause");
			}
			catch (...) {
				cout << ">>> Непредвиденная ошибка в меню итератора!" << endl;
				system("pause");
			}
		}
	}
};