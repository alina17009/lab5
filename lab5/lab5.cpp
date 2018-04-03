// lab5.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/* http://ci-plus-plus-snachala.ru/?p=323 */


#include "stdafx.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <conio.h>

#include <time.h>
#include <algorithm> //��� find_if
#include <numeric> //��� accumulate
#include <vector>

using namespace std;

struct MyClass
{
	void operator()(int i)
	{
		cout << i << ' ';
	}
};
struct MyClass3
{
	int operator()(int i)
	{
		return (i == 2) || (i == 3) || (i == 5) || (i == 7);
	}
};
	
int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(NULL));
		
	int n = 6; 
	vector<int>Vector(n);
	for (int i = 0; i < n; i++)
		Vector[i] = rand() % 10;

	MyClass obj;
	cout << "�������� ������:" << endl;
	for_each(Vector.begin(), Vector.end(), obj);
	cout << endl << endl << endl;

	vector <int>::iterator pv;
	MyClass3 obj3;
	pv = find_if(Vector.begin(), Vector.end(), obj3);
	if (pv == Vector.end()) cout << "������� ����� ���" << endl << endl;
	else cout << "������ �������, ������� �������� ������� ������: " << *pv << endl << endl;
		
	_getch();
	return 0;
}

