#pragma once
#include "Graph.h"
#define MAX_INT 2147483647

template <class Vertex, class Edge>
class Task3 {
	Graph<Vertex, Edge>* g;
	int** mass;
	int* d, * ver;
	vector<int*> results;
	vector<int*> dist;

	void solveTask(int target) {
		int n = g->getVertexCount();
		int k = 0;
		for (int i = 0; i < n - 1; i++) {
			if (i != target)
				if (dijkstra(i, target))
					k++;
		}
		if (k == 0)
			cout << "Кратчаших путей в " << target << " не обнаружено" << endl;
	}

	bool dijkstra(int _start, int _end) {
		int k;
		int n = g->getVertexCount();
		int* v;
		int temp, minindex, min;
		int begin_index = _start;

		d = new int[n];
		v = new int[n];

		for (int i = 0; i < n; i++) {
			d[i] = 10000;
			v[i] = 1;
		}
		d[begin_index] = 0;

		int cnt = 0;

		do {
			if (cnt > (n * n))
				return false;

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
			cnt++;
		} while (minindex < 10000);

		ver = new int[n + 1];
		int end = _end;
		ver[0] = end;
		k = 1;
		int weight = d[end];

		cnt = 0;

		while (end != begin_index) {
			if (cnt > (n * n))
				return false;
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
			cnt++;
		}

		ver[k] = -1;
		results.push_back(ver);
		dist.push_back(d);

		cout << "Кратчайший путь из " << _start << " в " << _end << " (общий вес: " << d[_end] << "): ";
		for (int i = k - 1; i >= 0; i--)
			cout << ver[i] << " ";
		cout << endl;
		delete[] v;
		return true;
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
		delete[] d;
		delete[] ver;
	}

	void Set(Graph<Vertex, Edge>* g, int i) {
		this->g = g;
		init_mass();
		solveTask(i);
	}

	void Restart(int i) {
		solveTask(i);
	}

	void Result() {
		if (results.size() == 0) {
			cout << "Результатов задачи нет" << endl;
			return;
		}
		int n = g->getVertexCount();
		for (int i = 0; i < results.size(); i++) {
			int* buf = new int[n + 1];
			int* d = new int[n];
			d = dist[i];
			buf = results[i];
			int k = 0;
			for (; buf[k] != -1; ++k);
			cout << "Кратчайший путь из " << buf[k - 1] << " в " << buf[0] << " (общий вес: " << d[buf[0]] << "): ";
			for (int j = k - 1; j >= 0; j--)
				cout << buf[j] << ' ';
			cout << endl;
		}
	}
};