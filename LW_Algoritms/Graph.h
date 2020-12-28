#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "GraphForm.h"
#include <stdio.h>

string i_to_s(int x) {
	char buffer[20];
	_itoa(x, buffer, 10);
	string s = buffer;
	return s;
}

template <class VertexT, class EdgeT>
class Graph {
	friend class VertexIterator;
	vector<VertexT*> vertexVector;	//������ �����������
	GraphForm<EdgeT> *data;			//������ �����
	bool directed;					//������������ ����
	bool dense;						//�-����
	int edgeCounter;				//����� ����
	int sz = 0;						//����� ������
	//��������� ������� ������� �� �����������
	int getIndexFromName(string n) {
		int index = 0;
		for (int i = 0; i < vertexVector.size(); ++i) {
			if (vertexVector[index]->getName() == n)
				break;
			++index;
		}
		if (index == vertexVector.size())
			throw "������ ������� ��� � �����";
		return index;
	};

public:
	//������������:
	//������ L ����
	Graph() {
		data = new LGraph<EdgeT>(false);
		directed = false;
		dense = false;
		edgeCounter = 0;
		sz = 0;
	}
	//������ ���-�� ������, ��������������, �����
	Graph(int vertexCount, bool directed, bool dense) {
		if (dense)
			data = new MGraph<EdgeT>(directed);
		else
			data = new LGraph<EdgeT>(directed);
		//������ ������� � �������� � ���������
		for (int i = 0; i < vertexCount; ++i)
			data->insertVertex(i);
		for (int i = 0; i < vertexCount; ++i) {
			VertexT *v = new VertexT();
			v->setName(i_to_s(sz));
			sz++;
			vertexVector.push_back(v);
			data->insertVertex(i);
		}
		this->directed = directed;
		this->dense = dense;
		edgeCounter = 0;
		sz = 0;
	}
	//+ ������ �� ���������� ������
	Graph(int vertexCount, int edgeCount, bool directed, bool dense) {
		if (dense)
			data = new MGraph<EdgeT>(directed);
		else
			data = new LGraph<EdgeT>(directed);
		//������ ������� � �������� � ���������
		for (int i = 0; i < vertexCount; ++i)
			data->insertVertex(i);
		for (int i = 0; i < vertexCount; ++i) {
			VertexT *v = new VertexT();
			v->setName(i_to_s(sz));
			sz++;
			vertexVector.push_back(v);
			data->insertVertex(i);
		}
		this->directed = directed;
		this->dense = dense;
		edgeCounter = 0;

		//��������� ����
		if (edgeCount <= 0) return;
		//������������ ����� ����, ����� �� ��������� ���������
		if (directed) {
			if (edgeCount > vertexCount * (vertexCount - 1))
				edgeCount = vertexCount * (vertexCount - 1);
			
		}
		else {
			if (edgeCount > (vertexCount * (vertexCount - 1)) / 2)
				edgeCount = (vertexCount * (vertexCount - 1)) / 2;
		}
		//���������
		int v1, v2;
		srand(time(0));
		while (edgeCounter < edgeCount) {
			v1 = rand() % vertexCount;
			v2 = rand() % vertexCount;
			if (v1 == v2)
				continue;
			if (data->hasEdge(v1, v2))
				continue;

			EdgeT *t = new EdgeT(vertexVector[v1], vertexVector[v2]);
			data->insertEdge(v1, v2, t);
			int z = rand() % 9 + 1;
			t->setWeight(z);
			if (directed == false) {
				t = new EdgeT(vertexVector[v2], vertexVector[v1]);
				t->setWeight(z);
				data->insertEdge(v2, v1, t);
			}
			++edgeCounter;
		}
	}
	Graph(const Graph<VertexT, EdgeT> &G) {
		delete data;
		if (G.isDense())
			data = new MGraph<EdgeT>(*(G.data));
		else
			data = new LGraph<EdgeT>(*(G.data));
		directed = G.directed;
		dense = G.dense;
	}
	~Graph() {
		while (vertexVector.size() != 0)
			deleteVertex(vertexVector.size() - 1);
		delete data;
	}

