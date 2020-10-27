#pragma once
#include <iostream>
#include "DinArray.h"

using namespace std;

typedef int selectType;

template <class Data = int>
class Menu {
private:
	static void printMainMenu() {
		cout << "Меню программы:" << endl
			<< "[1]	Добавить новый элемент" << endl
			<< "[2]	Добавить новый элемент по индексу" << endl
			<< "[3]	Удалить элемент" << endl
			<< "[4]	Удалить элемент по индексу" << endl
			<< "[5]	Удалить элемент по значению" << endl
			<< "[6]	Узнать размер массива" << endl
			<< "[7]	Узнать ёмкость массива" << endl
			<< "[8]	Очистка массива" << endl
			<< "[9]	Проверить массив на пустоту" << endl
			<< "[10]	Узнать наличие заданного значения" << endl
			<< "[11]	Считать значение по индексу" << endl
			<< "[12]	Изменить значение по индексу" << endl
			<< "[13]	Получить позицию в массиве с заданным значением" << endl
			<< "[14]	Запрос прямого итератора" << endl
			<< "[15]	Запрос обратного итератора" << endl
			<< "[16]	Запрос неустановленного прямого итератора" << endl
			<< "[17]	Запрос неустановленного обратного итератора" << endl
			<< "[18]	Вывести массив" << endl
			<< "[19]	Iterator == rIterator" << endl
			<< "[20]	Iterator == end()" << endl
			<< "[21]	rIterator == rend()" << endl
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
			<< "[0] Выход" << endl
			<< endl << ">>> ";
	}

public:
	static void startMenu(DinArray<Data>& DA) {
		auto iter = DA.end();
		auto riter = DA.rend();

		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			cout << "Массив элементов: ";
			if (DA.get_size() == 0)
				cout << "Пуст";
			else
				DA.print();

			cout << endl << "Размер массива: " << DA.get_size();
			cout << endl << "Ёмкость массива: " << DA.get_capacity() << endl << endl;
			printMainMenu();
			cin >> input;

			try {
				switch (input) {

				case 1: {
					selectType buf;
					cout << ">>> Введите новое значение: ";
					cin >> buf;
					DA.push(buf);
					system("pause");
					break;
				}

				case 2: {
					selectType buf;
					int index;
					cout << ">>> Введите новое значение: ";
					cin >> buf;
					cout << ">>> Введите индекс: ";
					cin >> index;
					cout << ">>> Результат операции: " << DA.push(buf, index) << endl;
					system("pause");
					break;
				}

				case 3: {
					DA.remove();
					cout << ">>> Удаление успешно!" << endl;
					system("pause");
					break;
				}

				case 4: {
					int index;
					cout << ">>> Удаление" << endl << ">>> Введите индекс: ";
					cin >> index;
					cout << ">>> Результат операции: " << DA.remove(index) << endl;
					system("pause");
					break;
				}

				case 5: {
					selectType obj;
					cout << ">>> Удаление" << endl << ">>> Введите значение: ";
					cin >> obj;
					cout << ">>> Результат операции: " << DA.remove_by_obj(obj) << endl;
					system("pause");
					break;
				}

				case 6: {
					cout << ">>> Размер массива: " << DA.get_size() << endl;
					system("pause");
					break;
				}

				case 7: {
					cout << ">>> Ёмкость массива: " << DA.get_capacity() << endl;
					system("pause");
					break;
				}

				case 8: {
					DA.clear();
					cout << ">>> Массив очищен!" << endl;
					system("pause");
					break;
				}

				case 9: {
					cout << "Результат операции: " << DA.isEmpty() << endl;
					system("pause");
					break;
				}

				case 10: {
					selectType buf;
					cout << ">>> Введите значение: ";
					cin >> buf;
					cout << ">>> Результат операции: " << DA.check_obj(buf) << endl;
					system("pause");
					break;
				}

				case 11: {
					int index;
					cout << ">>> Введите индекс: ";
					cin >> index;
					cout << ">>> Значение: " << DA.get_obj(index) << endl;
					system("pause");
					break;
				}

				case 12: {
					selectType buf;
					int index;
					cout << "Введите индекс: ";
					cin >> index;
					cout << "Новое значение: ";
					cin >> buf;
					cout << ">>> Результат операции: " << DA.edit_obj(buf, index) << endl;
					system("pause");
					break;
				}

				case 13: {
					selectType buf;
					cout << "Введите значение: ";
					cin >> buf;
					cout << ">>> Индекс в массиве: " << DA.get_index_obj(buf) << endl;
					system("pause");
					break;
				}

				case 14: {
					iter = DA.begin();
					Menu::iteratorMenu(DA, iter);
					system("pause");
					break;
				}

				case 15: {
					riter = DA.rbegin();
					Menu::riteratorMenu(DA, riter);
					system("pause");
					break;
				}

				case 16: {
					iter = DA.end();
					Menu::iteratorMenu(DA, iter);
					system("pause");
					break;
				}

				case 17: {
					riter = DA.rend();
					Menu::riteratorMenu(DA, riter);
					system("pause");
					break;
				}

				case 18: {
					cout << ">>> Массив элементов: ";
					if (DA.get_size() == 0)
						cout << "Пуст";
					else
						DA.print();
					cout << endl;
					system("pause");
					break;
				}

				case 19: {
					cout << ">>> Результат операции: " << ((*iter) == (*riter)) << endl;
					system("pause");
					break;
				}

				case 20: {
					cout << ">>> Результат операции: " << (iter == DA.end()) << endl;
					system("pause");
					break;
				}

				case 21: {
					cout << ">>> Результат операции: " << (riter == DA.rend()) << endl;
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

	static void iteratorMenu(DinArray<Data>& DA, typename DinArray<Data>::Iterator& iter) {
		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			printIteratorMenu(true);
			cin >> input;

			try {
				switch (input) {
				case 1: {
					iter++;
					system("pause");
					break;
				}

				case 2: {
					iter--;
					system("pause");
					break;
				}

				case 3: {
					cout << "Текущее значение: " << *iter << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << "Текущее значение: " << *iter << endl;
					cout << "Новое значение: ";
					cin >> buf;
					*iter = buf;
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

	static void riteratorMenu(DinArray<Data>& DA, typename DinArray<Data>::rIterator& riter) {
		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			printIteratorMenu(true);
			cin >> input;

			try {
				switch (input) {
				case 1: {
					riter++;
					system("pause");
					break;
				}

				case 2: {
					riter--;
					system("pause");
					break;
				}

				case 3: {
					cout << "Текущее значение: " << *riter << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << "Текущее значение: " << *riter << endl;
					cout << "Новое значение: ";
					cin >> buf;
					*riter = buf;
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