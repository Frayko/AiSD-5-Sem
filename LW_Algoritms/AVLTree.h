#pragma once
#include <iostream>
#include "Tree.h"

using namespace std;

template <class Key = int, class Data = int>
class AVLTree : public Tree<Key, Data> {
private:
	int getHeight(typename Tree<Key, Data>::Node* node);
	int bFactor(typename Tree<Key, Data>::Node* node);
	void fixHeight(typename Tree<Key, Data>::Node* node);
	typename Tree<Key, Data>::Node* balance(typename Tree<Key, Data>::Node* node);
	typename Tree<Key, Data>::Node* rotateLeft(typename Tree<Key, Data>::Node* node);
	typename Tree<Key, Data>::Node* rotateRight(typename Tree<Key, Data>::Node* node);

	typename Tree<Key, Data>::Node* insert(Key key, Data data, typename Tree<Key, Data>::Node* node, bool& flag);
	typename Tree<Key, Data>::Node* remove(Key key, typename Tree<Key, Data>::Node* node, bool& flag);
	typename Tree<Key, Data>::Node* removeMax(typename Tree<Key, Data>::Node* node);
	typename Tree<Key, Data>::Node* findMax(typename Tree<Key, Data>::Node* node);
	virtual void print(typename Tree<Key, Data>::Node* node, int lvl);

public:
	AVLTree();
	AVLTree(AVLTree<Key, Data>& t);
	~AVLTree();

	int getHeight();
	bool insert(Key key, Data data);
	bool remove(Key key);

	void print();
	void print(typename Tree<Key, Data>::Node* node, int lvl, typename Tree<Key, Data>::Iterator& iter);
	void print(typename Tree<Key, Data>::Node* node, int lvl, typename Tree<Key, Data>::rIterator& riter);
};

template <class Key, class Data>
AVLTree<Key, Data>::AVLTree() : Tree<Key, Data>::Tree() {}

template <class Key, class Data>
AVLTree<Key, Data>::AVLTree(AVLTree<Key, Data>& t) : Tree<Key, Data>::Tree(t) {}

template <class Key, class Data>
AVLTree<Key, Data>::~AVLTree() {
	Tree<Key, Data>::~Tree();
}

template <class Key, class Data>
int AVLTree<Key, Data>::getHeight(typename Tree<Key, Data>::Node* node) {
	return node ? node->height : 0;
}

template <class Key, class Data>
int AVLTree<Key, Data>::getHeight() {
	return this->root ? this->root->height : 0;
}

template <class Key, class Data>
int AVLTree<Key, Data>::bFactor(typename Tree<Key, Data>::Node* node) {
	return getHeight(node->right) - getHeight(node->left);
}

