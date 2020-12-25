#pragma once
#include <iostream>
#include <conio.h>

//Преобразование строки с помощью конкатенации битовых образов символов
unsigned Key(char* str) {
	unsigned K;
	for (K = 0; *str != '\0'; str++) {
		K = *str + 32 * K;
	}
	return K;
}

using namespace std;

double A;
int m;

//Хеш-таблица с открытой адресацией
template <class K, class D>
class HashTableOA
{	//Элемент хеш-таблицы
	class Node {
	public:
		K key;//ключ
		D data;//данные
		char state;//состояние элемента
	};
protected:
	Node* List;
public:
	HashTableOA(int);
	~HashTableOA();
	int Count();
	bool isEmpty();
	double GetAlfa();
	void Insert(K, D = 0);
	void Delete(K);
	D Search(K);
	int TestInsert(K);
	int TestDelete(K);
	int TestSearch(K);
	void Print();
	//Класс итератора
public:
	class Iterator {
		HashTableOA* ptr;
		Node* cur;
		int i;
	public:
		Iterator(HashTableOA* _p) {
			ptr = _p;
			cur = &(ptr->List[0]);
			i = 0;
		}
		void next() {
			if (cur->state != 'b')
				return;
			do {
				cur = &(ptr->List[++i]);
				if (cur->state == 'b')
					break;
			} while (i != m);
		}
		void first() {
			for (i = 0; i < m; i++) {
				cur = &(ptr->List[i]);
				if (cur->state == 'b')
					break;
			}
			if (i == m)
				throw exception("В таблице нет элементов!");
		}
		bool is_off() {			//проверка выхода итератора за пределы коллекции
			if (cur->state != 'b')
				return true;
			return false;
		}
		D& operator * () {  	//доступ к данным текущего элемента
			if (cur->state != 'b')
				throw exception("Итератор 'не установлен'");
			return cur->data;		//ссылка на текущий элемент
		}
		K showkey() {			//чтение ключа текущего элемента
			if (cur->state != 'b')
				throw exception("Итератор 'не установлен'");
			return cur->key;
		}
	};
	friend class Iterator;
};

//Конструктор
template <class K, class D>
HashTableOA<K, D>::HashTableOA(int k) {
	A = (sqrt(5) - 1) / 2;
	m = 2 * k;
	List = new Node[m];
	for (int i = 0; i < m; i++) {
		List[i].key = NULL;
		List[i].state = 'f';
	}
}

//Деструктор
template <class K, class D>
HashTableOA<K, D>::~HashTableOA() {
	for (int i = 0; i < m; i++) {
		List[i].state = 'f';
		if (List[i].key != NULL)
			List[i].key = NULL;
	}
}

//Опрос размера таблицы
template <class K, class D>
int HashTableOA<K, D>::Count() {
	int sum = 0;
	for (int i = 0; i < m; i++)
		if (List[i].key != NULL)
			sum++;
	return sum;
}

//Проверка таблицы на пустоту
template <class K, class D>
bool HashTableOA<K, D>::isEmpty() {
	for (int i = 0; i < m; i++)
		if (List[i].key != NULL)
			return false;
	return true;
}

//Oпрос коэффициента заполнения таблицы
template <class K, class D>
double HashTableOA<K, D>::GetAlfa() {
	return (double)Count() / m;
}

//Включение нового объекта с заданным ключом
template <class K, class D>
void HashTableOA<K, D>::Insert(K str, D val) {
	int h, h1, pos = -1, j = 0;
	unsigned k = Key(str);
	h = (int)(m * (A * k - (int)(A * k)));
	h1 = h;
while (j != m && List[h1].state != 'f') {
		h1 = (h + j) % m;
		if (List[h1].state == 'd' && pos == -1)
			pos = h1;
		if (List[h1].state == 'b') {
			if (strcmp(List[h1].key, str) == 0)
				throw exception("Этот элемент уже существует!");
		}
		j++;
	}
	if (j == m && List[h1].state == 'b' && pos == -1)
		throw exception("В хеш-таблице нет места!");
	if (pos == -1)
		pos = h1;
	List[pos].key = str;
	List[pos].data = val;
	List[pos].state = 'b';
}

//Удаление объекта с заданным ключом
template <class K, class D>
void HashTableOA<K, D>::Delete(K str) {
	int h, h1, j = 0;
	unsigned k = Key(str);
	h = (int)(m * (A * k - (int)(A * k)));
	while (1) {
		h1 = (h + j) % m;
		if (List[h1].state == 'f')
			throw exception("Этого элемента не существует!");
		if (List[h1].state == 'b')
			if (strcmp(List[h1].key, str) == 0) {
				List[h1].state = 'd';
				List[h1].key = NULL;
				if (isEmpty())
					for (int i = 0; i < m; i++)
						List[i].state = 'f';
				return;
			}
		j++;
		if (j == m)
			throw exception("Этого элемента не существует!");
	}
}

