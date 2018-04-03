// lab5.cpp: 
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <conio.h>

#include <time.h>
#include <algorithm> //find_if
#include <numeric> //accumulate
#include <vector>

using namespace std;

struct MyClass3
{
	int operator()(int i)
	{
		return (i == 2) || (i == 3) || (i == 5) || (i == 7);
	}
};
	
int main()
{
	//setlocale(LC_ALL, "Russian");
	srand((unsigned)time(NULL));

	int n = 6; 
	vector<int>Vector(n);
	for (int i = 0; i < n; i++)
		Vector[i] = rand() % 10;

	cout << "Исходный вектор:" << endl;
	for_each(Vector.begin(), Vector.end(), [](int i){ cout << i << ' '; });
	cout << endl;

	vector <int>::iterator pv;
	MyClass3 obj3;
	pv = find_if(Vector.begin(), Vector.end(), obj3);
	if (pv == Vector.end()) cout << "No prime numbers" << endl << endl;
	else cout << "First element: " << *pv << endl << endl;
	
	_getch();
	return 0;
}
//[&, n] (int a) mutable { m = ++n + a; }(4); //mutable 
//int n = [] (int x, int y) { return x + y; }(5, 4);
