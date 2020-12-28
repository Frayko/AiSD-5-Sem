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
		cout << "[1] ������� ���� � V ���������, ��� �����, ���� D, ����� ������������� F" << endl
			<< "[2] ������� ������ L-���� � ������� ������ ������ � ����" << endl
			<< "[3] ������� ���� � V ���������, � E ���������� �������, ���� D , ����� F" << endl
			<< "[0] �����" << endl << endl << ">>> ";
		cin >> input;
		switch (input) {
		case 1: {
			int v;
			bool directed, dense;
			cout << "���������� ������: ";
			cin >> v;
			cout << "��� ����� (1 - ���������������, 0 - �����������������): ";
			cin >> directed;
			cout << "����� ����� (1 - �������, 0 - ������): ";
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
			cout << "���������� ������: ";
			cin >> v;
			cout << "���������� ����: ";
			cin >> e;
			cout << "��� ����� (1 - ���������������, 0 - �����������������): ";
			cin >> directed;
			cout << "����� ����� (1 - �������, 0 - ������): ";
			cin >> dense;

			graph = new Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>(v, e, directed, dense);
			exit = true;
			break;
		}
		case 0: {
			return 0;
		}
		default: {
			cout << "������ �����!" << endl;
		}
		}
	}

	cout << "[1] ����������� ����" << endl
		<< "[2] ����� ����� ������ � �����" << endl
		<< "[3] ����� ����� ���� � �����" << endl
		<< "[4] ����� ���� �����" << endl
		<< "[5] ����� ����� ������������� �����" << endl
		<< "[6] ����� ������������ ������������ �����" << endl
		<< "[7] ������������� ���� � L-�����" << endl
		<< "[8] ������������� ���� � M-�����" << endl
		<< "[9] �������� ������� � �����" << endl
		<< "[10] ������� ������� �� �����" << endl
		<< "[11] �������� ����� � ����" << endl
		<< "[12] ������� ����� �� �����" << endl
		<< "[13] �������� ��� ��������" << endl
		<< "[14] �������� ������" << endl
		<< "[15] �������� ����" << endl
		<< "[16] �������� ��������� ����" << endl
		<< "[17] �������� ��� ������" << endl
		<< "[18] ������ 2" << endl
		<< "[19] ������ 3" << endl
		<< "[0] �����" << endl << endl << ">>> ";

	while (true) {
		cin >> input;
		switch (input) {
		case 1: {
			cout << "������ �����: " << endl;
			graph->print_graph();
			break;
		};

		case 2: {
			cout << "����� ������ � �����: " << graph->getVertexCount() << endl;
			break;
		};

		case 3: {
			cout << "����� ���� � �����: " << graph->getEdgeCount() << endl;
			break;
		};

		case 4: {
			cout << "��� �����: ";
			if (graph->isDirected())
				cout << "���������������" << endl;
			else
				cout << "�����������������" << endl;
			break;
		};

		case 5: {
			cout << "����� ������������� �����: ";
			if (graph->isDense())
				cout << "M-����" << endl;
			else
				cout << "L-����" << endl;
			break;
		}

		case 6: {
			cout << "����������� ������������: " << graph->getRatio() << endl;
			break;
		}

		case 7: {
			graph->toSparseGraph();
			cout << "���� ������������" << endl;
			break;
		}

		case 8: {
			graph->toDenseGraph();
			cout << "���� ������������" << endl;
			break;
		}

		case 9: {
			try {
				graph->insertVertex();
			}
			catch (...) {
				cout << "������";
			};
			cout << "������� ��������� � ����" << endl;
			break;
		}

		case 10: {
			string v1;
			cout << "������� ��������� �������: ";
			cin >> v1;
			try {
				if (graph->deleteVertex(v1))
					cout << "������� �������" << endl;
			}
			catch (...) {
				cout << "������" << endl;
				break;
			}
			break;
		}

		case 11: {
			string v1, v2;
			int v11, v22;
			cout << "������� �������, �� ������� ������� �����: ";
			cin >> v1;
			cout << "������� �������, � ������� ������ �����: ";
			cin >> v2;
			try {
				graph->insertEdge(v1, v2);
			}
			catch (...) {
				cout << "������" << endl;
				break;
			};
			cout << "����� ��������� � ����" << endl;
			break;
		}

		case 12: {
			string v1, v2;
			bool res;
			cout << "������� �������, �� ������� ������� �����: ";
			cin >> v1;
			cout << "������� �������, � ������� ������ �����: ";
			cin >> v2;
			try {
				res = graph->deleteEdge(v1, v2);
			}
			catch (...) {
				cout << "������" << endl;
				break;
			};
			cout << "���������: " << res << endl;
			break;
		}

		case 13: {
			bool exit1 = false;

			cout << "[1] ��������� ������ � �������" << endl
				<< "[2] �������� ������ � �������" << endl
				<< "[3] �������� ����� ��� �������" << endl
				<< "[0] ����� �� ����" << endl << endl << ">>> ";

			while (!exit1) {
				try {
					cin >> input;
					switch (input) {
					case 1: {
						string v;
						cout << "������� ��� �������: ";
						cin >> v;
						cout << "������ �������: " << graph->read_data_vertex(v) << endl;
						break;
					}

					case 2: {
						int cur;
						string v;
						cout << "������� ��� �������: ";
						cin >> v;
						cout << "������� ������: ";
						cin >> cur;
						cout << "���������: " << graph->write_data_vertex(v, cur) << endl;
						break;
					}

					case 3: {
						string v;
						string str;
						cout << "������� ��� �������: ";
						cin >> v;
						cout << "������� ����� ���: ";
						cin >> str;
						cout << "���������: " << graph->write_name_vertex(graph->getIndex(graph->getVertexFromName(v)), str) << endl;
						break;
					}

					case 0: {
						exit1 = true;
						break;
					}

					default: {
						cout << "������ �����!" << endl;
						break;
					}
					};
				}
				catch (...) {
					cout << "������" << endl;
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

			cout << "�������� ������:" << endl
				<< "[1] ���������� �������� ������ �� ��������� �������" << endl
				<< "[2] ���������� �������� ������ �� �������� �������" << endl
				<< "[3] ������� � ��������� �������" << endl
				<< "[4] ��������� ������� �� ������� ������� ���������" << endl
				<< "[5] ��������� ������ ������� �� ������� ������� ���������" << endl
				<< "[6] �������� ������ � ������� �� ������� ������� ���������" << endl
				<< "[7] �������� ��� ������� �� ������� ������� ���������" << endl
				<< "[0] ����� �� ���� ���������" << endl << endl << ">>> ";

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
						cout << "������� �� ������� ������� ���������: " << cur << endl;
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
						cout << "������ ������� �� ������� ������� ���������: " << cur << endl;
						break;
					}

					case 6: {
						int cur;
						cout << "������� ������: ";
						cin >> cur;
						try {
							vIt->write_data_vertex(cur);
						}
						catch (const char* Error) {
							cout << Error << endl;
						}
						cout << "������ ������� �������� �� ������� ������� ���������" << endl;
						break;
					}

					case 7: {
						string cur;
						cout << "������� ���: ";
						cin >> cur;
						try {
							vIt->write_name_vertex(cur);
						}
						catch (const char* Error) {
							cout << Error << endl;
							break;
						}
						cout << "��� ������� �������� �� ������� ������� ���������" << endl;
						break;
					}

					case 0: {
						exit1 = true;
						delete vIt;
						break;
					}

					default: {
						cout << "������ �����!" << endl;
						break;
					}
					};
				}
				catch (...) {
					cout << "������" << endl;
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

			cout << "�������� ����: " << endl
				<< "[1] ���������� �������� ���� �� ��������� �����" << endl
				<< "[2] ���������� �������� ���� �� �������� �����" << endl
				<< "[3] ������� � ��������� �������" << endl
				<< "[4] ��������� ���������, �������� ������� ����� � ��� �� ������� ������� ���������" << endl
				<< "[5] ��������� ������ ����� �� ������� ������� ���������" << endl
				<< "[6] �������� ������ � ����� �� ������� ������� ���������" << endl
				<< "[7] �������� ��� ����� �� ������� ������� ���������" << endl
				<< "[0] ����� �� ���� ���������" << endl << endl << ">>> ";

			while (!exit1) {
				try {
					cin >> input;
					switch (input) {
					case 1: {
						cout << "���������: " << eIt->begin() << endl;
						break;
					}

					case 2: {
						cout << "���������: " << eIt->toend() << endl;
						break;
					}

					case 3: {
						cout << "���������: " << ++ * eIt << endl;
						break;
					}

					case 4: {
						string cur;
						try {
							cur = eIt->read_edge();
						}
						catch (const char* Error) {
							cout << "�����" << endl;
							break;
						}
						cout << "�����: " << cur << endl;
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
						cout << "������ ����� �� ������� ������� ���������: " << cur << endl;
						break;
					}

					case 6: {
						int cur;
						cout << "������� ������: ";
						cin >> cur;
						cout << "���������: " << eIt->write_data_edge(cur) << endl;
						break;
					}

					case 7: {
						int w;
						cout << "������� ���: ";
						cin >> w;
						cout << "���������: " << eIt->write_weight_edge(w) << endl;
						break;
					};
						  break;
					case 0: {
						exit1 = true;
						delete eIt;
						break;
					}

					default: {
						cout << "������ �����!" << endl;
						break;
					}
					};
				}
				catch (...) {
					cout << "������!" << endl;
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
			cout << "������� ��� �������: ";
			cin >> v;
			try {
				oIt = new Graph<Vertex<string, int>, Edge<Vertex<string, int>, int, int>>::OutputEdgeIterator(*graph, *graph->getVertexFromName(v));

				cout << "�������� ��������� ����: " << endl
					<< "[1] ���������� �������� ��������� ���� �� ��������� �����" << endl
					<< "[2] ���������� �������� ��������� ���� �� �������� �����" << endl
					<< "[3] ������� � ��������� �������" << endl
					<< "[4] ��������� ���������, �������� ������� ����� � ��� �� ������� ������� ���������" << endl
					<< "[5] ��������� ������ ����� �� ������� ������� ���������" << endl
					<< "[6] �������� ������ � ����� �� ������� ������� ���������" << endl
					<< "[7] �������� ��� ����� �� ������� ������� ���������" << endl
					<< "[0] ����� �� ���� ���������" << endl << endl << ">>> ";

				while (!exit1) {
					cin >> input;
					switch (input) {
					case 1: {
						cout << "���������: " << oIt->begin() << endl;
						break;
					}

					case 2: {
						cout << "���������: " << oIt->toend() << endl;
						break;
					}

					case 3: {
						cout << "���������: " << ++ * oIt << endl;
						break;
					}

					case 4: {
						string cur;
						try {
							cur = oIt->read_edge();
						}
						catch (const char* Error) {
							cout << "�����" << endl;
							break;
						}
						cout << "�����: " << cur << endl;
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
						cout << "������ ����� �� ������� ������� ���������: " << cur << endl;
						break;
					}

					case 6: {
						int cur;
						cout << "������� ������: ";
						cin >> cur;
						cout << "���������: " << oIt->write_data_edge(cur) << endl;
						break;
					}

					case 7: {
						int w;
						cout << "������� ���: ";
						cin >> w;
						cout << "���������: " << oIt->write_weight_edge(w) << endl;
						break;
					};
						  break;
					case 0: {
						exit1 = true;
						delete oIt;
						break;
					}

					default: {
						cout << "������ �����!" << endl;
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
				cout << "������!" << endl;
			}
			break;
		}

		case 17: {
			bool exit1 = false;

			cout << "�������� ��� ������:" << endl
				<< "[1] ��������� ��� �����" << endl
				<< "[2] ��������� ������ � �����" << endl
				<< "[3] �������� ������ � �����" << endl
				<< "[4] �������� ��� �����" << endl
				<< "[0] ����� �� ����" << endl << endl << ">>> ";

			while (!exit1) {
				cin >> input;
				switch (input) {
				case 1: {
					string v1, v2;
					int w;
					cout << "������� ��� ��������� �������: ";
					cin >> v1;
					cout << "������� ��� �������� �������: ";
					cin >> v2;
					try {
						w = graph->read_weight_edge(v1, v2);
					}
					catch (...) {
						cout << "������!" << endl;
						break;
					}
					cout << "��� �����: " << w << endl;
					break;
				}

				case 2: {
					int d;
					string v1, v2;
					cout << "������� ��� ��������� �������: ";
					cin >> v1;
					cout << "������� ��� �������� �������: ";
					cin >> v2;
					try {
						d = graph->read_data_edge(v1, v2);
					}
					catch (...) {
						cout << "������!" << endl;
						break;
					}
					cout << "������ �����: " << d << endl;
					break;
				}

				case 3: {
					int d;
					string v1, v2;
					bool rez;
					cout << "        ������� ��� ��������� �������: ";
					cin >> v1;
					cout << "        ������� ��� �������� �������: ";
					cin >> v2;
					cout << "        ������� ������: ";
					cin >> d;
					cout << "���������: " << graph->write_data_edge(v1, v2, d) << endl;
					break;
				}

				case 4: {
					bool rez;
					string v1, v2;
					int w;
					cout << "        ������� ��� ��������� �������: ";
					cin >> v1;
					cout << "        ������� ��� �������� �������: ";
					cin >> v2;
					cout << "        ������� ���: ";
					cin >> w;
					cout << "���������: " << graph->write_weight_edge(v1, v2, w) << endl;
					break;
				}

				case 0: {
					exit1 = true;
					break;
				}

				default: {
					cout << "������ �����!" << endl;
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
				cout << "��� ���� ������ ��������� ��������������� ����" << endl;
				break;
			}

			Task2<Vertex<string, int>, Edge<Vertex<string, int>, int, int>> Task2(graph);
			bool exit1 = false;

			cout << "������ 2: " << endl
				<< "[1] ������ ���� � ������ ������" << endl
				<< "[2] ���������� ������" << endl
				<< "[3] ����� ���������� �������" << endl
				<< "[0] ����� �� ���� ������ 2" << endl << endl << ">>> ";

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
						cout << "������ �����" << endl;
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
					cout << "������!";
				}
				if (exit1)
					break;
				cout << ">>> ";
			}
			break;
		}

		case 19: {
			int v;
			cout << "������� �������� �������: ";
			cin >> v;
			Task3<Vertex<string, int>, Edge<Vertex<string, int>, int, int>> Task3(graph, v);
			bool exit1 = false;

			cout << "������ 3: " << endl
				<< "[1] ������ ���� � ������ ������" << endl
				<< "[2] ���������� ������" << endl
				<< "[3] ����� ���������� �������" << endl
				<< "[0] ����� �� ���� ������ 3" << endl << endl << ">>> ";

			while (!exit1) {
				cin >> input;

				try {
					switch (input) {
					case 1: {
						cout << "������� �������� �������: ";
						cin >> v;
						Task3.Set(graph, v);
						break;
					}

					case 2: {
						cout << "������� �������� �������: ";
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
						cout << "������ �����" << endl;
						break;
					}
					};
				}
				catch (...) {
					cout << "������!";
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
			cout << "������ �����!" << endl;
			break;
		}
		};
		cout << ">>> ";
	}
	return 0;
}