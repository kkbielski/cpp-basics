#include "pch.h"
#include <iostream>


int main()
{
	double a; //deklarujemy trzy zmienne
	double b;
	double c;
	


	std::cout << "Hello World!\n";
	//program wita się z użytkownikiem
	std::cout << "Give me the first length and confirm with enter:";
	//program prosi o długość boku
	std::cin >> a;
	//użytkownik wpisuje daną długość
	std::cout << "Give me the second length and confirm with enter:";
	std::cin >> b;
	c = sqrt(a*a + b * b);
	//deklarujemy funkcję obliczającą długość trzeciego boku
	std::cout << "The third length is equal to: " << c;
	//program podaje wynik zgodnie z twierdzeniem Pitagorasa
}


