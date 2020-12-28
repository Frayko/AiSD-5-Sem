#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"
#include "Task2.h"
#include "Task3.h"
using namespace std;

int main() {
	Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>* graph = new Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>();
	Vertex<string, int>* vertex;
	Edge<Vertex<string, int>, int, int>* edge;

	Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>::VertexIterator* vIt;
	Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>::EdgeIterator* eIt;
	Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>::OutputEdgeIterator* oIt;
	int ves = 0;
	setlocale(LC_ALL, "rus");

	int input;

	bool exit = false;
	while (!exit) {
		system("cls");
		cout << "[1] Создать граф с V вершинами, без ребер, типа D, формы представления F" << endl
			<< "[2] Создать пустой L-граф с нулевым числом вершин и рёбер" << endl
			<< "[3] Создать граф с V вершинами, с E случайными ребрами, типа D , формы F" << endl
			<< "[0] Выход" << endl << endl << ">>> ";
		cin >> input;
		switch (input) {
		case 1: {
			int v;
			bool directed, dense;
			cout << "Количество вершин: ";
			cin >> v;
			cout << "Тип графа (1 - ориентированный, 0 - неориентированный): ";
			cin >> directed;
			cout << "Форма графа (1 - матрица, 0 - список): ";
			cin >> dense;

			graph = new Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>(v, directed, dense);
			exit = true;
			break;
		}
		case 2: {
			graph = new Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>();
			exit = true;
			break;
		}
		case 3: {
			int v, e;
			bool directed, dense;
			cout << "Количество вершин: ";
			cin >> v;
			cout << "Количество рёбер: ";
			cin >> e;
			cout << "Тип графа (1 - ориентированный, 0 - неориентированный): ";
			cin >> directed;
			cout << "Форма графа (1 - матрица, 0 - список): ";
			cin >> dense;

			graph = new Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>(v, e, directed, dense);
			exit = true;
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			cout << "Ошибка ввода!" << endl;
		}
		}
	}

	cout << "[1] Распечатать граф" << endl
		<< "[2] Опрос числа вершин в графе" << endl
		<< "[3] Опрос числа рёбер в графе" << endl
		<< "[4] Опрос типа графа" << endl
		<< "[5] Опрос формы представления графа" << endl
		<< "[6] Опрос коэффициента насыщенности графа" << endl
		<< "[7] Преобразовать граф к L-форме" << endl
		<< "[8] Преобразовать граф к M-форме" << endl
		<< "[9] Добавить вершину к графу" << endl
		<< "[10] Удалить вершину из графа" << endl
		<< "[11] Вставить ребро в граф" << endl
		<< "[12] Удалить ребро из графа" << endl
		<< "[13] Операции над вершиной" << endl
		<< "[14] Итератор вершин" << endl
		<< "[15] Итератор рёбер" << endl
		<< "[16] Итератор исходящих рёбер" << endl
		<< "[17] Операции над ребром" << endl
		<< "[18] Задача 2" << endl
		<< "[19] Задача 3" << endl
		<< "[0] Выход" << endl << endl << ">>> ";

	while (true) {
		cin >> input;
		switch (input) {
		case 1: {
			cout << "Печать графа: " << endl;
			graph->print_graph();
			break;
		};

		case 2: {
			cout << "Число вершин в графе: " << graph->getVertexCount() << endl;
			break;
		};

		case 3: {
			cout << "Число рёбер в графе: " << graph->getEdgeCount() << endl;
			break;
		};

		case 4: {
			cout << "Тип графа: ";
			if (graph->isDirected())
				cout << "ориентированный" << endl;
			else
				cout << "неориентированный" << endl;
			break;
		};

		case 5: {
			cout << "Форма предстваления графа: ";
			if (graph->isDense())
				cout << "M-граф" << endl;
			else
				cout << "L-граф" << endl;
			break;
		}

		case 6: {
			cout << "Коэффициент насыщенности: " << graph->getRatio() << endl;
			break;
		}

		case 7: {
			graph->toSparseGraph();
			cout << "Граф преобразован" << endl;
			break;
		}

		case 8: {
			graph->toDenseGraph();
			cout << "Граф преобразован" << endl;
			break;
		}

		case 9: {
			try {
				graph->insertVertex();
			}
			catch (...) {
				cout << "Ошибка";
			};
			cout << "Вершина добавлена в граф" << endl;
			break;
		}

		case 10: {
			string v1;
			cout << "Введите удаляемую вершину: ";
			cin >> v1;
			try {
				if (graph->deleteVertex(v1))
					cout << "Вершина удалена" << endl;
			}
			catch (...) {
				cout << "Ошибка" << endl;
				break;
			}
			break;
		}

		case 11: {
			string v1, v2;
			int v11, v22;
			cout << "Введите вершину, из которой выходит ребро: ";
			cin >> v1;
			cout << "Введите вершину, в которую входит ребро: ";
			cin >> v2;
			try {
				graph->insertEdge(v1, v2);
			}
			catch (...) {
				cout << "Ошибка" << endl;
				break;
			};
			cout << "Ребро добавлено в граф" << endl;
			break;
		}

		case 12: {
			string v1, v2;
			bool res;
			cout << "Введите вершину, из которой выходит ребро: ";
			cin >> v1;
			cout << "Введите вершину, в которую входит ребро: ";
			cin >> v2;
			try {
				res = graph->deleteEdge(v1, v2);
			}
			catch (...) {
				cout << "Ошибка" << endl;
				break;
			};
			cout << "Результат: " << res << endl;
			break;
		}

		case 13: {
			bool exit1 = false;

			cout << "[1] Прочитать данные о вершине" << endl
				<< "[2] Записать данные о вершине" << endl
				<< "[3] Записать новое имя вершины" << endl
				<< "[0] Выход из меню" << endl << endl << ">>> ";

			while (!exit1) {
				try {
					cin >> input;
					switch (input) {
					case 1: {
						string v;
						cout << "Введите имя вершины: ";
						cin >> v;
						cout << "Данные вершины: " << graph->read_data_vertex(v) << endl;
						break;
					}

					case 2: {
						int cur;
						string v;
						cout << "Введите имя вершины: ";
						cin >> v;
						cout << "Введите данные: ";
						cin >> cur;
						cout << "Результат: " << graph->write_data_vertex(v, cur) << endl;
						break;
					}

					case 3: {
						string v;
						string str;
						cout << "Введите имя вершины: ";
						cin >> v;
						cout << "Введите новое имя: ";
						cin >> str;
						cout << "Результат: " << graph->write_name_vertex(graph->getIndex(graph->getVertexFromName(v)), str) << endl;
						break;
					}

					case 0: {
						exit1 = true;
						break;
					}

					default: {
						cout << "Ошибка ввода!" << endl;
						break;
					}
					};
				}
				catch (...) {
					cout << "Ошибка" << endl;
				}
				if (exit1)
					break;
				cout << ">>> ";
			}
			break;
		}

		case 14: {
			bool exit1 = false;
			vIt = new Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>::VertexIterator(*graph);

			cout << "Итератор вершин:" << endl
				<< "[1] Установить итератор вершин на начальную вершину" << endl
				<< "[2] Установить итератор вершин на конечную вершину" << endl
				<< "[3] Переход к следующей позиции" << endl
				<< "[4] Прочитать вершину по текущей позиции итератора" << endl
				<< "[5] Прочитать данные вершины по текущей позиции итератора" << endl
				<< "[6] Записать данные о вершины по текущей позиции итератора" << endl
				<< "[7] Записать имя вершины по текущей позиции итератора" << endl
				<< "[0] Выход из меню итератора" << endl << endl << ">>> ";

			while (!exit1) {
				try {
					cin >> input;
					switch (input) {
					case 1: {
						vIt->begin();
						break;
					}

					case 2: {
						vIt->toend();
						break;
					}

					case 3: {
						++*vIt;
						break;
					}

					case 4: {
						string cur;
						try {
							cur = vIt->read_vertex();
						}
						catch (const char* Error) {
							cerr << Error << endl;
						}
						cout << "Вершина на текущей позиции итератора: " << cur << endl;
						break;
					}

					case 5: {
						int cur;
						try {
							cur = vIt->read_data_vertex();
						}
						catch (const char* Error) {
							cout << Error << endl;
						}
						cout << "Данные вершины на текущей позиции итератора: " << cur << endl;
						break;
					}

					case 6: {
						int cur;
						cout << "Введите данные: ";
						cin >> cur;
						try {
							vIt->write_data_vertex(cur);
						}
						catch (const char* Error) {
							cout << Error << endl;
						}
						cout << "Данные вершины записаны по текущей позиции итератора" << endl;
						break;
					}

					case 7: {
						string cur;
						cout << "Введите имя: ";
						cin >> cur;
						try {
							vIt->write_name_vertex(cur);
						}
						catch (const char* Error) {
							cout << Error << endl;
							break;
						}
						cout << "Имя вершины записано по текущей позиции итератора" << endl;
						break;
					}

					case 0: {
						exit1 = true;
						delete vIt;
						break;
					}

					default: {
						cout << "Ошибка ввода!" << endl;
						break;
					}
					};
				}
				catch (...) {
					cout << "Ошибка" << endl;
				}
				if (exit1)
					break;
				cout << ">>> ";
			}
			break;
		}

		case 15: {
			bool exit1 = false;
			eIt = new Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>::EdgeIterator(*graph);

			cout << "Итератор рёбер: " << endl
				<< "[1] Установить итератор рёбер на начальное ребро" << endl
				<< "[2] Установить итератор рёбер на конечное ребро" << endl
				<< "[3] Переход к следующей позиции" << endl
				<< "[4] Прочитать исходящую, входящую вершины ребра и вес по текущей позиции итератора" << endl
				<< "[5] Прочитать данные ребра по текущей позиции итератора" << endl
				<< "[6] Записать данные о ребре по текущей позиции итератора" << endl
				<< "[7] Записать вес ребра по текущей позиции итератора" << endl
				<< "[0] Выход из меню итератора" << endl << endl << ">>> ";

			while (!exit1) {
				try {
					cin >> input;
					switch (input) {
					case 1: {
						cout << "Результат: " << eIt->begin() << endl;
						break;
					}

					case 2: {
						cout << "Результат: " << eIt->toend() << endl;
						break;
					}

					case 3: {
						cout << "Результат: " << ++ * eIt << endl;
						break;
					}

					case 4: {
						string cur;
						try {
							cur = eIt->read_edge();
						}
						catch (const char* Error) {
							cout << "Пусто" << endl;
							break;
						}
						cout << "Ребро: " << cur << endl;
						break;
					}

					case 5: {
						int cur;
						try {
							cur = eIt->read_data_edge();
						}
						catch (const char* Error) {
							cout << Error << endl;
							break;
						}
						cout << "Данные ребра на текущей позиции итератора: " << cur << endl;
						break;
					}

					case 6: {
						int cur;
						cout << "Введите данные: ";
						cin >> cur;
						cout << "Результат: " << eIt->write_data_edge(cur) << endl;
						break;
					}

					case 7: {
						int w;
						cout << "Введите вес: ";
						cin >> w;
						cout << "Результат: " << eIt->write_weight_edge(w) << endl;
						break;
					};
						  break;
					case 0: {
						exit1 = true;
						delete eIt;
						break;
					}

					default: {
						cout << "Ошибка ввода!" << endl;
						break;
					}
					};
				}
				catch (...) {
					cout << "Ошибка!" << endl;
				}
				if (exit1)
					break;
				cout << ">>> ";
			}
			break;
		}

		case 16: {
			bool exit1 = false;
			string v;
			cout << "Введите имя вершины: ";
			cin >> v;
			try {
				oIt = new Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>::OutputEdgeIterator(*graph, *graph->getVertexFromName(v));

				cout << "Итератор исходящих рёбер: " << endl
					<< "[1] Установить итератор исходящих рёбер на начальное ребро" << endl
					<< "[2] Установить итератор исходящих рёбер на конечное ребро" << endl
					<< "[3] Переход к следующей позиции" << endl
					<< "[4] Прочитать исходящую, входящую вершины ребра и вес по текущей позиции итератора" << endl
					<< "[5] Прочитать данные ребра по текущей позиции итератора" << endl
					<< "[6] Записать данные о ребре по текущей позиции итератора" << endl
					<< "[7] Записать вес ребра по текущей позиции итератора" << endl
					<< "[0] Выход из меню итератора" << endl << endl << ">>> ";

				while (!exit1) {
					cin >> input;
					switch (input) {
					case 1: {
						cout << "Результат: " << oIt->begin() << endl;
						break;
					}

					case 2: {
						cout << "Результат: " << oIt->toend() << endl;
						break;
					}

					case 3: {
						cout << "Результат: " << ++ * oIt << endl;
						break;
					}

					case 4: {
						string cur;
						try {
							cur = oIt->read_edge();
						}
						catch (const char* Error) {
							cout << "Пусто" << endl;
							break;
						}
						cout << "Ребро: " << cur << endl;
						break;
					}

					case 5: {
						int cur;
						try {
							cur = oIt->read_data_edge();
						}
						catch (const char* Error) {
							cout << Error << endl;
							break;
						}
						cout << "Данные ребра на текущей позиции итератора: " << cur << endl;
						break;
					}

					case 6: {
						int cur;
						cout << "Введите данные: ";
						cin >> cur;
						cout << "Результат: " << oIt->write_data_edge(cur) << endl;
						break;
					}

					case 7: {
						int w;
						cout << "Введите вес: ";
						cin >> w;
						cout << "Результат: " << oIt->write_weight_edge(w) << endl;
						break;
					};
						  break;
					case 0: {
						exit1 = true;
						delete oIt;
						break;
					}

					default: {
						cout << "Ошибка ввода!" << endl;
						break;
					}
					};
					if (exit1)
						break;
					cout << ">>> ";
				}
			}
			catch (exception& err) {
				cout << err.what() << endl;
			}
			catch (...) {
				cout << "Ошибка!" << endl;
			}
			break;
		}

		case 17: {
			bool exit1 = false;

			cout << "Операции над ребром:" << endl
				<< "[1] Прочитать вес ребра" << endl
				<< "[2] Прочитать данные о ребре" << endl
				<< "[3] Записать данные о ребре" << endl
				<< "[4] Записать вес ребра" << endl
				<< "[0] Выход из меню" << endl << endl << ">>> ";

			while (!exit1) {
				cin >> input;
				switch (input) {
				case 1: {
					string v1, v2;
					int w;
					cout << "Введите имя исходящей вершины: ";
					cin >> v1;
					cout << "Введите имя входящей вершины: ";
					cin >> v2;
					try {
						w = graph->read_weight_edge(v1, v2);
					}
					catch (...) {
						cout << "Ошибка!" << endl;
						break;
					}
					cout << "Вес ребра: " << w << endl;
					break;
				}

				case 2: {
					int d;
					string v1, v2;
					cout << "Введите имя исходящей вершины: ";
					cin >> v1;
					cout << "Введите имя входящей вершины: ";
					cin >> v2;
					try {
						d = graph->read_data_edge(v1, v2);
					}
					catch (...) {
						cout << "Ошибка!" << endl;
						break;
					}
					cout << "Данные ребра: " << d << endl;
					break;
				}

				case 3: {
					int d;
					string v1, v2;
					bool rez;
					cout << "        Введите имя исходящей вершины: ";
					cin >> v1;
					cout << "        Введите имя входящей вершины: ";
					cin >> v2;
					cout << "        Введите данные: ";
					cin >> d;
					cout << "Результат: " << graph->write_data_edge(v1, v2, d) << endl;
					break;
				}

				case 4: {
					bool rez;
					string v1, v2;
					int w;
					cout << "        Введите имя исходящей вершины: ";
					cin >> v1;
					cout << "        Введите имя входящей вершины: ";
					cin >> v2;
					cout << "        Введите вес: ";
					cin >> w;
					cout << "Результат: " << graph->write_weight_edge(v1, v2, w) << endl;
					break;
				}

				case 0: {
					exit1 = true;
					break;
				}

				default: {
					cout << "Ошибка ввода!" << endl;
					break;
				}
				};
				if (exit1)
					break;
				cout << ">>> ";
			}
			break;
		}

		case 18: {
			if (!graph->isDirected()) {
				cout << "Для этой задачи требуется ориентированный граф" << endl;
				break;
			}

			Task2<Vertex<string, int>, Edge<Vertex<string, int>, int, int>> Task2(graph);
			bool exit1 = false;

			cout << "Задача 2: " << endl
				<< "[1] Задать граф и решить задачу" << endl
				<< "[2] Перерешать задачу" << endl
				<< "[3] Вывод результата решения" << endl
				<< "[0] Выход из меню задачи 2" << endl << endl << ">>> ";

			while (!exit1) {
				cin >> input;

				try {
					switch (input) {
					case 1: {
						Task2.Set(graph);
						break;
					}

					case 2: {
						Task2.Restart();
						break;
					}

					case 3: {
						Task2.Result();
						break;
					}

					case 0: {
						exit1 = true;
						break;
					}

					default: {
						cout << "Ошибка ввода" << endl;
						break;
					}
					};
				}
				catch (const char* err) {
					cout << err << endl;
				}
				catch (exception& ex) {
					cout << ex.what() << endl;
				}
				catch (...) {
					cout << "Ошибка!";
				}
				if (exit1)
					break;
				cout << ">>> ";
			}
			break;
		}

		case 19: {
			int v;
			cout << "Введите исходную вершину: ";
			cin >> v;
			Task3<Vertex<string, int>, Edge<Vertex<string, int>, int, int>> Task3(graph, v);
			bool exit1 = false;

			cout << "Задача 3: " << endl
				<< "[1] Задать граф и решить задачу" << endl
				<< "[2] Перерешать задачу" << endl
				<< "[3] Вывод результата решения" << endl
				<< "[0] Выход из меню задачи 3" << endl << endl << ">>> ";

			while (!exit1) {
				cin >> input;

				try {
					switch (input) {
					case 1: {
						cout << "Введите исходную вершину: ";
						cin >> v;
						Task3.Set(graph, v);
						break;
					}

					case 2: {
						cout << "Введите исходную вершину: ";
						cin >> v;
						Task3.Restart(v);
						break;
					}

					case 3: {
						Task3.Result();
						break;
					}

					case 0: {
						exit1 = true;
						break;
					}

					default: {
						cout << "Ошибка ввода" << endl;
						break;
					}
					};
				}
				catch (...) {
					cout << "Ошибка!";
				}
				if (exit1)
					break;
				cout << ">>> ";
			}
			break;
		}

		case 0: {
			return 0;
		}

		default: {
			cout << "Ошибка ввода!" << endl;
			break;
		}
		};
		cout << ">>> ";
	}
	return 0;
}