	//���������� � �����
	//����� ������, ����, ������������
	int getVertexCount() {
		return vertexVector.size();
	}
	int getEdgeCount() {
		return edgeCounter;
	}
	double getRatio() {
		int max = vertexVector.size() * (vertexVector.size() - 1);
		if (!directed)
			max /= 2;
		return (double)edgeCounter / (double)max;
	}
	bool isDirected() {
		return directed;
	}
	bool isDense() {
		return dense;
	}

	//��������������
	void toDenseGraph() {
		//������ ��������� �������� �-�����
		GraphForm<EdgeT> *newData = new MGraph<EdgeT>(this->directed);

		//������ �������
		for (int i = 0; i < vertexVector.size(); ++i)
			newData->insertVertex(i);

		//��������� ����
		for (int i = 0; i < vertexVector.size(); ++i)
			for (int j = 0; j < vertexVector.size(); ++j)
				if (data->hasEdge(i, j))
					newData->insertEdge(i, j, data->getEdge(i, j));
		delete data;
		data = newData;
		dense = true;
	}
	void toSparseGraph() {
		//������ ��������� �������� L-�����
		GraphForm<EdgeT> *newData = new LGraph<EdgeT>(this->directed);

		//������ �������
		for (int i = 0; i < vertexVector.size(); ++i)
			newData->insertVertex(i);

		//��������� ����
		for (int i = 0; i < vertexVector.size(); ++i)
			for (int j = 0; j < vertexVector.size(); ++j)
				if (data->hasEdge(i, j))
					newData->insertEdge(i, j, data->getEdge(i, j));
		delete data;
		data = newData;
		dense = false;
	}

	//������
	//�������
	VertexT* insertVertex() {
		VertexT *v = new VertexT;
		if (data->insertVertex(vertexVector.size()) == false)
			throw 1;
		v->setName(i_to_s(sz));
		v->index = sz++;
		vertexVector.push_back(v);
		return v;
	}
	bool deleteVertex(VertexT *v) {
		int index = getIndex(v);
		edgeCounter -= data->deleteEdgesFromVertex(index, directed);
		if (data->deleteVertex(index)) {
			cout << vertexVector.size() << " ";
			vertexVector.erase(vertexVector.begin() + index);
			cout << vertexVector.size() << "\n";
			for (int i = v->index; i < vertexVector.size(); i++) {
				vertexVector[i]->index = i;	
			}
			return true;
		}
		return false;
	}
	bool deleteVertex(string n) {
		VertexT *v = new VertexT;
		bool rez;
		try {
			v = getVertexFromName(n);
		}
		catch (...) {
			return false;
		}
		rez = deleteVertex(v);
		return rez;
	}
	VertexT* getVertex(int index) {
		if (index < 0 || index >= vertexVector.size())
			throw exception("������ ������� ��� � �����");
		return vertexVector[index];
	}
	VertexT* getVertexFromName(string n) {
		int i;
		for (i = 0; i < vertexVector.size(); i++)
			if (vertexVector[i]->getName() == n)
				return vertexVector[i];
		if (i == vertexVector.size())
			throw exception("������ ������� ��� � �����");
	};
	int getIndex(VertexT *v) {
		int index = 0;
		for (int i = 0; i < vertexVector.size(); ++i) {
			if (vertexVector[index] == v)
				break;
			++index;
		}
		if (index == vertexVector.size())
			throw "������ ������� ��� � �����";
		return index;
	};
	vector<VertexT*> getVector() {
		vector<VertexT*> temp = vertexVector;
		return temp;
	};

