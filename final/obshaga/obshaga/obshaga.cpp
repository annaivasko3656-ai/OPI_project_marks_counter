#include <iostream>
#include <string>
#include<windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru_RU.UTF-8");
	setlocale(LC_ALL, "Russian");
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
		cin.ignore();
		while (cin.fail() || numSubjects <= 0 || numSubjects >= 30) { //проверка правильности ввода
			cout << "Вы ввели неверный символ.Попробуйте ещё раз.\n";
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Количество оценок: ";
			cin >> numSubjects;
		}
		// Выделение памяти под оценки
		grades[i] = new int[gradesCount[i]];

		// Ввод оценок
		cout << "Введите " << gradesCount[i] << " оценок:\n";
		for (int j = 0; j < gradesCount[i]; j++) {
			cout << "Оценка " << j + 1 << ": ";
			int num;
			cin >> num;
			if (num < 1 || num > 10) {
				cout << "Оценка должна быть от 1 до 10" << endl;
			}
			else {
				grades[i][j] = num;
			}

		}
		std::cin.ignore();
	}
	cout << "1.Продолжить работу\n";
	cout << "2.Выход\n";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1: {
		cout << "Введите название предмета\n";
		string searchSubject;
		cin >> searchSubject;

		// Поиск предмета
		int foundIndex = -1;
		for (int i = 0; i < numSubjects; i++) {
			if (subjects[i] == searchSubject) {
				foundIndex = i;
				break;
			}
		}


		cout << "1.Cредний балл\n";
		cout << "2.Подсчитать,как можно изменить средний балл\n";
		cout << "3.График\n";
		cout << "4.Лучший/Худший среедний балл\n";
		cout << "5.Общий средний балл\n";
		cout << "6.Выход";
		int choice1;
		cin >> choice1;
		switch (choice1) {
		case 1: {

		}
		case 2: {
			//Analyse.cpp
		}
		case 3: {

		}
		case 4: {

		}
		case 5: {

		}
		case 6: {
			cout << "Конец программыs" << endl;
		}
		}
	}
	case 2: {
		cout << "Конец программы" << endl;
	}
	}
}