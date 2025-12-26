#include <iostream>
#include <string>
#include <windows.h>
#include "coutMainAverage.h"
#include "coutWorstBest.h"
#include "coutAverageForOne.h"
#include "makeGraph.h"
#include "changeAverage.h"
using namespace std;

int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru_RU.UTF-8");
	setlocale(LC_ALL, "Russian");
	cout << "Добро пожаловать\n";
	// Запрашиваем количество предметов
	int numSubjects;
	cout << "Введите количество предметов: ";
	cin >> numSubjects;
	//проверка
	while (cin.fail() || numSubjects <= 0 || numSubjects >= 30) { //проверка правильности ввода
		cout << "Вы ввели неверный символ.Попробуйте ещё раз.\n";
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Количество предметов: ";
		cin >> numSubjects;
	}
	cin.ignore();

	// Динамические массивы
	string* subjects = new string[numSubjects];
	int* gradesCount = new int[numSubjects];
	int** grades = new int* [numSubjects];  // Это массив указателей для динамического многомерного массива
	// Ввод данных
	for (int i = 0; i < numSubjects; i++) {
		cout << "\nПредмет #" << i + 1 << ":\n";

		//проверка
		cout << "Введите название предмета: ";
		getline(cin, subjects[i]);

		//проверка
		while (true) {
			unsigned int pos = 0;  // Другое имя для счётчика!

			for (; pos < subjects[i].length(); pos++) {
				unsigned char c = subjects[i][pos];  // subjects[i][pos] - правильно!

				if (!((c >= 0xC0 && c <= 0xFF) || c == ' ' || c == 0xA8 || c == 0xB8)) {
					break;
				}
			}

			if (!cin.fail() && pos == subjects[i].length() && subjects[i].length() > 0) {
				break;
			}

			cout << "Вы допустили ошибку при вводе. Попробуйте ещё раз.\n";
			cin.clear();
			getline(cin, subjects[i]);
		}
		// Ввод количества оценок
		cout << "Введите количество оценок для предмета " << subjects[i] << ": ";
		cin >> gradesCount[i];

		while (cin.fail() || gradesCount[i] <= 0) { // Правильная проверка для количества оценок
			cout << "Вы ввели неверное значение. Количество оценок должно быть положительным числом.\n";
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Введите количество оценок для предмета " << subjects[i] << ": ";
			cin >> gradesCount[i];
		}
		cin.ignore();
		// Выделение памяти под оценки
		grades[i] = new int[gradesCount[i]];

		// Ввод оценок
		cout << "Введите " << gradesCount[i] << " оценок:\n";
		for (int j = 0; j < gradesCount[i]; j++) {
			cout << "Оценка " << j + 1 << ": ";
			int num;
			cin >> num;
			while (cin.fail() || num < 0 || num > 10) { //проверка правильности ввода
				cout << "Вы ввели неверный символ.Попробуйте ещё раз.\n";
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Оценка " << j + 1 << ": ";
				cin >> num;
			}
			grades[i][j] = num;
		}


		std::cin.ignore();
	}
	cout << "1.Продолжить работу\n";
	cout << "2.Подсчёт общего среднего балла\n";
	cout << "3.Лучший и худший\n";
	cout << "4.График";
	cout << "5.Выход";
	int choice;
	cin >> choice;
	while (cin.fail() || choice != 1 && choice != 2 && choice!=3 && choice != 4 && choice != 5) { //проверка правильности ввода
		cout << "Вы ввели неверный символ.Попробуйте ещё раз.\n";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> choice;
	}
	switch (choice) {
	case 1: {
	
		// Поиск предмета
		int foundIndex;
		string searchSubject;

		do {
			cout << "Введите название предмета: ";
			cin >> searchSubject;

			foundIndex = -1;
			for (int i = 0; i < numSubjects; i++) {
				if (subjects[i] == searchSubject) {
					foundIndex = i;
					break;
				}
			}

			if (foundIndex == -1) {
				cout << "Предмет \"" << searchSubject << "\" не найден. Попробуйте снова.\n";
			}

		} while (foundIndex == -1);

		int subjectGradesCount = gradesCount[foundIndex];
		int* subjectGradesArray = new int[subjectGradesCount];

		// Копируем оценки в одномерный массив
		for (int j = 0; j < subjectGradesCount; j++) {
			subjectGradesArray[j] = grades[foundIndex][j];
		}

		// Выводим результат
		cout << "\nОценки по предмету \"" << subjects[foundIndex] << "\":\n";
		for (int j = 0; j < subjectGradesCount; j++) {
			cout << " " << subjectGradesArray[j];
		}

		cout << "\n1.Cредний балл для введённого предмета\n";
		cout << "2.Подсчитать,как можно изменить средний балл\n";
		cout << "3.Выход\n";
		int choice1;
		cin >> choice1;
		while (cin.fail() || choice1 != 1 && choice1 != 2 && choice1 != 3 && choice1 != 4 && choice1 != 5 && choice1 != 6) { //проверка правильности ввода
			cout << "Вы ввели неверный символ.Попробуйте ещё раз.\n";
			cin.clear();
			cin.ignore(100, '\n');
			cin >> choice1;
		}
		 
			switch (choice1) {
			case 1: {
				coutAverageForOne(subjectGradesArray,subjectGradesCount,foundIndex,subjects);
				break;
			}
			case 2: {
				float sum = 0;
				for (int j = 0; j < subjectGradesCount; j++) {
					sum += subjectGradesArray[j];
				}
				changeAverage(subjectGradesArray, subjectGradesCount, sum);
			}
			case 3: {
				cout << "Конец программы" << endl;
			}
			}
	}
	case 2: {
		coutMainAverage(numSubjects,grades,gradesCount);
		break;
	}
	case 3: {
		coutWorstBest(numSubjects,grades,gradesCount,subjects);
		break;
	}
	case 4: {
		makeGraph(numSubjects, grades, gradesCount, subjects);
		break;
	}
	}
}