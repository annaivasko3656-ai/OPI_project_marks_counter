#include <iostream>
#include <string>
#include<windows.h>
using namespace std;
void coutMainAverage(int numSubjects, int** grades, int* gradesCount) {
	double totalSum = 0;
	int totalGradesCount = 0;

	// Считаем общую сумму всех оценок и их количество
	for (int i = 0; i < numSubjects; i++) {
		for (int j = 0; j < gradesCount[i]; j++) {
			totalSum += grades[i][j];
			totalGradesCount++;
		}
	}

	// Вычисляем общий средний балл
	double overallAverage = totalSum / totalGradesCount;

	cout << "\n=== ОБЩИЙ СРЕДНИЙ БАЛЛ ===" << endl;
	cout << "Всего предметов: " << numSubjects << endl;
	cout << "Всего оценок: " << totalGradesCount << endl;
	cout << "Общий средний балл: " << overallAverage << endl;
}