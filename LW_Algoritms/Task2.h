#pragma once
#include "Graph.h"
#define MAX_INT 2147483647

template <class Vertex, class Edge>
class Task2 {
	Graph<Vertex, Edge>* g;
	
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

	int way[200];

	void Route(int v1) {
		VertexSimply* v[200];
		for (int i = 0; i < g->getVertexCount(); i++)
			v[i] = new VertexSimply(i);
		int curr_v = v1;
		int son_v = 0;
		stack st;
		v[curr_v]->w = 0;
		v[curr_v]->parrent = -1;
		st.push(v[curr_v]);
		while (st.state()) {
			v[g->getVertexCount()] = st.pop();
			v[g->getVertexCount()]->state = true;
			curr_v = v[g->getVertexCount()]->vertex;
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
		for (int i = 0; i < g->getVertexCount(); i++) {
			if (i != v1) {
				cout << "Кратчайший путь из " << v1 << " в " << i << ": ";
				int j = 0;
				way[j] = i;
				int v2 = v[i]->vertex;
				while (v2 != v1) {
					j++;
					v2 = v[v2]->parrent;
					way[j] = v2;
				}
				way[j + 1] = -1;
				cout << way[j];
				while (j != 0) {
					j--;
					cout << "->" << way[j];
				}
				cout << endl;
			}
		}
		for (int i = 0; i < g->getVertexCount(); i++)
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

	~Task2() {}

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
		for (int i = 0; i < g->getVertexCount(); i++) {
			Route(i);
		}
	}
};