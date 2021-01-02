#pragma once
#include "Graph.h"
#define MAX_INT 2147483647

template <class Vertex, class Edge>
class Task2 {
	Graph<Vertex, Edge>* g;
	vector<int*> results;
	int* way;
	
	struct VertexSimply {
		int vertex;
		int parrent;
		int w;
		bool state;
		VertexSimply(int vertex, int parrent, int w) {
			this->vertex = vertex;
			this->parrent = parrent;
			this->state = true;
			this->w = w;
		}
		VertexSimply(int vertex) {
			this->vertex = vertex;
			this->w = MAX_INT;
			this->state = false;
		}
	};

	class stack {
		struct Node {
			VertexSimply* v;
			Node* next;
			Node() {
				v = NULL;
				next = NULL;
			}
			Node(VertexSimply* v, Node* next) {
				this->v = v;
				this->next = next;
			}
		};
		Node* top;
	public:
		stack() {
			top = NULL;
		}
		void push(VertexSimply* t) {
			Node* current = new Node(t, top);
			top = current;
		}
		VertexSimply* pop() {
			if (top != NULL) {
				VertexSimply* v = top->v;
				Node* current = top;
				top = top->next;
				delete current;
				return v;
			}
			else {
				return NULL;
			}
		}
		bool state() {
			if (top != NULL)
				return true;
			else
				return false;
		}
	};

	void Route(int v1) {
		int n = g->getVertexCount();
		way = new int[n];
		VertexSimply** v;
		v = new VertexSimply* [n];
		for (int i = 0; i < n; i++)
			v[i] = new VertexSimply(i);
		int curr_v = v1;
		int son_v = 0;
		stack st;
		v[curr_v]->w = 0;
		v[curr_v]->parrent = -1;
		st.push(v[curr_v]);
		while (st.state()) {
			v[n] = st.pop();
			v[n]->state = true;
			curr_v = v[n]->vertex;
			typename Graph<Vertex, Edge>::OutputEdgeIterator Iterator(g, curr_v);
			try {
				Edge* Ed = *Iterator;
				while (Ed != NULL) {
					int w = Ed->getWeight();
					if (g->getIndex(Ed->v1) == curr_v)
						son_v = g->getIndex(Ed->v2);
					else
						son_v = g->getIndex(Ed->v1);
					if (v[son_v]->w > (v[curr_v]->w + w)) {
						v[son_v]->w = v[curr_v]->w + w;
						v[son_v]->parrent = curr_v;
					}
					if (!v[son_v]->state)
						st.push(v[son_v]);
					++Iterator;
					Ed = *Iterator;
				}
			}
			catch(...) {}
		}
		for (int i = 0; i < n; i++) {
			if (i != v1) {
				cout << "Кратчайший путь из " << v1 << " в " << i << ": ";
				int j = 0;
				way = new int[n];
				way[j] = i;
				int v2 = v[i]->vertex;
				while (v2 != v1) {
					j++;
					v2 = v[v2]->parrent;
					way[j] = v2;
				}
				way[j + 1] = -1;
				results.push_back(way);
				cout << way[j];
				while (j != 0) {
					j--;
					cout << "->" << way[j];
				}
				cout << endl;
			}
		}
		for (int i = 0; i < n; i++)
			delete v[i];
	}


public:
	Task2(Graph<Vertex, Edge>* g) {
		this->g = g;
		for (int i = 0; i < g->getVertexCount(); i++) {
			Route(i);
		}
	}
	Task2(Task2& T) {}

	~Task2() {
		delete[] way;
	}

	void Set(Graph<Vertex, Edge>* g) {
		this->g = g;
		for (int i = 0; i < g->getVertexCount(); i++) {
			Route(i);
		}
	}

	void Restart() {
		for (int i = 0; i < g->getVertexCount(); i++)
			Route(i);
	}

	void Result() {
		int n = g->getVertexCount();
		for (int i = 0; i < results.size(); i++) {
			int* buf = new int[n];
			buf = results[i];
			int k = 0;
			for (; buf[k] != -1; ++k);
			cout << "Кратчайший путь из " << buf[k - 1] << " в " << buf[0] << ": ";
			cout << buf[k - 1];
			for (int j = k - 2; j >= 0; j--) {
				cout << "->" << buf[j];
			}
			cout << endl;
		}
	}
};