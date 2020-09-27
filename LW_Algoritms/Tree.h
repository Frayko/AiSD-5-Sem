#pragma once
#include <iostream>
#include "listErrors.h"

using namespace std;

template <class Key = int, class Data = int>
class Tree {
private:

	template <class Key = int, class Data = int>
	class Elem {
	public:
		Key key;
		Data obj;
		Elem* l, r;

		Elem(Key key = Key(), Data obj = Data(), Elem* l = nullptr, Elem* r = nullptr) : key(key), obj(obj), l(l), r(r) {}
		//Elem(Elem<Key, Data>& other) : key(other.key), obj(other.obj), l(other.l), r(other.r) {}
	};

	int count;
	Elem<Key, Data>* head;

public:
	Tree();
	Tree(Tree& t);
	void push(Data _obj, Key _key, Tree<Key, Data>& t);
	bool pop(Key _key, Tree<Key, Data>& t);
	Elem<Key, Data> find_max_min(Tree<Key, Data>::Elem<Key, Data>& t);
	Data get_obj(Key _key, Tree<Key, Data>& t);
	bool set_obj(Data _obj, Key _key, Tree<Key, Data>& t);
	bool isEmpty();
	void clear();
	int get_size();
	void print();
	int get_serial_number(Key _key);

	class Iterator {

	};

	class rIterator {

	};

	friend class Iterator;
	friend class rIterator;

	Iterator begin();
	Iterator end();

	rIterator rbegin();
	rIterator rend();
};

template <class Key, class Data>
Tree<Key, Data>::Tree() {
	count = 0;
	head = new Elem();
}

template <class Key, class Data>
Tree<Key, Data>::Tree(Tree<Key, Data>& t) {
	count = t.count;
	head = t.head;
}

template <class Key, class Data>
void Tree<Key, Data>::push(Data _obj, Key _key, Tree<Key, Data>& t) {
	Elem<Key, Data>* tmp = new Elem<Key, Data>(_obj, _key);

	if (head == nullptr || head->obj == NULL) {
		head = tmp;
	}
	else {
		Elem<Key, Data>* tree = head;
		if (tree->key > _key)
			push(_obj, _key, tree->l);
		else
			push(_obj, _key, tree->r);
	}


}

//template <class Key, class Data>
//bool Tree<Key, Data>::pop(Key _key, Tree<Key, Data>& t) {
//	if (head == nullptr || head->obj == NULL)
//		throw TreeDelErr();
//
//	Elem<Key, Data>* tree = head;
//	if (tree->key == _key) {
//		if (tree->r != nullptr) {
//			tree->key = tree->r->key;
//			tree->obj = tree->r->obj;
//			//tree->r = tree->
//		}
//	}
//	if else (tree->key > _key)
//		pop(_key, tree);
//}
//
//template <class Key, class Data>
//Tree<Key, Data>::Elem<Key, Data> Tree<Key, Data>::find_max_min(Tree<Key, Data>::Elem<Key, Data>& t) {
//	if (t.r == nullptr && t.l != nullptr) {
//		Elem<Key, Data>* temp = t;
//		t = t.l;
//		return temp;
//	}
//	else if (t.r == nullptr && t.l == nullptr) {
//		Elem<Key, Data>* temp = t;
//		t = nullptr;
//		return temp;
//	}
//	else
//		find_max_min(t.r);
//}