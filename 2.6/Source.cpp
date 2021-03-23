#include "Date.h"
#include <Windows.h>
#include <iostream>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Date::Triad a;
	cin >> a;
	a.incDay();
	Date a2;
	a2.Init(a);
	a2.Display();
	a2.incDay();
	a2.addDay();
	a2.Display();
	cout << a++;
	cout << a--;
	cout << ++a;
	cout << --a;

}