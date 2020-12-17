#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Insert(Elem*& L, Info value);
void Print(Elem* L);
int Count(Elem* L);
void Remove(Elem*& L);
void Process(Elem*& L);
int prev_elem(Elem* L, int count, int size);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* L = NULL;

	Info value, N;

	do
	{
		cout << "Введіть кількість елементів списку: "; cin >> N;
	} while (N < 0);

	for (int i = 0; i < N; i++)
	{
		cout << "Введіть дані: "; cin >> value;
		Insert(L, value);
	}

	cout << "Елементи черги: "; Print(L); cout << endl;

	Process(L);
	cout << "Рузультат: "; Print(L);

	return 0;
}
void Insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link;

		T->link = tmp;
	}
	else
		L = tmp;

	tmp->link = L;
}
void Print(Elem* L)
{
	if (L == NULL)
		return;

	Elem* first = L;
	cout << L->info << " ";
	while (L->link != first)
	{
		L = L->link;
		cout << L->info << " ";		
	}
}
void Process(Elem*& L)
{
	int size = Count(L);

	for (int i = 0; i < size - 1; i++)
	{
		Insert(L, prev_elem(L, i, size)); //добавлення у кінець списку зворотних елементів
	}

	for (int j = 0; j < size - 1; j++)
	{
		Remove(L);//видалення лишніх елементів
	}
}
int Count(Elem* L)
{
	if (L == NULL)
		return 0;

	Elem* first = L;
	int k = 1;
	while (L->link != first)
	{
		k++;
		L = L->link;
	}
	return k;
}
int prev_elem(Elem* L, int count, int size)
{
	for (int i = 0; i < size - count - 2; i++)
		L = L->link;
	return L->info;
}
void Remove(Elem*& L)
{
	Elem* T = L;
	while (T->link != L)
		T = T->link;

	Info value = L->info;

	if (T != L)
	{
		Elem* tmp = L->link;
		delete L;

		L = tmp;
		T->link = L;
	}
}