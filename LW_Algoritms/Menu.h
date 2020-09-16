#pragma once
#include <iostream>
#include "DinArray.h"

using namespace std;

typedef int selectType;

class Menu {
public:
	static void printMainMenu() {
		cout << "���� ���������:" << endl
			<< "[1]	������ ������ �������" << endl
			<< "[2]	������� �������" << endl
			<< "[3]	��������� ������ �� �������" << endl
			<< "[4]	������ ������� ��������� ��������" << endl
			<< "[5]	��������� �������� �� �������" << endl
			<< "[6]	�������� �������� �� �������" << endl
			<< "[7]	�������� ������� � ������� � �������� ���������" << endl
			<< "[8]	�������� ����� �������" << endl
			<< "[9]	�������� ����� ������� �� �������" << endl
			<< "[10]	������� �������" << endl
			<< "[11]	������� ������� �� �������" << endl
			<< "[12]	������ ������� ���������" << endl
			<< "[13]	������ ��������� ���������" << endl
			<< "[14]	������ ���������������� ������� ���������" << endl
			<< "[15]	������ ���������������� ��������� ���������" << endl
			<< "[16]	������� ���������� �� ��������" << endl
			<< "[17]	������� ������" << endl
			<< "[18]	Iterator == rIterator" << endl
			<< "[19]	Iterator == end()" << endl
			<< "[20]	rIterator == rend()" << endl
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
			<< "[5] � ������" << endl
			<< "[6] � �����" << endl
			<< "[0] �����" << endl
			<< endl << ">>> ";
	}

	static void startMenu(DinArray<>& DA) {
		DinArray<>::Iterator iter = DA.end();
		DinArray<>::rIterator riter = DA.rend();

		int input;
		bool exit = false;
		while (!exit) {
			system("cls");

			cout << "������ ���������: ";
			if (DA.get_size() == 0)
				cout << "����";
			else
				DA.print();

			cout << endl << "������ �������: " << DA.get_size() << endl << endl;
			printMainMenu();
			cin >> input;

			try {
				switch (input) {
				case 1: {
					cout << ">>> ������ �������: " << DA.get_size() << endl;
					system("pause");
					break;
				}

				case 2: {
					DA.clear();
					cout << ">>> ������ ������!" << endl;
					system("pause");
					break;
				}

				case 3: {
					if (DA.isEmpty())
						cout << ">>> ������ ����!" << endl;
					else
						cout << ">>> ������ �� ����!" << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << ">>> ������� ��������: ";
					cin >> buf;
					cout << ">>> ���������: " << DA.check_obj(buf) << endl;
					system("pause");
					break;
				}

				case 5: {
					int index;
					cout << ">>> ������� ������: ";
					cin >> index;
					cout << ">>> ��������: " << DA.get_obj(index) << endl;
					system("pause");
					break;
				}

				case 6: {
					selectType buf;
					int index;
					cout << "������� ������: ";
					cin >> index;
					cout << ">>> ������� ��������: " << DA.get_obj(index) << endl << "����� ��������: ";
					cin >> buf;
					cout << endl << DA.edit_obj(buf, index);
					system("pause");
					break;
				}

				case 7: {
					selectType buf;
					cout << "������� ��������: ";
					cin >> buf;
					cout << "������ � �������: " << DA.get_index_obj(buf) << endl;
					system("pause");
					break;
				}

				case 8: {
					selectType buf;
					cout << ">>> ������� ����� ��������: ";
					cin >> buf;
					DA.push(buf);
					system("pause");
					break;
				}

				case 9: {
					selectType buf;
					int index;
					cout << ">>> ������� ����� ��������: ";
					cin >> buf;
					cout << ">>> ������� ������: ";
					cin >> index;
					cout << endl << DA.push(buf, index) << endl;
					system("pause");
					break;
				}

				case 10: {
					DA.pop();
					cout << ">>> �������� �������!" << endl;
					system("pause");
					break;
				}

				case 11: {
					int index;
					cout << ">>> ��������" << endl << ">>> ������� ������: ";
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
					cout << ">>> ������ ���������: ";
					if (DA.get_size() == 0)
						cout << "����";
					else
						DA.print();
					cout << endl;
					system("pause");
					break;
				}

				case 18: {
					cout << ">>> ���������: " << ((*iter) == (*riter)) << endl;
					system("pause");
					break;
				}

				case 19: {
					cout << ">>> ���������: " << (iter == DA.end()) << endl;
					system("pause");
					break;
				}

				case 20: {
					cout << ">>> ���������: " << (riter == DA.rend()) << endl;
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

			catch (ArrayError& err) {
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
					cout << "������� ��������: " << **iter << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << "������� ��������: " << **iter << endl;
					cout << "����� ��������: ";
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
					cout << "������� ��������: " << **riter << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << "������� ��������: " << **riter << endl;
					cout << "����� ��������: ";
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
};