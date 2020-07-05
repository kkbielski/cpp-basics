#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;

	cout << "Podaj liczbe i wcisnij enter:";
	cin >> a;
	cout << "Podaj druga liczbe i wcisnij enter:";
	cin >> b;
	cout << "Podaj trzecia liczbe i wcisnij enter:";
	cin >> c;

	if (a > b && a > c) {
		cout << a << " ta liczba jest najwieksza";
	}
	else if (b > a && b > c) {
		cout << b << " ta liczba jest najwieksza";
	}
	else if (c > a && c > b) {
		cout << c << " ta liczba jest najwieksza";
	}
}