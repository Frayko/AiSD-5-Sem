#pragma once
#include "Graph.h"

template <class Vertex, class Edge>
class Task2 {
	Graph<Vertex, Edge>* g;
	int** mass;

	void solveTask() {
		int n = g->getVertexCount();
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i != j && mass[i][k] != -1 && mass[k][j] != -1) {
						if (mass[i][j] == -1) {
							mass[i][j] = mass[i][k] + mass[k][j];
						}
						else
						{
							mass[i][j] = min(mass[i][j], mass[i][k] + mass[k][j]);
						}
					}
				}
			}
		}
		cout << "Новая матрица кратчайших путей орграфа: " << endl;
		print();
	}

	void init_mass() {
		if (mass) {
			if (!g)
				return;
			for (int i = 0; i < g->getVertexCount(); i++) {
				if (mass[i])
					delete[] mass[i];
			}
			mass = nullptr;
		}

		Edge* e;
		mass = new int* [g->getVertexCount()];
		for (int i = 0; i < g->getVertexCount(); i++) {
			mass[i] = new int[g->getVertexCount()];
		}

		for (int i = 0; i < g->getVertexCount(); i++) {
			for (int j = 0; j < g->getVertexCount(); j++) {
				if (i == j) {
					mass[i][j] = 0;
				}
				else if (g->hasEdge(i, j)) {
					e = g->getEdge(g->getVertex(i), g->getVertex(j));
					mass[i][j] = e->getWeight();
				}
				else {
					mass[i][j] = -1;
				}
			}
		}

		print();
	}

	void print() {
		for (int i = 0; i < g->getVertexCount(); i++) {
			for (int j = 0; j < g->getVertexCount(); j++)
				cout << setw(4) << mass[i][j] << setw(1) << ' ';
			cout << endl;
		}
		cout << endl;
	}

public:
	Task2(Graph<Vertex, Edge>* g) {
		this->g = g;
		cout << "Матрица смежности орграфа: " << endl;
		init_mass();
		solveTask();
	}
	Task2(Task2& T) {}

	~Task2() {
		if (mass) {
			if (!g)
				return;
			for (int i = 0; i < g->getVertexCount(); i++) {
				if (mass[i])
					delete[] mass[i];
			}
			mass = nullptr;
		}
	}

	void Set(Graph<Vertex, Edge>* g) {
		this->g = g;
		cout << "Матрица смежности орграфа: " << endl;
		init_mass();
		solveTask();
	}

	void Restart() {
		solveTask();
	}

	void Result() {
		cout << "Матрица кратчайших путей орграфа: " << endl;
		print();
	}
};