	//и���
	void insertEdge(string v1, string v2) {
		VertexT* _v1 = new VertexT;
		VertexT* _v2 = new VertexT;
		try {
			_v1 = getVertexFromName(v1);
		}
		catch (const char*) {
			throw "�������� ��� 1 �������";
		};
		try {
			_v2 = getVertexFromName(v2);
		}
		catch (const char*) {
			throw "�������� ��� 2 �������";
		}
		try {
			insertEdge(_v1, _v2);
		}
		catch (const char*) {
			throw "����� �����������, ��� ����� ��� ����";
		}
		return;
	};
	EdgeT* insertEdge(VertexT *v1, VertexT *v2) {
		EdgeT *e = new EdgeT(v1, v2);
		if (!data->insertEdge(getIndex(v1), getIndex(v2), e))
			throw "����� �����������, ��� ����� ��� ����";
		if (directed == false)
			data->insertEdge(getIndex(v2), getIndex(v1), e);
		++edgeCounter;
		return e;
	}
	bool deleteEdge(string v1, string v2) {
		VertexT* _v1 = new VertexT;
		VertexT* _v2 = new VertexT;
		try {
			_v1 = getVertexFromName(v1);
		}
		catch (const char*) {
			throw "�������� ����� 1 ������";
		};
		try {
			_v2 = getVertexFromName(v2);
		}
		catch (const char*) {
			throw "�������� ����� 2 �������";
		}
		if (!deleteEdge(_v1, _v2))
			return false;

		return true;
	};
	bool deleteEdge(VertexT *v1, VertexT *v2) {
		if (data->deleteEdge(getIndex(v1), getIndex(v2))) {
			--edgeCounter;
			if (directed == false)
				data->deleteEdge(getIndex(v2), getIndex(v1));
			return true;
		}
		else
			return false;
	}
	bool hasEdge(VertexT *v1, VertexT *v2) {
		int ind1, ind2;
		try {
			ind1 = getIndex(v1);
		}
		catch (int &a) {
			return false;
		}
		try {
			ind2 = getIndex(v2);
		}
		catch (int &a)
		{
			return false;
		}
		return data->hasEdge(getIndex(v1), getIndex(v2));
	}
	bool hasEdge(int v1, int v2) {
		if (v1 < 0 || v1 >= vertexVector.size())
			return false;
		if (v2 < 0 || v2 >= vertexVector.size())
			return false;
		return data->hasEdge(v1, v2);
	}
	EdgeT* getEdge(VertexT *v1, VertexT *v2) {
		EdgeT* e;
		try {
			e = data->getEdge(getIndex(v1), getIndex(v2));
		}
		catch (int) {
			throw "������ ������";
		}
		return e;
	}
	EdgeT* getEdge(int v1, int v2) {
		EdgeT* e;
		try {
			e = data->getEdge(v1, v2);
		}
		catch (int) {
			throw "������ ������";
		}
		return e;
	}
	bool write_data_edge(string _v1, string _v2, int data) {
		EdgeT* e;
		VertexT *v1, *v2;
		try {
			v1 = getVertexFromName(_v1);
		}
		catch (const char*) {
			return false;
		}
		try {
			v2 = getVertexFromName(_v2);
		}
		catch (const char*) {
			return false;
		}
		e = getEdge(v1, v2);
		e->setData(data);
		return true;
	};
	bool write_weight_edge(string _v1, string _v2, int w) {
		EdgeT* e;
		VertexT *v1, *v2;
		try {
			v1 = getVertexFromName(_v1);
		}
		catch (const char*) {
			return false;
		}
		try {
			v2 = getVertexFromName(_v2);
		}
		catch (const char*) {
			return false;
		}
		e = getEdge(v1, v2);
		e->setWeight(w);
		if (!directed) {
			e = getEdge(v2, v1);
			e->setWeight(w);
		}
		return true;
	};
	int read_data_edge(string _v1, string _v2) {
		EdgeT* e;
		VertexT *v1, *v2;
		try {
			v1 = getVertexFromName(_v1);
		}
		catch (const char*) {
			throw "������ ������";
		}
		try {
			v2 = getVertexFromName(_v2);
		}
		catch (const char*) {
			throw "������ ������";
		}
		e = getEdge(v1, v2);
		if (e->isDataSet())
			return e->getData();
		else
			throw "�����";
	};
	int read_weight_edge(string _v1, string _v2) {
		EdgeT* e;
		VertexT *v1, *v2;
		try {
			v1 = getVertexFromName(_v1);
		}
		catch (...) {
			throw "������ ������ �� �����";
		}
		try {
			v2 = getVertexFromName(_v2);
		}
		catch (...) {
			throw "������ ������ �� �����";
		}
		e = getEdge(v1, v2);
		if (e->isWeightSet())
			return e->getWeight();
		else
			throw "�����";
	};

