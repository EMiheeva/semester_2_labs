#include <iostream>

struct T_List
{
	T_List* next;
	int age;
};

void ADD(T_List* head, int age)// вставляет элемент после данного
{
	T_List* p = new T_List;
	p->age = age;

	p->next = head->next;
	head->next = p;
}

void InsertAfter(T_List* head, int age, int k)
{
	T_List* p = head;

	for (int i = 0; i < k; i++) 
	{
		//считаем до нужной позиции
		p = p->next;
	}
	ADD(p, age);//и вставляем после нее нужный элемент
}

void PRINT(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->age << std::endl;
		p = p->next;
	}
}

void DELETE(T_List* head)
{
	T_List* tmp;
	T_List* p = head;
	while (p->next != nullptr)
	{
		if (p->next->age % 2 == 0)
		{
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		}
		else
			p = p->next;
	}
}

void CLEAR(T_List* head)
{
	T_List* tmp;
	T_List* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
}


int main()
{
	T_List* head = new T_List;
	head->next = nullptr;
	ADD(head, 10);
	ADD(head, 2);
	ADD(head, 3);
	ADD(head, 5);
	ADD(head, 6);

	PRINT(head);
	std::cout << "///" << std::endl;
	InsertAfter(head, 1, 3);// вставка элемента 1 в позицию 2

	PRINT(head);

	CLEAR(head);

	delete head;
	return 0;
}
