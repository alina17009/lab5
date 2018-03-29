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

/*struct MyClass
{
	void operator()(int i)
	{
		cout << i << ' ';
	}
};*/
/*struct MyClass3
{
	int operator()(int i)
	{
		return (i == 2) || (i == 3) || (i == 5) || (i == 7);
	}
};*/
	
/*template <typename T> class MyClass2
{
public:
	void operator()(int i)
	{
		cout << i << ' ';
		
		//cout << accumulate(main_int.begin(), main_int.end(), 0, sum<int>);
	}
};*/

int main()
{
	setlocale(LC_ALL, "Russian");
	srand((unsigned)time(NULL));
		
	int n = 6; 
	vector<int>Vector(n);
	for (int i = 0; i < n; i++)
		Vector[i] = rand() % 10;
	for_each(Vector.begin(), Vector.end(), [](int i){ cout << i << ' '; });
	
	//MyClass obj;
	cout << "�������� ������:" << endl;
	for_each(Vector.begin(), Vector.end(), [](int i){ cout << i << ' '; });
	cout << endl;

	vector <int>::iterator pv;
	//MyClass3 obj3;
	pv = find_if(Vector.begin(), Vector.end(), [](int i){ return (i == 2) || (i == 3) || (i == 5) || (i == 7); });
	if (pv == Vector.end()) cout << "������� ����� ���" << endl << endl;
	else cout << "������ �������, ������� �������� ������� ������: " << *pv << endl << endl;
			
	_getch();
	return 0;
}
//[&, n] (int a) mutable { m = ++n + a; }(4); //mutable ��������� �������� n ������ ������-���������
//int n = [] (int x, int y) { return x + y; }(5, 4);
