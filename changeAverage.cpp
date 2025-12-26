#include <iostream>
#include <string>
#include<windows.h>
using namespace std;

void changeAverage(int* subjectGradesArray, int size, float sum) {
    int choice; 
    int subjectGradesCount = size; 

    do {
        cout << "\nВыберите следующее действие и введите соответствующую цифру:\n\n";
        cout << "1. Посчитать сколько и какие отметки надо получить для достижения определённого среднего балла\n";
        cout << "2. Посчитать как изменится средний балл если получить определённые отметки\n";
        cout << "3. Выбрать другие операции или предмет (выход)\n";
        cout << "\nВыбранная операция: ";
        cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3) { //проверка правильности ввода
            cout << "Вы ввели неверное число. Попробуйте ещё раз.";
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nВыбранная операция: ";
            cin >> choice;
        }

        float average = sum / size;

        switch (choice) {
        case 1: {
            float new_average;
            cout << "Введите желаемый средний балл: ";
            cin >> new_average;
            while (new_average < 1 || new_average > 10) {
                cout << "Вы ввели неверное число. Попробуйте ещё раз.";
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nЖелаемый средний балл: ";
                cin >> new_average;
            }

            // Специальная обработка для желаемого балла 10
            if (new_average == 10) {
                // Проверяем, возможно ли достичь 10
                if (sum == 10 * size) {
                    cout << "Средний балл уже равен 10\n";
                }
                else {
                    // Вычисляем сколько нужно 10-ок
                    int count = 0;
                    float new_sum = sum;
                    // Используем <= 10 - 0.001 для учета погрешности float
                    while (new_sum / (size + count) <= 10 - 0.001) {
                        new_sum += 10;
                        count++;
                    }
                    cout << "Надо " << count << " отметок 10\n";
                }
            }
            else {
                // Для остальных случаев
                for (int i = 0; (10 - i) >= new_average; i++) {
                    int count = 0;
                    float new_sum = sum;
                    while (new_sum / (size + count) < new_average) {
                        new_sum += 10 - i;
                        count++;
                    }
                    // Выводим только если есть решение
                    if (count > 0) {
                        cout << "Надо " << count << " отметок " << 10 - i << "\n";
                    }
                }
            }
            break;
        }
        case 2: {
            cout << "Сколько отметок вы хотите добавить? ";
            int size_keyboard;
            cin >> size_keyboard;
            while (cin.fail() || size_keyboard < 0 || size_keyboard>40) {//проверка правильности ввода
                cout << "Вы ввели неверное число.Попробуйте ещё раз.";
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nКоличество вводимых отметок: ";
                cin >> size_keyboard;
            }
            cout << "Введите отметки: ";
            int* B = new int[size_keyboard];
            int sum_keyboard = 0;
            for (int i = 0; i < size_keyboard; i++) {
                cin >> B[i];
                while (cin.fail() || B[i] < 0 || B[i]>10) {//проверка правильности ввода
                    cout << "Вы ввели неверную отметку.Попробуйте ещё раз.";
                    cin.clear();
                    cin.ignore(100, '\n');
                    cin >> B[i];
                }
                sum_keyboard += B[i];
            }
            int sum_and_keyboard = sum_keyboard + sum;
            float average_keyboard = (float)sum_and_keyboard / (size + size_keyboard);
            cout << "Средний балл с учётом введённых отметок: " << average_keyboard << "\n";
            delete[] B;
            break;
        }
        case 3: {
            cout << "Выход из программы.\n";
            break;
        }
        default:
            cout << "Неверный выбор, попробуйте снова.\n";
        }

    } while (choice != 3);
}