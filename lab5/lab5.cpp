// lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <conio.h>

#include <time.h>
#include <algorithm> //для for_each
#include <numeric> //для accumulate
#include <vector>

using namespace std;

/*class MyClass
{
public:
void operator()(int i)
{
cout << i << ' ';
}
};*/
struct MyClass
{
	void operator()(int i)
	{
		cout << i << ' ';
	}
};

template <class T>
T sum(T x, T y)
{
	return x + y;
}

template <typename T> class MyClass2
{
public:
	void operator()(list <int> main_int)
	{
		//cout << i << ' ';
		//main_int_iter = main_int.begin();
		//list <int> main_int;
		//cout << "Сумма простых чисел: " << accumulate(main_int.begin(), main_int.end(), 0, sum<int>);
		cout << accumulate(main_int.begin(), main_int.end(), 0, sum<int>);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(NULL));

	/*
	int n = 10; 
	vector<int>Vector(n);
	for (int i = 0; i < n; i++)
		Vector[i] = rand() % n;
		
		
	//_______________________________________________________________________lab2_11_32.cpp:	
		
		
		*/
	vector <int> Vector = { -1, 2, 3, 17, 5, 6, 7 };

	Vector.at(1) = 999;

	list <int> l_int;
	MyClass obj;

	int i;
	for (i = 0; i < 6; i++) l_int.push_back(rand() % 10);

	cout << "Исходный список:" << endl;
	list <int>::iterator ip = l_int.begin();
	for_each(l_int.begin(), l_int.end(), obj);
	cout << endl;

	//поиск простых чисел
	list <int> main_int;
	list <int>::iterator main_int_iter;
	ip = l_int.begin();
	while (ip != l_int.end())
	{
		switch (*ip)
		{
		case 2:
			main_int.push_back(2);
			break;
		case 3:
			main_int.push_back(3);
			break;
		case 5:
			main_int.push_back(5);
			break;
		case 7:
			main_int.push_back(7);
			break;
		default:
			main_int.push_back(0);
			break;
		}
		ip++;
	}

	main_int_iter = main_int.begin();
	cout << "Список из простых чисел:" << endl;
	for_each(main_int.begin(), main_int.end(), obj); ////вывод списка, использовали объект в качестве аргумента для алгоритма
	cout << endl << endl;

	cout << "Сумма простых чисел: " << accumulate(main_int.begin(), main_int.end(), 0, sum<int>); //Суммируем 
	cout << endl << endl;

	MyClass2 <int> obj2;
	cout << "Список из простых чисел через шаблон:" << endl;
	for_each(main_int.begin(), main_int.end(), obj2);
	cout << endl;
	//cout << "Сумма простых чисел: " << accumulate(main_int.begin(), main_int.end(), 0, sum<int>);

	_getch();
	return 0;
}

