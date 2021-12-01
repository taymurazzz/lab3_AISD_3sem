#include <iostream>
#include "iteratorShirina.h"
#include "iteratorGlubina.h"


using namespace std;

class heap {
public:
	int key;
	heap* next;
	heap* spisok;
	heap* prev;
	heap* head;
	heap* last;

	heap() {
		next = NULL;
		spisok = NULL;
		prev = NULL;
		head = NULL;
		last = NULL;
	}
	// начало работы
	void begin() {
		head = new heap;
		last = new heap;
		

		head->next = last;
		last->prev = head;
	}
	// вывод значния по индексу в куче
	int at(int index) {
		spisok = head->next;
		int i = 0;
		while (i!=index) {
			spisok = spisok->next;
			i++;
		}
		return spisok->key;
	}
	// нахождение размера 
	int size() {
		spisok = head->next;
		int i = 0;
		while (spisok->next != NULL) {
			spisok = spisok->next;
			i++;
		}
		return i;
	}
	// обмен двух значений
	void swap(int one, int two) {
		int i = 0;
		int keyOne= at(one);
		int keyTwo= at(two);
		spisok = head->next;
		while (i != one) {
			spisok = spisok->next;
			i++;
		}
		spisok->key = keyTwo;
		i = 0;
		spisok = head->next;
		while (i != two) {
			spisok = spisok->next;
			i++;
		}
		spisok->key = keyOne;
	}
	// вывод значений кучи
	void print() {
		spisok = head->next;
		while (spisok->next != NULL) {
			cout << spisok->key;
			spisok = spisok->next;
		}
	}
	// добавление значения
	void insert(int data) {
		if (head->next != last) {
			spisok = last->prev;
			spisok->next = new heap;
			spisok->next->key = data;
			spisok->next->prev = spisok;
			spisok->next->next = last;
			spisok = spisok->next;
			last->prev = spisok;
			siftUp(size() - 1);
		}

		if (head->next == last) {
			spisok = new heap;
			spisok->key = data;
			head->next = spisok;
			last->prev = spisok;
			spisok->prev = head;
			spisok->next = last;
		}
	}
	// просеивание вверх
	void siftUp(int index){
		while (at(index) < at((index - 1) / 2)) {
			swap(index, ((index - 1) / 2) );
			index = (index - 1) / 2;
		}
	}
	// проверка на то что ключ есть в куче
	bool contains(int data) {
		spisok = head->next;
		bool contex = 0;
		while (spisok->next != NULL) {
			if (spisok->key == data) {
				contex = 1;
			}
			spisok = spisok->next;
		}
		return contex;
	}
	// просеивание вниз
	void siftDown(int index) {
		int left, right, j = 0;
		while ((2 * index + 1) < size()) {
			left = 2 * index + 1;
			right = 2 * index + 2;
			j = left;
			if (right < size() && at(right) < at(left)) {
				j = right;
			}
			if (at(index) < at(j)) {
				break;
			}
			swap(index, j);
			index = j;
		}
	}
	// удаление 
	void remove(int data) {
		int indexD =0;
		spisok = head->next;
		while (spisok->next != NULL) {
			if (spisok->key == data) {
				break;
			}
			else {
				indexD++;
				spisok = spisok->next;
			}
		}
		swap(indexD, (size() - 1));

		spisok = last->prev->prev;
		spisok->next = last;
		last->prev = spisok;

		siftDown(indexD);
		siftUp(indexD);
	}
	
	// итератор в ширину 
	iteratorS* create_iteratorS() {
		return new Shirina(head->next);
	}
	class Shirina : public iteratorS
	{
	public:
		heap* current;
		Shirina(heap* start) {
			current = start;
		}
		bool has_next() {
			return current->next != NULL;
		}
		int next() {
			if (!has_next()) {
				throw out_of_range("No more elements");
			}
			int temp = current->key;
			current = current->next;
			return temp;
		}
	};

	// итератор в глубину 
	iteratorG* create_iteratorG() {
		return new Glubina(head->next, size());
	}

	class Glubina : public iteratorG
	{
	public:
		heap* current;
		heap* head;
		heap* mass[1000];
		heap* temp;
		int size;
		int i = 0;
		int j = 0;
		int z = 0;
		int tmp;
		Glubina(heap* start, int sizee) {
			current = start;
			head = start;
			size = sizee;
		}
		heap* ptrR(int index) {
			current = head;
			z = 0;
			while (z != index) {
				current = current->next;
				z++;
			}
			return current;
		}
		bool has_Left() {
			if (((i * 2) + 1) < size) {
				return 1;
			}
			else {
				return 0;
			}
		}
		bool has_Right() {
			if (((i * 2) + 2) < size) {
				return 1;
			}
			else {
				return 0;
			}
		}
		int Next() {
			tmp = current->key;
			if (has_Right()) {
				mass[j] = ptrR((i * 2) + 2);
				j++;
			}
			if (has_Left()) {
				current = ptrR((i * 2) + 1);
				i = (i * 2) + 1;
			}
			else {
				current = mass[j - 1];
				temp = head;
				z = 0;
				while (current != temp) {
					temp = temp->next;
					z++;
				}
				j = j - 1;
				i = z;
			}
			return tmp;
		}
	};

};