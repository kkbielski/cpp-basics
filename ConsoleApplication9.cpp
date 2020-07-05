#include "pch.h"
#include <iostream>

using namespace std;

int main() {

	int x[3][3] = { {0,1,3}, {2,3,6}, {4,5,9} };
	int y[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			y[i][j] = x[j][i];
			cout << "x[" << i << "][" << j << "]: ";
			cout << x[i][j] << endl;
		}
	}
	cout << "\n ------ \n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "y[" << i << "][" << j << "]: ";
			cout << y[i][j] << endl;
		}
	}
	return 0;
}