	void print_graph() {
		int i, j;
		VertexT* v, *v2;
		EdgeT* e;
		if (isDense()) {
			cout << "  |";
			for (i = 0; i < getVertexCount(); i++) {
				v = getVertex(i);
				cout << setw(4) << v->getName();
			}
			cout << endl << "--|-";
			for (i = 0; i < getVertexCount(); i++)
				cout << "----";
			cout << endl;
			for (i = 0; i < getVertexCount(); i++) {
				v = getVertex(i);
				cout << setw(2) << v->getName() << setw(0) << "|";
				for (j = 0; j < getVertexCount(); j++)
					if (hasEdge(i, j)) {
						e = getEdge(getVertex(i), getVertex(j));
						cout << setw(4) << "1";
					}
					else
						cout << setw(4) << "0";
				cout << endl;
			}
		}
		else
		{
			LGraph<EdgeT>* form = static_cast<LGraph<EdgeT>*>(data);

			for (int i = 0; i < getVertexCount(); i++) {
				v = getVertex(i);
				cout << "*" << v->getName() << " - ";
				list<typename LGraph<EdgeT>::Node> l = form->edgeList[i];
				for (typename list<typename LGraph<EdgeT>::Node>::iterator it = l.begin(); it != l.end(); it++) {
					if ((*it).edge != NULL) {
						cout << getVertex((*it).v2)->getName() << ", ";
					}
				}
				cout << endl;
			}
		}
	};
	int read_data_vertex(string v1) {
		VertexT *v;
		try
		{
			v = getVertexFromName(v1);
		}
		catch (...) {
			throw "������ ������ �� �����";
		};
		int d;
		d = v->getData();
		if (v->dataSet != false)
			return d;
		else
			throw "�����";
	};
	bool write_data_vertex(string v1, int d) {
		VertexT *v;
		try
		{
			v = getVertexFromName(v1);
		}
		catch (const char*) {
			return false;
		};
		v->setData(d);
		return true;
	};
	bool write_name_vertex(int v1, string str) {
		VertexT *v;
		try
		{
			v = getVertex(v1);
		}
		catch (const char*) {
			return false;
		};
		v->setName(str);
		return true;
	};

