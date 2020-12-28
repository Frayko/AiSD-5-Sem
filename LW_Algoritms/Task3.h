#pragma once
#include "Graph.h"
#define MAX_INT 2147483647

template <class Vertex, class Edge>
class Task3 {
	Graph<Vertex, Edge>* g;
	int** mass;
	int V, v1;
	int* distance, i;
	int* ver;
	int k;

	void solveTask(int _end) {
		int n = g->getVertexCount();
		int* d; // минимальное расстояние
		int* v; // посещенные вершины
		int temp, minindex, min;
		int begin_index = 0;
		
		d = new int[n];
		v = new int[n];

		for (int i = 0; i < n; i++) {
			d[i] = 10000;
			v[i] = 1;
		}
		d[begin_index] = 0;
		do {
			minindex = 10000;
			min = 10000;
			for (int i = 0; i < n; i++) {
				if ((v[i] == 1) && (d[i] < min)) {
					min = d[i];
					minindex = i;
				}
			}
			if (minindex != 10000)
			{
				for (int i = 0; i < n; i++)
				{
					if (mass[minindex][i] >= 0)
					{
						temp = min + mass[minindex][i];
						if (temp < d[i])
						{
							d[i] = temp;
						}
					}
				}
				v[minindex] = 0;
			}
		} while (minindex < 10000);

		cout << " Кратчайшие расстояния до вершин: " << endl; 
		for (int i = 0; i < n; i++)
			cout << d[i] << " ";

		ver = new int[n];
		int end = _end;
		ver[0] = end;
		k = 1;
		int weight = d[end];

		while (end != begin_index) {
			for (int i = 0; i < n; i++)
				if (mass[i][end] >= 0 && i != end) {
					int temp = weight - mass[i][end];
					if (temp == d[i]) {
						weight = temp;
						end = i;
						ver[k] = i;
						k++;
					}
				}
		}

		cout << endl << "Вывод кратчайшего пути" << endl;
		for (int i = k - 1; i >= 0; i--)
			cout << ver[i] << " ";
		cout << endl;
		delete[] d;
		delete[] v;
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
	Task3(Graph<Vertex, Edge>* g, int i) {
		this->g = g;
		cout << "Матрица смежности графа: " << endl;
		init_mass();
		solveTask(i);
	}

	Task3(Task3& T) {}

	~Task3() {
		if (mass) {
			if (!g)
				return;
			for (int i = 0; i < g->getVertexCount(); i++) {
				if (mass[i])
					delete[] mass[i];
			}
			mass = nullptr;
		}

		if (distance)
			delete[] distance;
	}

	void Set(Graph<Vertex, Edge>* g, int i) {
		this->g = g;
		cout << "Матрица смежности графа: " << endl;
		init_mass();
		solveTask(i);
	}

	void Restart(int i) {
		solveTask(i);
	}

	void Result() {
		cout << endl << "Вывод кратчайшего пути" << endl;
		for (int i = k - 1; i >= 0; i--)
			cout << ver[i] << "->";
		cout << endl;
	}
};