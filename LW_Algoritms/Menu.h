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
		cout << "���� ���������:" << endl
			<< "[1]	������ ������ ������" << endl
			<< "[2]	�������� ������" << endl
			<< "[3]	��������� ������ �� �������" << endl
			<< "[4]	��������� �������� �� �����" << endl
			<< "[5]	�������� �������� �� �����" << endl
			<< "[6]	��������� ������ �� �����" << endl
			<< "[7]	�������� ������ �� �����" << endl
			<< "[8]	�������� ������ �������� � ��������� ������� (begin)" << endl
			<< "[9]	�������� ������ �������� � �������� ������� (end)" << endl
			<< "[10]	�������� �������� �������� � ��������� ������� (begin)" << endl
			<< "[11]	�������� �������� �������� � �������� ������� (end)" << endl
			<< "[12]	Iterator == begin()" << endl
			<< "[13]	Iterator == end()" << endl
			<< "[14]	rIterator == rbegin()" << endl
			<< "[15]	rIterator == rend()" << endl
			<< "[16]	Iterator == rIterator" << endl
			<< "[17]	����� ������" << endl
			<< "[18]	�������� �������� ��������" << endl
			<< "[19]	����� �����������" << endl
			<< "[0]	�����" << endl
			<< endl << ">>> ";
	}

	static void printIteratorMenu(bool l) {
		if (l == true)
			cout << "���� ������� ���������:" << endl;
		else
			cout << "���� ��������� ���������:" << endl;

		cout << "[1] ���������" << endl
			<< "[2] ����������" << endl
			<< "[3] �������� ������� ��������" << endl
			<< "[4] �������� ������� ��������" << endl
			<< "[0] �����" << endl
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
					cout << "������� ��������: " << *iter << endl;
					system("pause");
					break;
				}

				case 4: {
					selectData data;
					cout << "������� ������: " << *iter << endl;
					cout << "����� ������: ";
					cin >> data;
					*iter = data;
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

			catch (IteratorError& err) {
				err.ErrMsg();
				system("pause");
			}
			catch (...) {
				cout << ">>> �������������� ������ � ���� ���������!" << endl;
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
					cout << "������� ��������: " << *riter << endl;
					system("pause");
					break;
				}

				case 4: {
					selectData data;
					cout << "������� ������: " << *riter << endl;
					cout << "����� ������: ";
					cin >> data;
					*riter = data;
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

			catch (IteratorError& err) {
				err.ErrMsg();
				system("pause");
			}
			catch (...) {
				cout << ">>> �������������� ������ � ���� ���������!" << endl;
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

			cout << "������ ���������: " << endl;
			if (tree.getSize() == 0)
				cout << "�����";
			else
				tree.print();

			cout << endl << "������ ������: " << tree.getSize() << endl << endl;
			printMainMenu();
			cin >> input;

			try {
				switch (input) {
				case 1: {
					cout << "������ ������: " << tree.getSize() << endl;
					system("pause");
					break;
				}

				case 2: {
					tree.clear();
					cout << "������ �������!" << endl;
					system("pause");
					break;
				}

				case 3: {
					cout << "�������� �� �������" << endl << "������ ��������: " << tree.isEmpty() << endl;
					system("pause");
					break;
				}

				case 4: {
					selectKey key;
					cout << "������ �� �����" << endl;
					cout << "������� ����: ";
					cin >> key;
					Tree<Key, Data>::resetCOUNTER();
					cout << "���������: " << tree.find(key) << endl;
					system("pause");
					break;
				}

				case 5: {
					selectKey key;
					selectData data;
					cout << "��������� �� �����" << endl;
					cout << "������� ����: ";
					cin >> key;
					cout << "������� ������: ";
					cin >> data;
					Tree<Key, Data>::resetCOUNTER();
					cout << "������ ��������: " << tree.set(key, data) << endl;
					system("pause");
					break;
				}

				case 6: {
					selectKey key;
					selectData data;
					cout << "��������� �� �����" << endl;
					cout << "������� ����: ";
					cin >> key;
					cout << "������� ������: ";
					cin >> data;
					Tree<Key, Data>::resetCOUNTER();
					cout << "������ ��������: " << tree.insert(key, data) << endl;
					system("pause");
					break;
				}

				case 7: {
					selectKey key;
					cout << "�������� �� �����" << endl;
					cout << "������� ����: ";
					cin >> key;
					Tree<Key, Data>::resetCOUNTER();
					cout << "������ ��������: " << tree.remove(key) << endl;
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
					cout << "���������: " << (iter == tree.begin()) << endl;
					system("pause");
					break;
				}

				case 13: {
					cout << "Iterator == end()" << endl;
					cout << "���������: " << (iter == tree.end()) << endl;
					system("pause");
					break;
				}

				case 14: {
					cout << "rIterator == rbegin()" << endl;
					cout << "���������: " << (riter == tree.rbegin()) << endl;
					system("pause");
					break;
				}

				case 15: {
					cout << "rIterator == rend()" << endl;
					cout << "���������: " << (riter == tree.rend()) << endl;
					system("pause");
					break;
				}

				case 16: {
					cout << "Iterator == rIterator" << endl;
					cout << "���������: " << (*iter == *riter) << endl;
					system("pause");
					break;
				}

				case 17: {
					cout << "����� ������" << endl;
					tree.print();
					cout << endl;
					system("pause");
					break;
				}

				case 18: {
					cout << "�������� ��������: " << tree.getCOUNTER() << endl;
					system("pause");
					break;
				}

				case 19: {
					system("cls");

					for (int i = 5000, j = 1; i <= 20000; i += 5000, j++) {
						cout << "�������� #" << j << "" << endl;
						cout << "���� ����������� �������� ���������� AVL-������" << endl;
						test_rand(i);

						cout << endl << "-----------------" << endl << endl;
					}

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

			catch (TreeError& err) {
				err.ErrMsg();
				system("pause");
			}
			catch (IteratorError& err) {
				err.ErrMsg();
				system("pause");
			}
			catch (...) {
				cout << ">>> �������������� ������ � ������� ����!" << endl;
				system("pause");
			}
		}
	}
};