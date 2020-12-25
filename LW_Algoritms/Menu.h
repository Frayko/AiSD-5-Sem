#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Hashtable.h"
using namespace std;

class Menu {
private:
	static void printMainMenu() {
		cout << "[1] ���-������� � �������� ����������" << endl
			<< "[2] ���-������� � ��������� ��������" << endl
			<< "[3] ������ �������� ����������� ���2" << endl
			<< "[4] ������������ ���-������� � �������� ����������" << endl
			<< "[5] ������������ ���-������� � ��������� ��������" << endl
			<< "[Esc] �����" << endl << endl << ">>> ";
	}

	static void printHashTableMenu() {
		cout << "[1] �������" << endl
			<< "[2] ��������" << endl
			<< "[3] �����" << endl
			<< "[4] ����������� �������" << endl
			<< "[5] �����" << endl
			<< "[6] ���������� ���������" << endl
			<< "[7] �������� �� �������" << endl
			<< "[8] ������� �������" << endl
			<< "[9] ������ ��������" << endl
			<< "[Esc] �����" << endl << endl << ">>> ";
	}

	static void printIteratorMenu() {
		cout << "���� ���������:" << endl
			<< "[1] ���������� �� ������" << endl
			<< "[2] ��������� �������" << endl
			<< "[3] �������� ������ ���������" << endl
			<< "[4] ��������� ������ �� �������� ��������" << endl
			<< "[5] ������������ ������� �������" << endl
			<< "[6] ��������� ���� �� �������� ��������" << endl
			<< "[Esc] �����" << endl << endl << ">>> ";
	}
public:
	static void start(HashTableOA<char*, int>& htoa, HashTableCC<char*, int>& htcc, int n) {
		int d, i, j, *m, cnt, p, kk;
		double x, x2, x_sum, a, alfa, cntI, cntD, cntS;
		char k[100], c[22], * t, ** mas;
		HashTableOA <char*, int>::Iterator it_oa(&htoa);
		HashTableCC <char*, int>::Iterator it_cc(&htcc);
		bool exit, iterator_exit;
		while (true) {
			system("cls");
			exit = false;
			printMainMenu();
			switch (_getch()) {
			case '1':
				while (true) {
					system("cls");
					cout << "���-������� � �������� ����������" << endl;
					printHashTableMenu();
					try {
						switch (_getch()) {
						case '1':
							cout << "������� ����: ";
							cin.ignore(); cin.getline(k, 100);
							cout << "������� ������: ";
							cin >> d;
							htoa.Insert(k, d);
							break;
						case '2':
							cout << "������� ����: ";
							cin.ignore(); cin.getline(k, 100);
							htoa.Delete(k);
							break;
						case '3':
							cout << "������� ����: ";
							cin.ignore(); cin.getline(k, 100);
							cout << "������, ��������� �� ����� �� �����: " << htoa.Search(k) << endl;
							system("pause");
							break;
						case '4':
							htoa.Print();
							system("pause");
							break;
						case '5':
							cout << "�����: " << htoa.GetAlfa() << endl;
							system("pause");
							break;
						case '6':
							cout << "���������� ���������: " << htoa.Count() << endl;
							system("pause");
							break;
						case '7':
							if (htoa.isEmpty())
								cout << "������� �����" << endl;
							else
								cout << "������� �� �����" << endl;
							system("pause");
							break;
						case '8':
							htoa.~HashTableOA();
							cout << "������� �������" << endl;
							system("pause");
							break;
						case '9':
							iterator_exit = false;
							while (!iterator_exit) {
								system("cls");
								printIteratorMenu();
								switch (_getch()) {
								case '1':
									it_oa.first();
									cout << "�������� ���������� �� ������" << endl;
									system("pause");
									break;
								case '2':
									it_oa.next();
									cout << "������� � ���������� ��������" << endl;
									system("pause");
									break;
								case '3':
									if (!it_oa.is_off())
										cout << "�������� � ������ '�������������'" << endl;
									else
										cout << "�������� � ������ '�� �������������'" << endl;
									system("pause");
									break;
								case '4':
									cout << "������ �� �������� �����: " << *it_oa << endl;
									system("pause");
									break;
								case '5':
									cout << "������� ����� ������:";
									cin >> d;
									*it_oa = d;
									break;
								case '6':
									cout << "������� ����: " << it_oa.showkey() << endl;
									system("pause");
									break;
								case 27:
									iterator_exit = true;
								}
							}
							break;
						case 27:
							exit = true;
						}
						if (exit)break;
					}
					catch (exception& ex) {
						cerr << ex.what() << endl;
						system("pause");

					}
				}
				break;
			case '2':
				while (true) {
					system("cls");
					cout << "���-������� � ��������� ��������" << endl;
					printHashTableMenu();
					try {
						switch (_getch()) {
						case '1':
							cout << "������� ����: ";
							cin.ignore(); cin.getline(k, 100);
							cout << "������� ������: ";
							cin >> d;
							htcc.Insert(k, d);
							break;
						case '2':
							cout << "������� ����: ";
							cin.ignore(); cin.getline(k, 100);
							htcc.Delete(k);
							break;
						case '3':
							cout << "������� ����: ";
							cin.ignore(); cin.getline(k, 100);
							cout << "������, ��������� �� ����� �� �����: " << htcc.Search(k) << endl;
							system("pause");
							break;
						case '4':
							htcc.Print();
							system("pause");
							break;
						case '5':
							cout << "�����: " << htcc.GetAlfa() << endl;
							system("pause");
							break;
						case '6':
							cout << "���������� ���������: " << htcc.Count() << endl;
							system("pause");
							break;
						case '7':
							if (htcc.isEmpty())
								cout << "������� �����" << endl;
							else
								cout << "������� �� �����" << endl;
							system("pause");
							break;
						case '8':
							htcc.~HashTableCC();
							cout << "������� �������" << endl;
							system("pause");
							break;
						case '9':
							iterator_exit = false;
							while (!iterator_exit) {
								system("cls");
								printIteratorMenu();
								switch (_getch()) {
								case '1':
									it_cc.first();
									cout << "�������� ���������� �� ������" << endl;
									system("pause");
									break;
								case '2':
									it_cc.next();
									cout << "������� � ���������� ��������" << endl;
									system("pause");
									break;
								case '3':
									if (!it_cc.is_off())
										cout << "�������� � ������ '�������������'" << endl;
									else
										cout << "�������� � ������ '�� �������������'" << endl;
									system("pause");
									break;
								case '4':
									cout << "������ �� �������� �����: " << *it_cc << endl;
									system("pause");
									break;
								case '5':
									cout << "������� ����� ������:";
									cin >> d;
									*it_cc = d;
									break;
								case '6':
									cout << "������� ����: " << it_cc.showkey() << endl;
									system("pause");
									break;
								case 27:
									iterator_exit = true;
								}
							}
							break;
						case 27:
							exit = true;
						}
						if (exit)break;
					}
					catch (exception& ex) {
						cerr << ex.what() << endl;
						system("pause");

					}
				}
				break;
			case '3':
				system("cls");
				int size;
				x_sum = 0;
				cout << "���^2 ������������" << endl << "������� ������ �������: ";
				cin >> size;
				cout << endl;
				for (p = 0; p < 5; p++) {
					cout << "�������� #" << p + 1 << endl;
					cnt = 20 * size;
					a = (sqrt(5) - 1) / 2;
					m = new int[size];
					for (i = 0; i < size; i++) m[i] = 0;
					for (i = 0; i < cnt; i++) {
						int j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++) c[q] = char('�' + rand() % ('�' - '�'));
						c[j + 1] = NULL;
						unsigned long key = Key(c);
						int r = (unsigned long)(size * (key * a - (unsigned long)(key * a)));
						m[r]++;
					}
					x = 0;
					for (i = 0; i < size; i++)
						x += ((double)m[i] - 20) * ((double)m[i] - 20);
					x2 = (double)x / (20);
					x_sum += x2;
					cout << size - sqrt(double(size)) << " < " << x2 << " < " << size + sqrt(double(size)) << endl;
					cout << endl;
					delete[]m;
				}
				cout << "������� ��������: " << endl;
				cout << size - sqrt(double(size)) << " < " << x_sum / 5 << " < " << size + sqrt(double(size)) << endl;
				system("pause");
				break;
			case '4':
				system("cls");
				cntI = cntD = cntS = 0;
				cout << "������������ ���-������� � �������� ����������" << endl;
				cout << "������� ����� ����� (�� 0.0 �� 1.0): ";
				cin >> alfa;
				if (alfa > 1.0) {
					cout << "����� ����� " << alfa << " -> 1.0" << endl;
					alfa = 1.0;
				}
				else if (alfa < 0.0) {
					cout << "����� ����� ������ ����" << endl;
					system("pause");
					break;
				}
				cout << endl;
				size = n * 2;
				htoa.~HashTableOA();
				mas = new char* [(int)(alfa * size + 1)];
				for (i = 0; i < (alfa * size); i++) {
					j = 10 + rand() % 10;
					for (int q = 0; q <= j; q++) c[q] = char('�' + rand() % ('�' - '�'));
					c[j + 1] = NULL;
					mas[i] = new char[strlen(c) + 1];
					strcpy(mas[i], c);
					htoa.TestInsert(mas[i]);
				}
				for (i = 0; i < (alfa * size) / 2; i++) {
					if (i % 10 == 0) {	// 10% ��������
						j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++) c[q] = char('�' + rand() % ('�' - '�'));
						c[j + 1] = NULL;
						cntD += htoa.TestDelete(c);
						cntI += htoa.TestInsert(mas[(rand() * rand() + rand()) % (int)(alfa * size)]);
						cntS += htoa.TestSearch(c);
					}
					else {	// 90% �������� ��������
						kk = (rand() * rand() + rand()) % (int)(alfa * size);
						cntD += htoa.TestDelete(mas[kk]);
						delete mas[kk];
						j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++)
							c[q] = char('�' + rand() % ('�' - '�'));
						c[j + 1] = NULL;
						mas[kk] = new char[strlen(c) + 1];
						strcpy(mas[kk], c);
						cntI += htoa.TestInsert(mas[kk]);
						cntS += htoa.TestSearch(mas[(rand() * rand() + rand()) % (int)(alfa * size)]);
					}
				}
				for (i = 0; i < (alfa * size); i++)
					delete mas[i];
				delete[] mas;
				cout << "��������\t�����������\t������" << endl;
				cout << "������� \t" << setprecision(3) << 2 * cntI / (alfa * size) << " �\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa))) << " �" << endl;
				cout << "�������� \t" << setprecision(3) << 2 * cntD / (alfa * size) << " �\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) << " �" << endl;
				cout << "����� \t\t" << setprecision(3) << 2 * cntS / (alfa * size) << " �\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) << " �" << endl;
				system("pause");
				break;
			case '5':
				system("cls");
				cntI = cntD = cntS = 0;
				cout << "������������ ���-������� � �������� ��������" << endl;
				cout << "������� ����� ����� (�� 0.0 �� 1.0): ";
				cin >> alfa;
				if (alfa > 1.0) {
					cout << "����� ����� " << alfa << " -> 1.0" << endl;
					alfa = 1.0;
				}
				else if (alfa < 0.0) {
					cout << "����� ����� ������ ����" << endl;
					system("pause");
					break;
				}
				cout << endl;
				size = n / 2;
				htcc.~HashTableCC();
				mas = new char* [(int)(alfa * size + 1)];
				for (i = 0; i < (alfa * size); i++) {
					j = 10 + rand() % 10;
					for (int q = 0; q <= j; q++)
						c[q] = char('�' + rand() % ('�' - '�'));
					c[j + 1] = NULL;
					mas[i] = new char[strlen(c) + 1];
					strcpy(mas[i], c);
					htcc.TestInsert(mas[i]);
				}
				cntI = cntD = cntS = 0;
				for (i = 0; i < (alfa * size) / 2; i++) {
					if (i % 10 == 0) {	// 10% ��������
						j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++) c[q] = char('�' + rand() % ('�' - '�'));
						c[j + 1] = NULL;
						cntD += htcc.TestDelete(c);
						cntI += htcc.TestInsert(mas[(rand() * rand() + rand()) % (int)(alfa * size)]);
						cntS += htcc.TestSearch(c);
					}
					else {	// 90% �������� ��������
						kk = (rand() * rand() + rand()) % (int)(alfa * size);
						cntD += htcc.TestDelete(mas[kk]);
						delete mas[kk];
						j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++) c[q] = char('�' + rand() % ('�' - '�'));
						c[j + 1] = NULL;
						mas[kk] = new char[strlen(c) + 1];
						strcpy(mas[kk], c);
						cntI += htcc.TestInsert(mas[kk]);
						cntS += htcc.TestSearch(mas[(rand() * rand() + rand()) % (int)(alfa * size)]);
					}
				}
				for (i = 0; i < (alfa * size); i++)
					delete mas[i];
				delete[] mas;
				cout << "��������\t�����������\t������" << endl;
				cout << "������� \t" << setprecision(3) << 2 * cntI / (alfa * size) << " �\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa))) << " �" << endl;
				cout << "�������� \t" << setprecision(3) << 2 * cntD / (alfa * size) << " �\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) << " �" << endl;
				cout << "����� \t\t" << setprecision(3) << 2 * cntS / (alfa * size) << " �\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) << " �" << endl;
				system("pause");
				break;
			case 27:
				return;
			}
		}
	}
};