//Поиск объекта с заданным ключом
template <class K, class D>
D HashTableOA<K, D>::Search(K str) {
	int h, h1, j = 0;
	unsigned k = Key(str);
	h = (int)(m * (A * k - (int)(A * k)));
	while (1) {
		h1 = (h + j) % m;
		if (List[h1].state == 'f')
			throw exception("Этого элемента не существует!");
		if (List[h1].state == 'b')
			if (strcmp(List[h1].key, str) == 0)
				return List[h1].data;
		j++;
		if (j == m)
			throw exception("Этого элемента не существует!");
	}
}

//Тестирование трудоемкости вставки
template <class K, class D>
int HashTableOA<K, D>::TestInsert(K str) {
	int count = 0;
	int h, h1, pos = -1, j = 0;
	unsigned k = Key(str);
	h = (int)(m * (A * k - (int)(A * k)));
	h1 = h;
	while (j != m && List[h1].state != 'f') {
		h1 = (h + j) % m;
		if (List[h1].state == 'd' && pos == -1) {
			pos = h1; count++;
		}
		if (List[h1].state == 'b') {
			count++;
			if (strcmp(List[h1].key, str) == 0)
				return count;
		}
		j++;
	}
	if (j == m && List[h1].state == 'b' && pos == -1)
		return count;
	count++;
	if (pos == -1)
		pos = h1;
	List[pos].key = str;
	List[pos].state = 'b';
	return count;
}

//Тестирование трудоемкости удаления
template <class K, class D>
int HashTableOA<K, D>::TestDelete(K str) {
	int count = 0;
	int h, h1, j = 0;
	unsigned k = Key(str);
	h = (int)(m * (A * k - (int)(A * k)));
	while (1) {
		h1 = (h + j) % m;
		if (List[h1].state == 'f')
			return count;	//Элемент не найден
		if (List[h1].state == 'b') {
			count++;
			if (strcmp(List[h1].key, str) == 0) {
				List[h1].state = 'd';
				List[h1].key = NULL;
				return count;
			}
		}
		j++;
		if (j == m)
			return count;//Элемент не найден
	}
}

//Тестирование трудоемкости поиска
template <class K, class D>
int HashTableOA<K, D>::TestSearch(K str) {
	int count = 0;
	int h, h1, j = 0;
	unsigned k = Key(str);
	h = (int)(m * (A * k - (int)(A * k)));
	while (1) {
		h1 = (h + j) % m;
		if (List[h1].state == 'f')
			return count;//Элемент не найден
		if (List[h1].state == 'b') {
			count++;
			if (strcmp(List[h1].key, str) == 0)
				return count;
		}
		j++;
		if (j == m)
			return count;
	}
}

//Вывод структуры хеш-таблицы на экран
template <class K, class D>
void HashTableOA<K, D>::Print() {
	for (int i = 0; i < m; i++) {
		if (List[i].state == 'b')
			cout << i << " - " << List[i].key << endl;
		else {
			if (List[i].state != 'f')
				cout << i << " - " << List[i].state << endl;
			else
				cout << i << " - Пусто" << endl;
			}
	}
}


int M;

//Хеш-таблица с цепочками коллизий
template <class K, class D>
class HashTableCC {
	class Node {
	public:
		K key;			//ключ
		D data;			//данные
		Node* next;		//указатель на следующий элемент
	};
protected:
	Node** List;
public:
	HashTableCC(int);
	~HashTableCC();
	int Count();
	bool isEmpty();
	double GetAlfa();
	void Insert(K, D = 0);
	void Delete(K);
	D Search(K);
	int TestInsert(K);
	int TestDelete(K);
	int TestSearch(K);
	void Print();
public:
	class Iterator {
		HashTableCC* ptr;
		Node* cur;
		int i;

	public:
		Iterator(HashTableCC* _p) {
			ptr = _p;
			cur = ptr->List[0];
			i = 0;
		}
		void next() {
			if (!cur || i == M) return;
			if (cur->next) {
				cur = cur->next;
				return;
			}
			do {
				cur = ptr->List[++i];
				if (cur)
					break;
			} while (i != m);
		}
		void first() {
			for (i = 0; i < M; i++) {
				cur = ptr->List[i];
				if (cur)
					break;
			}
			if (!cur)
				throw exception("В таблице нет элементов!");
		}
		bool is_off() {
			if (!cur || i == M)
				return true;
			return false;
		}
		D& operator* () {
			if (!cur || i == M)
				throw exception("Итератор 'не установлен'");
			return cur->data;
		}
		K showkey() {
			if (!cur || i == M)
				throw exception("Итератор 'не установлен'");
			return cur->key;
		}
	};
	friend class Iterator;
};

//Конструктор
template <class K, class D>
HashTableCC<K, D>::HashTableCC(int k) {
	A = (sqrt(5) - 1) / 2;
	M = k / 2;
	List = new Node * [M];
	for (int i = 0; i < M; i++)
		List[i] = NULL;
}

//Деструктор
template <class K, class D>
HashTableCC<K, D>::~HashTableCC() {
	for (int i = 0; i < M; i++) {
		if (List[i] != NULL)delete List[i];
		List[i] = NULL;
	}
}

