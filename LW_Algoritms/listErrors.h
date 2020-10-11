#pragma once
#include <iostream>
using namespace std;

class TreeError {
public:
	TreeError() {}

	virtual void ErrMsg() const {
		cerr << ">>> Ошибка при работе с деревом!\n";
	}

	void Continue() const {
		cerr << ">>> Программа продолжает работать.\n>>> ";
	}
};

class TreeIsEmpty : public TreeError {
public:
	TreeIsEmpty() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка при работе с пустым деревом!\n";
		Continue();
	}
};

class TreeDelErr : public TreeError {
public:
	TreeDelErr() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка удаления! Дерево пусто!\n";
		Continue();
	}
};

class TreeFindErr : public TreeError {
public:
	TreeFindErr() {}
	void ErrMsg() const {
		cerr << ">>> Ошибка поиска! Искомый узел не был найден!\n";
		Continue();
	}
};

class IteratorError {
public:
	IteratorError() {}

	virtual void ErrMsg() const {
		cerr << ">>> Ошибка в работе итератора!\n";
	}

	void Continue() const {
		cerr << ">>> Программа продолжает работать.\n>>> ";
	}
};

class IteratorInactive : public IteratorError {
public:
	IteratorInactive() {}
	void ErrMsg() const {
		cerr << ">>> Итератор находится в режиме 'неустановленный'.\n>>> Для последующего использования итератора воспользуйтесь функцией begin/rbegin." << endl;
		Continue();
	}
};