	//��������� ������
	//�������� ������
	class VertexIterator {
		Graph<VertexT, EdgeT>* graph; //�������������� ����
		bool end;
		int current;
	public:
		VertexIterator(Graph<VertexT, EdgeT> &g) {
			graph = &g;
			begin();
		};
		//��������� � ������
		void begin() {
			if (graph->vertexVector.size() == 0) {
				end = true;
				throw exception("���������� ������ = 0");
			}
			current = 0;
			end = false;
		};
		//����� �� ��������� �������
		void operator++() {
			if (graph->vertexVector.size() == 0) {
				end = true;
				throw exception("���������� ������ = 0");
			}
			if (end) {
				current = -1;
				return;
			}
			current++;
			if (graph->vertexVector.size() - 1 == current)
				end = true;
			return;
		};
		void toend() {
			if (graph->vertexVector.size() == 0) {
				end = true;
				throw exception("���������� ������ = 0");
			}
			current = graph->vertexVector.size() - 1;
			end = true;
		};
		//�������� �� �����
		bool onEnd() {
			return end;
		};
		//��������� �������
		VertexT* operator*() {
			if (current >= graph->vertexVector.size() || current == -1)
				throw 1;
			return graph->vertexVector[current];
		};
		string read_vertex() {
			VertexT *v;
			try
			{
				v = operator*();
			}
			catch (int) {
				throw "������ ������ �������";
			};
			string d;
			d = v->getName();
			if (v->nameSet != false)
				return d;
			else
				throw "�����";
		};
		int read_data_vertex() {
			VertexT *v;
			try
			{
				v = operator*();
			}
			catch (int) {
				throw "������ ������ ������";
			};
			int d;
			d = v->getData();
			if (v->dataSet != false)
				return d;
			else
				throw "�����";
		};
		void write_data_vertex(int d) {
			VertexT *v;
			try
			{
				v = operator*();
			}
			catch (int) {
				throw "������ ������ �������";
			};
			v->setData(d);
			return;
		};
		void write_name_vertex(string str) {
			VertexT *v;
			try
			{
				v = operator*();
			}
			catch (int) {
				throw "������ ������ �������";
			};
			v->setName(str);
			return;
		};

	};

	//�������� ����
	class EdgeIterator {
		Graph<VertexT, EdgeT> *graph; //�������������� ����
		typename MGraph<EdgeT>::EdgeIterator *mIt;
		typename LGraph<EdgeT>::EdgeIterator *lIt;
		bool useM;
	public:
		int curV1, curV2;
		bool end;
		EdgeIterator(Graph<VertexT, EdgeT> &g) {
			graph = &g;
			if (graph->isDense()) {
				mIt =  new typename MGraph<EdgeT>::EdgeIterator(static_cast<MGraph<EdgeT>*>(g.data));
				useM = true;
			}
			else {
				lIt = new typename LGraph<EdgeT>::EdgeIterator(static_cast<LGraph<EdgeT>*>(g.data));
				useM = false;
			}
			begin();
		}
		//��������� � ������
		bool begin() {
			if (useM) return
				mIt->begin();
			else
				return lIt->begin();
		}
		//����� �� ��������� �������
		bool operator++() {
			if (useM)
				return mIt->next();
			else
				return lIt->next();
		}
		//�������� �� �����
		bool onEnd() {
			//return end;
			if (useM)
				return mIt->onEnd();
			else
				return lIt->onEnd();
		}
		bool toend() {
			if (useM)
				return mIt->toend();
			else
				return lIt->toend();
		}
		//��������� �����
		EdgeT* operator*() {
			if (onEnd())
				throw "�����";
			if (useM)
				return mIt->getEdge();
			else
				return lIt->getEdge();
		}
		string read_edge() {
			EdgeT* e;
			try {
				e = operator*();
			}
			catch (const char*) {
				throw "������ ������ �����";
			}
			VertexT *_v1, *_v2;
			int w;
			string str1, str2, str3, str4;
			_v1 = e->getVertex1();
			_v2 = e->getVertex2();
			if (_v1->nameSet == false)
				str1 = "Null";
			else
				str1 = _v1->getName();
			if (_v2->nameSet == false)
				str2 = "Null";
			else
				str2 = _v2->getName();
			if (e->isWeightSet() == false)
				str3 = "Null";
			else
				str3 = i_to_s(e->getWeight());
			str4 = "��������� �������: " + str1 + ". �������� �������: " + str2 + ". ��� �����: " + str3;
			return str4;
		}
		int read_data_edge() {
			EdgeT* e;
			try {
				e = operator*();
			}
			catch (const char* Error) {
				throw "������ ������ �����";
			}
			int a;
			if (e->isDataSet())
				return e->getData();
			else
				throw "�����";
		};
		bool write_data_edge(int d) {
			EdgeT* e;
			try {
				e = operator*();
			}
			catch (const char*) {
				return false;
			}
			e->setData(d);
			return true;
		};
		bool write_weight_edge(int w) {
			EdgeT* e;
			try {
				e = operator*();
			}
			catch (const char*) {
				return false;
			}
			e->setWeight(w);
			return true;
		}
	};

