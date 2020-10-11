#pragma once
#include <iostream>
#include "listErrors.h"

using namespace std;

template <class Key = int, class Data = int>
class Tree {
private:

	class Node {
	private:
		Key key;
		Data data;
		Node *left, *right;

	public:
		Node(Key key = Key(), Data data = Data(), Node* left = nullptr, Node* right = nullptr) : key(key), data(data), left(left), right(right) {}

		Key getKey();
		void setKey(Key key);
		Data getData();
		void setData(Data data);
		Node* getLeft();
		void setLeft(Node* left);
		Node* getRight();
		void setRight(Node* right);
	};

	int size;
	Node* root;

	void clear(Node* node);
	bool insert(Key key, Data data, Node* parent, Node* cur);
	Node* getNode(Key key, Node* cur);
	bool remove(Key key, Node* cur);

public:
	Tree();
	Tree(Tree& t);
	~Tree();

	void clear();
	Node* getRoot();
	int getSize();
	bool isEmpty();
	bool insert(Key key, Data data);
	bool remove(Key key);
	Node* getNode(Key key);
	Data getData(Key key);
	bool setData(Key key, Data data);
	void print();
	int getSerialNumber(Key key);

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


//-------------------Node---------------------//

template <class Key, class Data>
Key Tree<Key, Data>::Node::getKey() {
	return key;
}

template <class Key, class Data>
void Tree<Key, Data>::Node::setKey(Key key) {
	this->key = key;
}

template <class Key, class Data>
Data Tree<Key, Data>::Node::getData() {
	return data;
}

template <class Key, class Data>
void Tree<Key, Data>::Node::setData(Data data) {
	this->data = data;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* Tree<Key, Data>::Node::getLeft() {
	return left;
}

template <class Key, class Data>
void Tree<Key, Data>::Node::setLeft(Node* left) {
	this->left = left;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* Tree<Key, Data>::Node::getRight() {
	return right;
}

template <class Key, class Data>
void Tree<Key, Data>::Node::setRight(Node* right) {
	this->right = right;
}

//-------------------Tree---------------------//

template <class Key, class Data>
Tree<Key, Data>::Tree() {
	size = 0;
	root = nullptr;
}

template <class Key, class Data>
Tree<Key, Data>::Tree(Tree<Key, Data>& t) {
	//TODO
}

template <class Key, class Data>
Tree<Key, Data>::~Tree() {
	if (this->isEmpty())
		this->clear();
}

template <class Key, class Data>
void Tree<Key, Data>::clear(Node* node) {
	if (node) {
		this->clear(node->getLeft());
		this->clear(node->getRight());
		delete node;
		this->size--;
	}
}

template <class Key, class Data>
void Tree<Key, Data>::clear() {
	this->clear(this->root);
	this->root = nullptr;
	size = 0;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* Tree<Key, Data>::getRoot() {
	return root;
}

template <class Key, class Data>
int Tree<Key, Data>::getSize() {
	return this->size;
}

template <class Key, class Data>
bool Tree<Key, Data>::isEmpty() {
	return this->size == 0;
}

template <class Key, class Data>
bool Tree<Key, Data>::insert(Key key, Data data) {

	if (!root)
		root = new Node(key, data);
	else {
		if (root->getKey() > key)
			insert(key, data, root, root->getLeft());
		else if (root->getKey() < key)
			insert(key, data, root, root->getRight());
		else
			return false;
	}

	this->size++;
	return true;
}

template <class Key, class Data>
bool Tree<Key, Data>::insert(Key key, Data data, Tree<Key, Data>::Node* parent, Tree<Key, Data>::Node* cur) {
	if (!cur) {
		cur = new Node(key, data);
		if (parent->getKey() > key)
			parent->setLeft(cur);
		else
			parent->setRight(cur);
	}

	else {
		if (cur->getKey() > key)
			insert(key, data, cur, cur->getLeft());
		else if (cur->getKey() < key)
			insert(key, data, cur, cur->getRight());
		else
			return false;
	}

	return true;
}

template <class Key, class Data>
bool Tree<Key, Data>::remove(Key key) {
	try {

	}
	catch (TreeError& te) {
		te.ErrMsg();
		return false;
	}
}

template <class Key, class Data>
bool Tree<Key, Data>::remove(Key key, Node* node) {
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* Tree<Key, Data>::getNode(Key key) {
	if (!root)
		throw TreeIsEmpty();
	Node* node = nullptr;

	if (root->getKey() == key)
		node = this->root;
	else if (root->getKey() > key)
		node = getNode(key, root->getLeft());
	else
		node = getNode(key, root->getRight());

	if (!node)
		throw TreeFindErr();

	return node;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* Tree<Key, Data>::getNode(Key key, Node* node) {
	if (!node)
		return node;

	if (node->getKey() == key)
		return node;
	else if (node->getKey() > key)
		node = getNode(key, node->getLeft());
	else
		node = getNode(key, node->getRight());
}

template <class Key, class Data>
Data Tree<Key, Data>::getData(Key key) {
	Node* node = getNode(key);
	return node->getData();
}

template <class Key, class Data>
bool Tree<Key, Data>::setData(Key key, Data data) {
	try {
		Node* node = getNode(key);
		node->setData(data);
		return true;
	}
	catch (TreeError& te) {
		te.ErrMsg();
		return false;
	}
}

//--------------------------------------------//
