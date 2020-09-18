#pragma once
#include <iostream>
using namespace std;

class TreeError {
public:
	TreeError() {}

	virtual void ErrMsg() const {
		cerr << ">>> Ошибка в работе с деревом!\n";
	}

	void Continue() const {
		cerr << ">>> Программа продолжает работать.\n>>> ";
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