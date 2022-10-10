// laba3fin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct node
{
	char inf[256];
	int P;
	struct node* prev; // ссылка на предыдущий элемент 
};

struct node* head = NULL, * last = NULL; // указатели на первый и последний элементы списка

void push(const char* str, int P);

void pop();

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	char com[10], data[256];
	int pr;
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
			cout << "Введите номер для приоритета в очереди: ";
			cin >> pr;
			cout << endl;
			push(data, pr);
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

void push(const char* str, int P) {
	node* tmp = (node*)malloc(sizeof(node));
	if (head == NULL) {
		head = tmp;
		last = tmp;
		tmp->P = P;
		strcpy_s(tmp->inf, str);
	}
	else {
		char flag = 0;
		tmp->P = P;
		strcpy_s(tmp->inf, str);
		node* sravn = head, * sravnprev = head;
		while (flag == 0) {
			while (1) {
				if (sravn->P == tmp->P) {	//если номера равны
					if (sravn == last) {	//если последний элемент равен вводимому
						last = tmp;
						sravn->prev = tmp;
						flag = 1;
						break;
					}
					else {
						tmp->prev = sravn->prev;
						sravn->prev = tmp;
						flag = 1;
						break;
					}
				}
				else if (sravn->P < tmp->P) {		//если номер с меньшим приоритетом
					if (sravn == last) {
						last = tmp;
						sravn->prev = tmp;
						flag = 1;
						break;
					}
					else {
						sravnprev = sravn;
						sravn = sravn->prev;
						break;
					}
				}
				else if (sravn->P > tmp->P) {		//если номер с большим приоритетом
					if (sravn == head) {
						tmp->prev = head;
						head = tmp;
						flag = 1;
						break;
					}
					else {
						tmp->prev = sravn;
						sravnprev->prev = tmp;
						flag = 1;
						break;
					}
				}
			}
		}
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