//Oпрос размера таблицы
template <class K, class D>
int HashTableCC<K, D>::Count() {
	int sum = 0;
	for (int i = 0; i < M; i++) {
		if (List[i])sum++;
		Node* t;
		if (List[i]) {
			t = List[i]->next;
			while (t != NULL) {
				sum++;
				t = t->next;
			}
		}
	}
	return sum;
}

//Проверка таблицы на пустоту
template <class K, class D>
bool HashTableCC<K, D>::isEmpty() {
	for (int i = 0; i < M; i++)
		if (List[i]) return false;
	return true;
}

//Oпрос коэффициента заполнения таблицы
template <class K, class D>
double HashTableCC<K, D>::GetAlfa() {
	return (double)Count() / M;
}

//Включение нового объекта с заданным ключом
template <class K, class D>
void HashTableCC<K, D>::Insert(K str, D val) {
	unsigned k = Key(str);
	int h = (int)(M * (A * k - (int)(A * k)));	//Мультипликативный метод хеширования
	if (List[h] == NULL) {
		List[h] = new Node();
		List[h]->next = NULL;
		List[h]->key = str;
		List[h]->data = val;
	}
	else {
		Node* p = List[h];
		if (strcmp(p->key, str) == 0)
			throw exception("Этот элемент уже существует!");
		while (p->next != NULL) {
			p = p->next;
			if (strcmp(p->key, str) == 0)
				throw exception("Этот элемент уже существует!");
		}
		p->next = new Node();
		p->next->next = NULL;
		p->next->key = str;
		p->next->data = val;
	}
}

//Удаление объекта с заданным ключом
template <class K, class D>
void HashTableCC<K, D>::Delete(K str) {
	unsigned k = Key(str);
	int h = (int)(M * (A * k - (int)(A * k)));
	Node* p = List[h];
	if (p == NULL)
		throw exception("Этого элемента не существует!");
	if (strcmp(p->key, str) == 0) {
		List[h] = List[h]->next;
		delete p;
		return;
	}
	while (p->next != NULL) {
		if (strcmp(p->next->key, str) == 0)
			break;
		p = p->next;
	}
	if (p->next == NULL)
		throw exception("Этого элемента не существует!");
	Node* t = p->next;
	p->next = p->next->next;
	delete t;
}

//Поиск объекта с заданным ключом
template <class K, class D>
D HashTableCC<K, D>::Search(K str) {
	unsigned k = Key(str);
	int h = (int)(M * (A * k - (int)(A * k)));
	Node* t = List[h];
	while (t != NULL) {
		if (strcmp(t->key, str) == 0)
			break;
		t = t->next;
	}
	if (t == NULL)
		throw exception("Этого элемента не существует!");
	return t->data;
}

//Тестирование трудоемкости вставки
template <class K, class D>
int HashTableCC<K, D>::TestInsert(K str) {
	int count = 0;
	unsigned k = Key(str);
	int h = (int)(M * (A * k - (int)(A * k)));
	if (List[h] == NULL) {
		count++;
		List[h] = new Node();
		List[h]->next = NULL;
		List[h]->key = str;
	}
	else {
		count++;
		Node* p = List[h];
		if (strcmp(p->key, str) == 0)
			return count;
		while (p->next != NULL) {
			count++;
			p = p->next;
			if (strcmp(p->key, str) == 0)
				return count;
		}
		count++;
		p->next = new Node();
		p->next->next = NULL;
		p->next->key = str;
	}
	return count;
}

//Тестирование трудоемкости удаления
template <class K, class D>
int HashTableCC<K, D>::TestDelete(K str) {
	int count = 0;
	unsigned k = Key(str);
	int h = (int)(M * (A * k - (int)(A * k)));
	Node* p = List[h];
	if (p == NULL)
		return count;
	if (strcmp(p->key, str) == 0) {
		List[h] = List[h]->next;
		delete p;
		return count;
	}
	while (p->next != NULL) {
		count++;
		if (strcmp(p->next->key, str) == 0)
			break;
		p = p->next;
	}
	if (p->next == NULL) {
		return count;
	}
	Node* t = p->next;
	p->next = p->next->next;
	delete t;
	return count;
}

//Тестирование трудоемкости поиска
template <class K, class D>
int HashTableCC<K, D>::TestSearch(K str) {
	int count = 0;
	unsigned k = Key(str);
	int h = (int)(M * (A * k - (int)(A * k)));
	Node* t = List[h];
	while (t != NULL) {
		count++;
		if (strcmp(t->key, str) == 0)
			break;
		t = t->next;
	}
	if (t == NULL)
		return count;
	return count;
}

//Вывод структуры хеш-таблицы на экран
template <class K, class D>
void HashTableCC<K, D>::Print() {
	for (int i = 0; i < M; i++) {
		if (List[i] != NULL) {
			cout << i << " - " << List[i]->key;
			Node* t = List[i]->next;
			while (t != NULL) {
				cout << ", " << t->key;
				t = t->next;
			}
			cout << endl;
		}
		else
			cout << i << " - Пусто" << endl;
	}
}