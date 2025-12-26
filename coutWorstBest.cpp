#include <iostream>
#include <string>
#include<windows.h>
using namespace std;
void coutWorstBest(int numSubjects, int** grades, int* gradesCount, string* subjects){
double* allAverages = new double[numSubjects];

// Вычисляем средние баллы для каждого предмета
for (int i = 0; i < numSubjects; i++) {
	double sum = 0;
	for (int j = 0; j < gradesCount[i]; j++) {
		sum += grades[i][j];
	}
	allAverages[i] = sum / gradesCount[i];
}

// Находим лучший и худший средний балл
double best = allAverages[0];
double worst = allAverages[0];
int bestIndex = 0;
int worstIndex = 0;

for (int i = 1; i < numSubjects; i++) {
	if (allAverages[i] > best) {
		best = allAverages[i];
		bestIndex = i;
	}
	if (allAverages[i] < worst) {
		worst = allAverages[i];
		worstIndex = i;
	}
}

cout << "\n=== ЛУЧШИЙ/ХУДШИЙ СРЕДНИЙ БАЛЛ ===" << endl;
cout << "Лучший средний балл: " << best
<< " (предмет: " << subjects[bestIndex] << ")" << endl;
cout << "Худший средний балл: " << worst
<< " (предмет: " << subjects[worstIndex] << ")" << endl;

// Освобождаем память
delete[] allAverages;
}