#pragma once
#include <iostream>
#include "AVLTree.h"
#include "listErrors.h"
#include "Test.h"

using namespace std;

typedef int selectKey;
typedef int selectData;

template <class Key = int, class Data = int>
class Menu {
private:
	static void printMainMenu() {
		cout << "Меню программы:" << endl
			<< "[1]	Узнать размер дерева" << endl
			<< "[2]	Очистить дерево" << endl
			<< "[3]	Проверить дерево на пустоту" << endl
			<< "[4]	Прочитать значение по ключу" << endl
			<< "[5]	Изменить значение по ключу" << endl
			<< "[6]	Включение данных по ключу" << endl
			<< "[7]	Удаление данных по ключу" << endl
			<< "[8]	Получить прямой итератор в начальной позиции (begin)" << endl
			<< "[9]	Получить прямой итератор в конечной позиции (end)" << endl
			<< "[10]	Получить обратный итератор в начальной позиции (begin)" << endl
			<< "[11]	Получить обратный итератор в конечной позиции (end)" << endl
			<< "[12]	Iterator == begin()" << endl
			<< "[13]	Iterator == end()" << endl
			<< "[14]	rIterator == rbegin()" << endl
			<< "[15]	rIterator == rend()" << endl
			<< "[16]	Iterator == rIterator" << endl
			<< "[17]	Вывод дерева" << endl
			<< "[18]	Получить значение счётчика" << endl
			<< "[19]	Тесты трудоёмкости" << endl
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

	static void iteratorMenu(AVLTree<Key, Data>& tree, typename Tree<Key, Data>::Iterator& iter) {
		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			tree.print(tree.getRoot(), 0, iter);

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
					selectData data;
					cout << "Текущие данные: " << *iter << endl;
					cout << "Новые данные: ";
					cin >> data;
					*iter = data;
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

	static void riteratorMenu(AVLTree<Key, Data>& tree, typename Tree<Key, Data>::rIterator& riter) {
		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			tree.print(tree.getRoot(), 0, riter);

			printIteratorMenu(false);
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
					selectData data;
					cout << "Текущие данные: " << *riter << endl;
					cout << "Новые данные: ";
					cin >> data;
					*riter = data;
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

public:
	static void startMenu(AVLTree<Key, Data>& tree) {
		auto iter = tree.begin();
		auto riter = tree.rbegin();

		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			cout << "Дерево элементов: " << endl;
			if (tree.getSize() == 0)
				cout << "Пусто";
			else
				tree.print();

			cout << endl << "Размер дерева: " << tree.getSize() << endl << endl;
			printMainMenu();
			cin >> input;

			try {
				switch (input) {
				case 1: {
					cout << "Размер дерева: " << tree.getSize() << endl;
					system("pause");
					break;
				}

				case 2: {
					tree.clear();
					cout << "Дерево очищено!" << endl;
					system("pause");
					break;
				}

				case 3: {
					cout << "Проверка на пустоту" << endl << "Статус операции: " << tree.isEmpty() << endl;
					system("pause");
					break;
				}

				case 4: {
					selectKey key;
					cout << "Чтение по ключу" << endl;
					cout << "Введите ключ: ";
					cin >> key;
					Tree<Key, Data>::resetCOUNTER();
					cout << "Результат: " << tree.find(key) << endl;
					system("pause");
					break;
				}

				case 5: {
					selectKey key;
					selectData data;
					cout << "Изменение по ключу" << endl;
					cout << "Введите ключ: ";
					cin >> key;
					cout << "Введите данные: ";
					cin >> data;
					Tree<Key, Data>::resetCOUNTER();
					cout << "Статус операции: " << tree.set(key, data) << endl;
					system("pause");
					break;
				}

				case 6: {
					selectKey key;
					selectData data;
					cout << "Включение по ключу" << endl;
					cout << "Введите ключ: ";
					cin >> key;
					cout << "Введите данные: ";
					cin >> data;
					Tree<Key, Data>::resetCOUNTER();
					cout << "Статус операции: " << tree.insert(key, data) << endl;
					system("pause");
					break;
				}

				case 7: {
					selectKey key;
					cout << "Удаление по ключу" << endl;
					cout << "Введите ключ: ";
					cin >> key;
					Tree<Key, Data>::resetCOUNTER();
					cout << "Статус операции: " << tree.remove(key) << endl;
					system("pause");
					break;
				}

				case 8: {
					iter = tree.begin();
					Menu::iteratorMenu(tree, iter);
					break;
				}

				case 9: {
					iter = tree.end();
					Menu::iteratorMenu(tree, iter);
					break;
				}

				case 10: {
					riter = tree.rbegin();
					Menu::riteratorMenu(tree, riter);
					break;
				}

				case 11: {
					riter = tree.rend();
					Menu::riteratorMenu(tree, riter);
					break;
				}

				case 12: {
					cout << "Iterator == begin()" << endl;
					cout << "Результат: " << (iter == tree.begin()) << endl;
					system("pause");
					break;
				}

				case 13: {
					cout << "Iterator == end()" << endl;
					cout << "Результат: " << (iter == tree.end()) << endl;
					system("pause");
					break;
				}

				case 14: {
					cout << "rIterator == rbegin()" << endl;
					cout << "Результат: " << (riter == tree.rbegin()) << endl;
					system("pause");
					break;
				}

				case 15: {
					cout << "rIterator == rend()" << endl;
					cout << "Результат: " << (riter == tree.rend()) << endl;
					system("pause");
					break;
				}

				case 16: {
					cout << "Iterator == rIterator" << endl;
					cout << "Результат: " << (*iter == *riter) << endl;
					system("pause");
					break;
				}

				case 17: {
					cout << "Вывод дерева" << endl;
					tree.print();
					cout << endl;
					system("pause");
					break;
				}

				case 18: {
					cout << "Значение счётчика: " << tree.getCOUNTER() << endl;
					system("pause");
					break;
				}

				case 19: {
					system("cls");

					for (int i = 5000, j = 1; i <= 20000; i += 5000, j++) {
						cout << "Итерация #" << j << "" << endl;
						cout << "Тест трудоёмкости операций случайного AVL-дерева" << endl;
						test_rand(i);

						cout << endl << "-----------------" << endl << endl;
					}

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

			catch (TreeError& err) {
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
};