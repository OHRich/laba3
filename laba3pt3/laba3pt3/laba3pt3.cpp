// laba3pt3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct node
{
	char inf[256];
	struct node* next; // ссылка на следующий элемент 
};

struct node* last = NULL; // указатели на последний элементы списка

void push(const char* str);

void pop();

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char com[10], data[256];
	while (1) {
		if (last != NULL) {
			node* tmp = last;
			cout << "Стэк: ";
			while (1) {
				cout << tmp->inf << " ";
				if (tmp->next == NULL) {
					cout << endl << endl;
					break;
				}
				tmp = tmp->next;
			}
		}
		cout << "Введите команду push или pop для работы со стеком. Чтобы выйти введите exit: ";
		cin >> com;
		cout << endl;
		if (!strcmp(com, "push")) {
			cout << "Введите данные для помещения в стэк: ";
			cin >> data;
			cout << endl;
			push(data);
		}
		else if (!strcmp(com, "pop")) {
			pop();
		}
		else if (!strcmp(com, "exit")) {
			exit(0);
		}
		else {
			cout << "Вы ввели команду неверно" << endl;
		}
	}
}

void push(const char* str) {
	node* tmp = (node*)malloc(sizeof(node));
	if (last == NULL) {
		last = tmp;
		strcpy_s(last->inf, str);
		last->next = NULL;
	}
	else {
		tmp->next = last;
		strcpy_s(tmp->inf, str);
		last = tmp;
	}
}

void pop() {
	if (last == NULL) {
		cout << "Стэк пустой" << endl << endl;
		return;
	}
	else if (last->next == NULL) {
		cout << "Извлечённый элемент: " << last->inf << endl << endl;
		free(last);
		last = NULL;
	}
	else {
		cout << "Извлечённый элемент: " << last->inf << endl;
		node* tmp = last;
		last = last->next;
		free(tmp);
	}
}