	//�������� ��������� ����
	class OutputEdgeIterator {
		Graph<VertexT, EdgeT> *graph; //�������������� ����
		typename MGraph<EdgeT>::OutputEdgeIterator *mIt;
		typename LGraph<EdgeT>::OutputEdgeIterator *lIt;
		bool useM;
	public:
		int curV1, curV2;
		bool end;
		OutputEdgeIterator(Graph<VertexT, EdgeT> &g, VertexT &v) {
			graph = &g;
			curV1 = graph->getIndex(&v);
			if (graph->isDense()) {
				mIt = new typename MGraph<EdgeT>::OutputEdgeIterator(static_cast<MGraph<EdgeT>*>(g.data), curV1);
				useM = true;
			}
			else {
				lIt = new typename LGraph<EdgeT>::OutputEdgeIterator(static_cast<LGraph<EdgeT>*>(g.data), curV1);
				useM = false;
			}
			begin();
		}
		OutputEdgeIterator(Graph<VertexT, EdgeT>* g, int v1) {
			graph = g;
			curV1 = v1;
			if (graph->isDense()) {
				mIt = new typename MGraph<EdgeT>::OutputEdgeIterator(static_cast<MGraph<EdgeT>*>(g->data), curV1);
				useM = true;
			}
			else {
				lIt = new typename LGraph<EdgeT>::OutputEdgeIterator(static_cast<LGraph<EdgeT>*>(g->data), curV1);
				useM = false;
			}
			begin();
		}
		//��������� � ������
		bool begin() {
			if (useM)
				return mIt->begin();
			else
				return lIt->begin();
		}
		//����� �� ��������� �������
		bool operator++() {
			if (useM)
				return mIt->next();
			else
				return lIt->next();
		}
		bool toend() {
			if (useM)
				return mIt->toend();
			else
				return lIt->toend();
		}
		//�������� �� �����
		bool onEnd() {
			if (useM)
				return mIt->onEnd();
			else
				return lIt->onEnd();
		}
		//��������� �����
		EdgeT* operator*() {
			if (onEnd()) {
				//return NULL;
				throw "������ ������ �����";
			}
			if (useM)
				return mIt->getEdge();
			else
				return lIt->getEdge();
		}
		string read_edge() {
			EdgeT* e;
			try {
				e = operator*();
			}
			catch (const char*) {
				throw "������ ������ �����";
			}
			VertexT *_v1, *_v2;
			int w;
			string str1, str2, str3, str4;
			_v1 = e->getVertex1();
			_v2 = e->getVertex2();
			if (_v1->nameSet == false)
				str1 = "Null";
			else
				str1 = _v1->getName();
			if (_v2->nameSet == false)
				str2 = "Null";
			else
				str2 = _v2->getName();
			if (e->isWeightSet() == false)
				str3 = "Null";
			else
				str3 = i_to_s(e->getWeight());
			str4 = "��������� �������: " + str1 + ". �������� �������: " + str2 + ". ��� �����: " + str3;
			return str4;
		}
		int read_data_edge() {
			EdgeT* e;
			try {
				e = operator*();
				return e->getData();
			}
			catch (...) {
				cout << "������ ������ �����";
			}
			
		};
		bool write_data_edge(int d) {
			EdgeT* e;
			try {
				e = operator*();
			}
			catch (const char*) {
				return false;
			}
			e->setData(d);
			return true;
		};
		bool write_weight_edge(int w) {
			EdgeT* e;
			try {
				e = operator*();
			}
			catch (...) {
				return false;
			}
			e->setWeight(w);
			return true;
		}
	};
};