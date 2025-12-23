#include<iostream>
using namespace std;
void coutFromKeyboard(int size_keyboard, int size,int sum, int B[]) {
	int sum_keyboard=0;
	for (int i = 0; i < size_keyboard; i++) {
		cin >> B[i];
		sum_keyboard += B[i];
	}
	int sum_and_keyboard = sum_keyboard + sum;
	float average_keyboard = sum_and_keyboard / (size + size_keyboard);
	cout << "Средний балл с учётом введённых отметок: " << average_keyboard;
}