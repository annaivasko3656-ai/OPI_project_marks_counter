#include <iostream>
#include <string>
#include<windows.h>
using namespace std;
void coutAverageForOne(int* subjectGradesArray, int subjectGradesCount,int foundIndex, string* subjects) {
	//средний балл для 1 предмета
	double sum = 0;

	// Считаем сумму оценок
	for (int j = 0; j < subjectGradesCount; j++) {
		sum += subjectGradesArray[j];
	}

	// Вычисляем средний балл
	double average = sum / subjectGradesCount;

	// Выводим результат
	cout << "\n=== РЕЗУЛЬТАТЫ ПО ПРЕДМЕТУ ===" << endl;
	cout << "Предмет: " << subjects[foundIndex] << endl;
	cout << "Количество оценок: " << subjectGradesCount << endl;
	cout << "Средний балл: " << average << endl;
}