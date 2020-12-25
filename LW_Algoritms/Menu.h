#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Hashtable.h"
using namespace std;

class Menu {
private:
	static void printMainMenu() {
		cout << "[1] Хеш-таблица с открытой адресацией" << endl
			<< "[2] Хеш-таблица с цепочками коллизий" << endl
			<< "[3] Оценка качества хеширования кси2" << endl
			<< "[4] Тестирование хеш-таблицы с открытой адресацией" << endl
			<< "[5] Тестирование хеш-таблицы с цепочками коллизий" << endl
			<< "[Esc] Выход" << endl << endl << ">>> ";
	}

	static void printHashTableMenu() {
		cout << "[1] Вставка" << endl
			<< "[2] Удаление" << endl
			<< "[3] Поиск" << endl
			<< "[4] Распечатать таблицу" << endl
			<< "[5] Альфа" << endl
			<< "[6] Количиство элементов" << endl
			<< "[7] Проверка на пустоту" << endl
			<< "[8] Очистка таблицы" << endl
			<< "[9] Прямой итератор" << endl
			<< "[Esc] Выход" << endl << endl << ">>> ";
	}

	static void printIteratorMenu() {
		cout << "Меню итератора:" << endl
			<< "[1] Установить на начало" << endl
			<< "[2] Следующий элемент" << endl
			<< "[3] Проверка режима итератора" << endl
			<< "[4] Прочитать данные по текущему элементу" << endl
			<< "[5] Перезаписать текущий элемент" << endl
			<< "[6] Прочитать ключ по текущему элементу" << endl
			<< "[Esc] Выход" << endl << endl << ">>> ";
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
					cout << "Хеш-таблица с открытой адресацией" << endl;
					printHashTableMenu();
					try {
						switch (_getch()) {
						case '1':
							cout << "Введите ключ: ";
							cin.ignore(); cin.getline(k, 100);
							cout << "Введите данные: ";
							cin >> d;
							htoa.Insert(k, d);
							break;
						case '2':
							cout << "Введите ключ: ";
							cin.ignore(); cin.getline(k, 100);
							htoa.Delete(k);
							break;
						case '3':
							cout << "Введите ключ: ";
							cin.ignore(); cin.getline(k, 100);
							cout << "Данные, найденные по ключу по ключу: " << htoa.Search(k) << endl;
							system("pause");
							break;
						case '4':
							htoa.Print();
							system("pause");
							break;
						case '5':
							cout << "Альфа: " << htoa.GetAlfa() << endl;
							system("pause");
							break;
						case '6':
							cout << "Количество элементов: " << htoa.Count() << endl;
							system("pause");
							break;
						case '7':
							if (htoa.isEmpty())
								cout << "Таблица пуста" << endl;
							else
								cout << "Таблица не пуста" << endl;
							system("pause");
							break;
						case '8':
							htoa.~HashTableOA();
							cout << "Таблица очищена" << endl;
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
									cout << "Итератор установлен на начало" << endl;
									system("pause");
									break;
								case '2':
									it_oa.next();
									cout << "Переход к следующему элементу" << endl;
									system("pause");
									break;
								case '3':
									if (!it_oa.is_off())
										cout << "Итератор в режиме 'установленный'" << endl;
									else
										cout << "Итератор в режиме 'не установленный'" << endl;
									system("pause");
									break;
								case '4':
									cout << "Данные по текущему ключу: " << *it_oa << endl;
									system("pause");
									break;
								case '5':
									cout << "Введите новые данные:";
									cin >> d;
									*it_oa = d;
									break;
								case '6':
									cout << "Текущий ключ: " << it_oa.showkey() << endl;
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
					cout << "Хеш-таблица с цепочками коллизий" << endl;
					printHashTableMenu();
					try {
						switch (_getch()) {
						case '1':
							cout << "Введите ключ: ";
							cin.ignore(); cin.getline(k, 100);
							cout << "Введите данные: ";
							cin >> d;
							htcc.Insert(k, d);
							break;
						case '2':
							cout << "Введите ключ: ";
							cin.ignore(); cin.getline(k, 100);
							htcc.Delete(k);
							break;
						case '3':
							cout << "Введите ключ: ";
							cin.ignore(); cin.getline(k, 100);
							cout << "Данные, найденные по ключу по ключу: " << htcc.Search(k) << endl;
							system("pause");
							break;
						case '4':
							htcc.Print();
							system("pause");
							break;
						case '5':
							cout << "Альфа: " << htcc.GetAlfa() << endl;
							system("pause");
							break;
						case '6':
							cout << "Количество элементов: " << htcc.Count() << endl;
							system("pause");
							break;
						case '7':
							if (htcc.isEmpty())
								cout << "Таблица пуста" << endl;
							else
								cout << "Таблица не пуста" << endl;
							system("pause");
							break;
						case '8':
							htcc.~HashTableCC();
							cout << "Таблица очищена" << endl;
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
									cout << "Итератор установлен на начало" << endl;
									system("pause");
									break;
								case '2':
									it_cc.next();
									cout << "Переход к следующему элементу" << endl;
									system("pause");
									break;
								case '3':
									if (!it_cc.is_off())
										cout << "Итератор в режиме 'установленный'" << endl;
									else
										cout << "Итератор в режиме 'не установленный'" << endl;
									system("pause");
									break;
								case '4':
									cout << "Данные по текущему ключу: " << *it_cc << endl;
									system("pause");
									break;
								case '5':
									cout << "Введите новые данные:";
									cin >> d;
									*it_cc = d;
									break;
								case '6':
									cout << "Текущий ключ: " << it_cc.showkey() << endl;
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
				cout << "Кси^2 тестирование" << endl << "Введите размер таблицы: ";
				cin >> size;
				cout << endl;
				for (p = 0; p < 5; p++) {
					cout << "Проверка #" << p + 1 << endl;
					cnt = 20 * size;
					a = (sqrt(5) - 1) / 2;
					m = new int[size];
					for (i = 0; i < size; i++) m[i] = 0;
					for (i = 0; i < cnt; i++) {
						int j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++) c[q] = char('А' + rand() % ('Я' - 'А'));
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
				cout << "Средние значения: " << endl;
				cout << size - sqrt(double(size)) << " < " << x_sum / 5 << " < " << size + sqrt(double(size)) << endl;
				system("pause");
				break;
			case '4':
				system("cls");
				cntI = cntD = cntS = 0;
				cout << "Тестирование хеш-таблицы с открытой адресацией" << endl;
				cout << "Введите альфа число (от 0.0 до 1.0): ";
				cin >> alfa;
				if (alfa > 1.0) {
					cout << "Альфа число " << alfa << " -> 1.0" << endl;
					alfa = 1.0;
				}
				else if (alfa < 0.0) {
					cout << "Альфа число меньше нуля" << endl;
					system("pause");
					break;
				}
				cout << endl;
				size = n * 2;
				htoa.~HashTableOA();
				mas = new char* [(int)(alfa * size + 1)];
				for (i = 0; i < (alfa * size); i++) {
					j = 10 + rand() % 10;
					for (int q = 0; q <= j; q++) c[q] = char('А' + rand() % ('Я' - 'А'));
					c[j + 1] = NULL;
					mas[i] = new char[strlen(c) + 1];
					strcpy(mas[i], c);
					htoa.TestInsert(mas[i]);
				}
				for (i = 0; i < (alfa * size) / 2; i++) {
					if (i % 10 == 0) {	// 10% промахов
						j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++) c[q] = char('А' + rand() % ('Я' - 'А'));
						c[j + 1] = NULL;
						cntD += htoa.TestDelete(c);
						cntI += htoa.TestInsert(mas[(rand() * rand() + rand()) % (int)(alfa * size)]);
						cntS += htoa.TestSearch(c);
					}
					else {	// 90% успешных операций
						kk = (rand() * rand() + rand()) % (int)(alfa * size);
						cntD += htoa.TestDelete(mas[kk]);
						delete mas[kk];
						j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++)
							c[q] = char('А' + rand() % ('Я' - 'А'));
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
				cout << "Операция\tЭксперимент\tТеория" << endl;
				cout << "Вставка \t" << setprecision(3) << 2 * cntI / (alfa * size) << " с\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa))) << " с" << endl;
				cout << "Удаление \t" << setprecision(3) << 2 * cntD / (alfa * size) << " с\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) << " с" << endl;
				cout << "Поиск \t\t" << setprecision(3) << 2 * cntS / (alfa * size) << " с\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) << " с" << endl;
				system("pause");
				break;
			case '5':
				system("cls");
				cntI = cntD = cntS = 0;
				cout << "Тестирование хеш-таблицы с цепочкой коллизий" << endl;
				cout << "Введите альфа число (от 0.0 до 1.0): ";
				cin >> alfa;
				if (alfa > 1.0) {
					cout << "Альфа число " << alfa << " -> 1.0" << endl;
					alfa = 1.0;
				}
				else if (alfa < 0.0) {
					cout << "Альфа число меньше нуля" << endl;
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
						c[q] = char('А' + rand() % ('Я' - 'А'));
					c[j + 1] = NULL;
					mas[i] = new char[strlen(c) + 1];
					strcpy(mas[i], c);
					htcc.TestInsert(mas[i]);
				}
				cntI = cntD = cntS = 0;
				for (i = 0; i < (alfa * size) / 2; i++) {
					if (i % 10 == 0) {	// 10% промахов
						j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++) c[q] = char('А' + rand() % ('Я' - 'А'));
						c[j + 1] = NULL;
						cntD += htcc.TestDelete(c);
						cntI += htcc.TestInsert(mas[(rand() * rand() + rand()) % (int)(alfa * size)]);
						cntS += htcc.TestSearch(c);
					}
					else {	// 90% успешных операций
						kk = (rand() * rand() + rand()) % (int)(alfa * size);
						cntD += htcc.TestDelete(mas[kk]);
						delete mas[kk];
						j = 10 + rand() % 10;
						for (int q = 0; q <= j; q++) c[q] = char('А' + rand() % ('Я' - 'А'));
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
				cout << "Операция\tЭксперимент\tТеория" << endl;
				cout << "Вставка \t" << setprecision(3) << 2 * cntI / (alfa * size) << " с\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa))) << " с" << endl;
				cout << "Удаление \t" << setprecision(3) << 2 * cntD / (alfa * size) << " с\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) << " с" << endl;
				cout << "Поиск \t\t" << setprecision(3) << 2 * cntS / (alfa * size) << " с\t\t" << 0.9 * (0.5) * (1 + (1 / (1 - alfa))) + 0.1 * (0.5) * (1 + (1 / (1 - alfa)) * (1 / (1 - alfa))) << " с" << endl;
				system("pause");
				break;
			case 27:
				return;
			}
		}
	}
};