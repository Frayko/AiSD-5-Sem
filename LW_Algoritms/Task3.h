#pragma once
#include "Graph.h"
#define MAX_INT 2147483647

template <class Vertex, class Edge>
class Task3 {
	Graph<Vertex, Edge>* g;
	int** mass;
	int V, v1;
	int* distance, i;

	void solveTask(int v1) {
		if (distance)
			delete[] distance;

		V = g->getVertexCount();

		this->v1 = v1;

		distance = new int[V];

		int count, index, u;
		bool* visited = new bool[V];
		for (i = 0; i < V; i++)
		{
			distance[i] = INT_MAX; visited[i] = false;
		}
		distance[v1] = 0;
		for (count = 0; count < V - 1; count++)
		{
			int min = INT_MAX;
			for (i = 0; i < V; i++)
				if (!visited[i] && distance[i] <= min)
				{
					min = distance[i]; index = i;
				}
			u = index;
			visited[u] = true;
			for (i = 0; i < V; i++)
				if (!visited[i] && mass[u][i] && distance[u] != INT_MAX &&
					distance[u] + mass[u][i] < distance[i])
					distance[i] = distance[u] + mass[u][i];
		}

		delete[] visited;

		cout << "Стоимость пути из начальной вершины до остальных:" << endl;
		for (i = 0; i < V; i++) if (distance[i] != INT_MAX)
			cout << v1 << " -> " << i + 1 << " = " << distance[i] << endl;
		else cout << v1 << " -> " << i + 1 << " = " << "маршрут недоступен" << endl;
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
					mass[i][j] = 0;
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
		cout << "Стоимость пути из начальной вершины до остальных:" << endl;
		for (i = 0; i < V; i++) if (distance[i] != INT_MAX)
			cout << v1 << " -> " << i + 1 << " = " << distance[i] << endl;
		else cout << v1 << " -> " << i + 1 << " = " << "маршрут недоступен" << endl;
	}
};