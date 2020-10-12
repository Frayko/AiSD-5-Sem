#pragma once
#include <iostream>
#include "DinArray.h"

using namespace std;

typedef int selectType;

class Menu {
public:
	static void printMainMenu() {
		cout << "���� ���������:" << endl
			<< "[1]	�������� ����� �������" << endl
			<< "[2]	�������� ����� ������� �� �������" << endl
			<< "[3]	������� �������" << endl
			<< "[4]	������� ������� �� �������" << endl
			<< "[5]	������� ������� �� ��������" << endl
			<< "[6]	������ ������ �������" << endl
			<< "[7]	������ ������� �������" << endl
			<< "[8]	������� �������" << endl
			<< "[9]	��������� ������ �� �������" << endl
			<< "[10]	������ ������� ��������� ��������" << endl
			<< "[11]	������� �������� �� �������" << endl
			<< "[12]	�������� �������� �� �������" << endl
			<< "[13]	�������� ������� � ������� � �������� ���������" << endl
			<< "[14]	������ ������� ���������" << endl
			<< "[15]	������ ��������� ���������" << endl
			<< "[16]	������ ���������������� ������� ���������" << endl
			<< "[17]	������ ���������������� ��������� ���������" << endl
			<< "[18]	������� ����������" << endl
			<< "[19]	������� ������" << endl
			<< "[20]	Iterator == rIterator" << endl
			<< "[21]	Iterator == end()" << endl
			<< "[22]	rIterator == rend()" << endl
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

			cout << endl << "������ �������: " << DA.get_size();
			cout << endl << "������� �������: " << DA.get_capacity() << endl << endl;
			printMainMenu();
			cin >> input;

			try {
				switch (input) {

				case 1: {
					selectType buf;
					cout << ">>> ������� ����� ��������: ";
					cin >> buf;
					DA.push(buf);
					system("pause");
					break;
				}

				case 2: {
					selectType buf;
					int index;
					cout << ">>> ������� ����� ��������: ";
					cin >> buf;
					cout << ">>> ������� ������: ";
					cin >> index;
					cout << ">>> ��������� ��������: " << DA.push(buf, index) << endl;
					system("pause");
					break;
				}

				case 3: {
					DA.remove();
					cout << ">>> �������� �������!" << endl;
					system("pause");
					break;
				}

				case 4: {
					int index;
					cout << ">>> ��������" << endl << ">>> ������� ������: ";
					cin >> index;
					cout << ">>> ��������� ��������: " << DA.remove(index) << endl;
					system("pause");
					break;
				}

				case 5: {
					selectType obj;
					cout << ">>> ��������" << endl << ">>> ������� ��������: ";
					cin >> obj;
					cout << ">>> ��������� ��������: " << DA.remove_by_obj(obj) << endl;
					system("pause");
					break;
				}

				case 6: {
					cout << ">>> ������ �������: " << DA.get_size() << endl;
					system("pause");
					break;
				}

				case 7: {
					cout << ">>> ������� �������: " << DA.get_capacity() << endl;
					system("pause");
					break;
				}

				case 8: {
					DA.clear();
					cout << ">>> ������ ������!" << endl;
					system("pause");
					break;
				}

				case 9: {
					cout << "��������� ��������: " << DA.isEmpty() << endl;
					system("pause");
					break;
				}

				case 10: {
					selectType buf;
					cout << ">>> ������� ��������: ";
					cin >> buf;
					cout << ">>> ��������� ��������: " << DA.check_obj(buf) << endl;
					system("pause");
					break;
				}

				case 11: {
					int index;
					cout << ">>> ������� ������: ";
					cin >> index;
					cout << ">>> ��������: " << DA.get_obj(index) << endl;
					system("pause");
					break;
				}

				case 12: {
					selectType buf;
					int index;
					cout << "������� ������: ";
					cin >> index;
					cout << "����� ��������: ";
					cin >> buf;
					cout << ">>> ��������� ��������: " << DA.edit_obj(buf, index) << endl;
					system("pause");
					break;
				}

				case 13: {
					selectType buf;
					cout << "������� ��������: ";
					cin >> buf;
					cout << ">>> ������ � �������: " << DA.get_index_obj(buf) << endl;
					system("pause");
					break;
				}

				case 14: {
					iter = DA.begin();
					Menu::iteratorMenu(&DA, &iter);
					system("pause");
					break;
				}

				case 15: {
					riter = DA.rbegin();
					Menu::riteratorMenu(&DA, &riter);
					system("pause");
					break;
				}

				case 16: {
					iter = DA.end();
					Menu::iteratorMenu(&DA, &iter);
					system("pause");
					break;
				}

				case 17: {
					riter = DA.rend();
					Menu::riteratorMenu(&DA, &riter);
					system("pause");
					break;
				}

				case 18: {
					DA.print_stat();
					system("pause");
					break;
				}

				case 19: {
					cout << ">>> ������ ���������: ";
					if (DA.get_size() == 0)
						cout << "����";
					else
						DA.print();
					cout << endl;
					system("pause");
					break;
				}

				case 20: {
					cout << ">>> ��������� ��������: " << ((*iter) == (*riter)) << endl;
					system("pause");
					break;
				}

				case 21: {
					cout << ">>> ��������� ��������: " << (iter == DA.end()) << endl;
					system("pause");
					break;
				}

				case 22: {
					cout << ">>> ��������� ��������: " << (riter == DA.rend()) << endl;
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
					cout << "������� ��������: " << iter->get_data() << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << "������� ��������: " << iter->get_data() << endl;
					cout << "����� ��������: ";
					cin >> buf;
					cout << endl << DA->edit_obj(buf, iter->get_cur()) << endl;
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
					cout << "������� ��������: " << riter->get_data() << endl;
					system("pause");
					break;
				}

				case 4: {
					selectType buf;
					cout << "������� ��������: " << riter->get_data() << endl;
					cout << "����� ��������: ";
					cin >> buf;
					cout << endl << DA->edit_obj(buf, riter->get_cur()) << endl;
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