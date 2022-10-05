// laba3pt2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct node
{
	char inf[256];
	struct node* prev; // ссылка на предыдущий элемент 
};

struct node* head = NULL, * last = NULL; // указатели на первый и последний элементы списка

void push(const char* str);

void pop();

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char com[10], data[256];
	while (1) {
		if (head != NULL) {
			node* tmp = head;
			cout << "Очередь: ";
			while (1) {
				cout << tmp->inf << " ";
				if (tmp == last) {
					cout << endl << endl;
					break;
				}
				tmp = tmp->prev;
			}
		}
		cout << "Введите команду push или pop для работы с очередью. Чтобы выйти введите exit: ";
		cin >> com;
		cout << endl;
		if (!strcmp(com, "push")) {
			cout << "Введите данные для помещения в очередь: ";
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
			cout << "Вы ввели команду неверно" << endl << endl;
		}
	}
}

void push(const char* str) {
	node* tmp = (node*)malloc(sizeof(node));
	if (head == NULL) {
		head = tmp;
		last = tmp;
		strcpy_s(last->inf, str);
	}
	else {
		last->prev = tmp;
		strcpy_s(tmp->inf, str);
		last = tmp;
	}
}

void pop() {
	if (head == NULL) {
		cout << "Очередь пустая" << endl << endl;
		return;
	}
	else if (head == last) {
		cout << "Извлечённый элемент: " << head->inf << endl << endl;
		free(head);
		head = NULL;
		last = NULL;
	}
	else {
		cout << "Извлечённый элемент: " << head->inf << endl;
		node* tmp = head;
		head = head->prev;
		free(tmp);
	}
}