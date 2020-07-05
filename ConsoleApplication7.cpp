#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int d;

	cout << "Podaj liczbe i wcisnij enter:";
	cin >> a;
	cout << "Podaj druga liczbe i wcisnij enter:";
	cin >> b;
	cout << "Podaj trzecia liczbe i wcisnij enter:";
	cin >> c;
	cout << "Podaj czwarta liczbe i wcisnij enter:";
	cin >> d;

	if (a != 90 || b != 90 || c != 90 || d != 90) {
		cout << "Prostokat musi miec wszystkie katy 90 stopni!";
	}
	else {
		cout << "Z tych katow mozna zbudowac prostokat.";
	}
}