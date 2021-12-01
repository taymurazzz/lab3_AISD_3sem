#include "Header.h"

int main() {
	setlocale(LC_ALL, "Russian");
	heap a;
	a.begin();
	int var;
	int data;
	cout << " Доступные действия:" << endl;
	cout << " 1)Поиск элемента в дереве по ключу" << endl; 
	cout << " 2)Добавление элемента в дерево по ключу" << endl;
	cout << " 3)Удаление в дереве по ключу" << endl;
	cout << " 4)Прохожление дерева в ширину" << endl;
	cout << " 5)Прохожление дерева в глубину" << endl;
	cout << " 6)Закончить работу с деревом" << endl;
	
	while (1) {
		cout << "Выберите действие: ";
		cin >> var;
		cout << endl;
		if (var == 1) {
			cout << "Введите ключ: ";
			cin >> data;
			cout << endl;
			if (a.contains(data) == 1) {
				cout << "Значение есть в дереве" << endl;
			}
			else {
				cout << "Значения нет в дереве" << endl;
			}
		}

		if (var == 2) {
			cout << "Введите ключ: ";
			cin >> data;
			cout << endl;
			a.insert(data);
		}

		if (var == 3) {
			cout << "Введите ключ: ";
			cin >> data;
			if (a.contains(data)) {
				a.remove(data);
			}
			else {
				cout << "Неверный ключ, удаление невозможно";
			}

		}
		if (var == 4) {
			cout << "Порядок прохождения в ширину: ";
			iteratorS* a_iteratorS = a.create_iteratorS();
			while (a_iteratorS->has_next()) {
				cout << a_iteratorS->next() << " ";
			}
			cout << endl << endl;
		}
		if (var == 5) {
			cout << "Порядок прохождения в глубину: ";
			iteratorG* a_iteratorG = a.create_iteratorG();
			int ii = 0;
			while (ii < a.size()) {
				cout << a_iteratorG->Next() << " ";
				ii++;
			}
			cout << endl << endl;
		}
		if (var == 6) {
			return 0;
		}
	}

}