template <class Key, class Data>
void AVLTree<Key, Data>::fixHeight(typename Tree<Key, Data>::Node* node) {
	int hLeft = getHeight(node->left);
	int hRight = getHeight(node->right);
	node->height = (hLeft < hRight ? hRight : hLeft) + 1;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* AVLTree<Key, Data>::balance(typename Tree<Key, Data>::Node* node) {
	if (!node)
		return nullptr;

	fixHeight(node);

	if (bFactor(node) == 2) {
		if (bFactor(node->right) < 0)
			node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	if (bFactor(node) == -2) {
		if (bFactor(node->left) > 0)
			node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	return node;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* AVLTree<Key, Data>::rotateLeft(typename Tree<Key, Data>::Node* node) {
	typename Tree<Key, Data>::Node* tmp = node->right;
	node->right = tmp->left;
	node->countSubNode = (node->left ? node->left->countSubNode : 0) + (node->right ? node->right->countSubNode : 0) + 1;
	tmp->left = node;
	tmp->countSubNode = (tmp->left ? tmp->left->countSubNode : 0) + (tmp->right ? tmp->right->countSubNode : 0) + 1;
	fixHeight(node);
	fixHeight(tmp);
	return tmp;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* AVLTree<Key, Data>::rotateRight(typename Tree<Key, Data>::Node* node) {
	typename Tree<Key, Data>::Node* tmp = node->left;
	node->left = tmp->right;
	node->countSubNode = (node->left ? node->left->countSubNode : 0) + (node->right ? node->right->countSubNode : 0) + 1;
	tmp->right = node;
	tmp->countSubNode = (tmp->left ? tmp->left->countSubNode : 0) + (tmp->right ? tmp->right->countSubNode : 0) + 1;
	fixHeight(node);
	fixHeight(tmp);
	return tmp;
}

template <class Key, class Data>
bool AVLTree<Key, Data>::insert(Key key, Data data) {
	bool flag = false;

	this->root = insert(key, data, this->root, flag);

	if (!flag)
		return false;

	this->root = balance(this->root);

	this->size++;
	return true;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* AVLTree<Key, Data>::insert(Key key, Data data, typename Tree<Key, Data>::Node* node, bool& flag) {
	Tree<Key, Data>::incrementCOUNTER();

	if (!node) {
		flag = true;
		return new typename Tree<Key, Data>::Node(key, data);
	}

	if (node->key > key) {
		node->left = insert(key, data, node->left, flag);
		if (flag)
			node->countSubNode++;
	}
	else if (node->key < key) {
		node->right = insert(key, data, node->right, flag);
		if (flag)
			node->countSubNode++;
	}
	else {
		return node;
	}

	return balance(node);
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* AVLTree<Key, Data>::findMax(typename Tree<Key, Data>::Node* node) {
	Tree<Key, Data>::incrementCOUNTER();
	return node->right ? findMax(node->right) : node;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* AVLTree<Key, Data>::removeMax(typename Tree<Key, Data>::Node* node) {
	if (!node->right)
		return node->left;
	Tree<Key, Data>::incrementCOUNTER();
	node->right = removeMax(node->right);

	return balance(node);
}

template <class Key, class Data>
bool AVLTree<Key, Data>::remove(Key key) {
	bool flag = false;

	this->root = remove(key, this->root, flag);

	if (!flag)
		return false;

	this->root = balance(this->root);

	this->size--;
	return true;
}

template <class Key, class Data>
typename Tree<Key, Data>::Node* AVLTree<Key, Data>::remove(Key key, typename Tree<Key, Data>::Node* node, bool& flag) {
	Tree<Key, Data>::incrementCOUNTER();

	if (!node)
		return nullptr;

	if (node->key > key) {
		node->left = remove(key, node->left, flag);
		if (flag)
			node->countSubNode--;
	}
	else if (node->key < key) {
		node->right = remove(key, node->right, flag);
		if (flag)
			node->countSubNode--;
	}
	else {
		flag = true;
		typename Tree<Key, Data>::Node* p = node->right;
		typename Tree<Key, Data>::Node* q = node->left;
		delete node;
		if (!q)
			return p;
		typename Tree<Key, Data>::Node* buf = findMax(q);
		buf->left = removeMax(q);
		buf->right = p;

		return balance(buf);
	}

	return balance(node);
}

template <class Key, class Data>
void AVLTree<Key, Data>::print() {
	print(this->root, 0);
}

template <class Key, class Data>
void AVLTree<Key, Data>::print(typename Tree<Key, Data>::Node* node, int lvl) {
	if (!node) {
		for (int i = 0; i < lvl; i++)
			cout << "	";
		cout << "*" << endl;
		return;
	}

	print(node->right, lvl + 1);
	for (int i = 0; i < lvl; i++)
		cout << "	";
	cout << node->key << "(" << this->bFactor(node) << ")" << endl;
	print(node->left, lvl + 1);
}

template <class Key, class Data>
void AVLTree<Key, Data>::print(typename Tree<Key, Data>::Node* node, int lvl, typename Tree<Key, Data>::Iterator& iter) {
	if (!node) {
		for (int i = 0; i < lvl; i++)
			cout << "	";
		cout << "*" << endl;
		return;
	}

	print(node->right, lvl + 1, iter);
	for (int i = 0; i < lvl; i++)
		cout << "	";
	if (iter != Tree<Key, Data>::end() && iter == node)
		cout << "->";
	cout << node->key << "(" << this->bFactor(node) << ")" << endl;
	print(node->left, lvl + 1, iter);
}

template <class Key, class Data>
void AVLTree<Key, Data>::print(typename Tree<Key, Data>::Node* node, int lvl, typename Tree<Key, Data>::rIterator& riter) {
	if (!node) {
		for (int i = 0; i < lvl; i++)
			cout << "	";
		cout << "*" << endl;
		return;
	}

	print(node->right, lvl + 1, riter);
	for (int i = 0; i < lvl; i++)
		cout << "	";
	if (riter != Tree<Key, Data>::rend() && riter == node)
		cout << "->";
	cout << node->key << "(" << this->bFactor(node) << ")" << endl;
	print(node->left, lvl + 1, riter);
}