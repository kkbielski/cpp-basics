#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int ARR_SIZE = 5; //size of the array

int min(int arr[ARR_SIZE][ARR_SIZE]); 
int max(int arr[ARR_SIZE][ARR_SIZE]);

int main() {
	int arr[5][5] = { 0 };

	srand(time(NULL)); //rolls a random number

	for (int i = 0; i < ARR_SIZE; ++i) {
		for (int j = 0; j < ARR_SIZE; ++j) {
			arr[i][j] = 30 + rand() % 30;
		}
	}

	cout << "Min: " << min(arr) << endl;
	cout << "Max: " << max(arr) << endl;
}


int min(int arr[ARR_SIZE][ARR_SIZE]) {
	int min = 60;
	for (int i = 0; i < ARR_SIZE; ++i) {
		for (int j = 0; j < ARR_SIZE; ++j) {
			if (arr[i][j] < min) {
				min = arr[i][j];
			}
		}
	}
	return min;
}
int max(int arr[ARR_SIZE][ARR_SIZE]) {
	int max = 30;
	for (int i = 0; i < ARR_SIZE; ++i) {
		for (int j = 0; j < ARR_SIZE; ++j) {
			if (arr[i][j] > max) {
				max = arr[i][j];
			}
		}
	}
	return max;
}