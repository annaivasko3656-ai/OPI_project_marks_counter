#pragma once
#include <iostream>
#include <string>
#include <iomanip>  // Добавлено для setw, fixed, setprecision
#include <windows.h>
using namespace std;

void makeGraph(int numSubjects, int** grades, int* gradesCount, string* subjects) {
    // Проверяем, есть ли вообще предметы
    if (numSubjects <= 0) {
        cout << "Нет данных для построения графика!\n" << endl;
        return;  // Исправлено: break -> return
    }

    // Рассчитываем средние баллы для каждого предмета
    double* averages = new double[numSubjects];
    bool hasData = false;
    for (int i = 0; i < numSubjects; i++) {
        if (gradesCount[i] > 0) {
            int sum = 0;
            for (int j = 0; j < gradesCount[i]; j++) {
                sum += grades[i][j];
            }
            averages[i] = (double)sum / gradesCount[i];
            hasData = true;
        }
        else {
            averages[i] = 0.0;
        }
    }

    if (!hasData) {
        cout << "Нет данных для построения графика (все предметы без оценок)!\n" << endl;
        delete[] averages;
        return;  // Исправлено: break -> return
    }

    // Находим максимальный средний балл для масштабирования графика
    double maxAvg = 0.0;
    for (int i = 0; i < numSubjects; i++) {
        if (averages[i] > maxAvg) {
            maxAvg = averages[i];
        }
    }

    // Если все средние баллы равны 0
    if (maxAvg == 0.0) {
        cout << "Нет данных для построения графика (все средние баллы равны 0)!\n" << endl;
        delete[] averages;
        return;  // Исправлено: break -> return
    }

    // Определяем высоту графика
    const int HEIGHT = 10;

    // Создаем массив для меток
    string* labels = new string[numSubjects];

    // Генерируем метки для каждого предмета
    for (int i = 0; i < numSubjects; i++) {
        string label = "";
        // Начинаем с первого символа
        for (int len = 1; len <= subjects[i].length(); len++) {
            label = subjects[i].substr(0, len);
            bool isUnique = true;

            // Проверяем уникальность этой метки
            for (int j = 0; j < i; j++) {
                if (labels[j] == label) {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique) {
                break;
            }
        }
        labels[i] = label;

        // Если метка слишком длинная, обрезаем до 3 символов
        if (labels[i].length() > 3) {
            labels[i] = labels[i].substr(0, 3);
        }
    }

    // Построение вертикального графика сверху вниз
    cout << "\n=================================================" << endl;
    cout << "ГРАФИК СРЕДНИХ БАЛЛОВ ПО ПРЕДМЕТАМ" << endl;
    cout << "=================================================\n" << endl;

    // Построение графика сверху вниз
    for (int level = HEIGHT; level > 0; level--) {
        // Вычисляем порог для текущей строки
        double threshold = (maxAvg / HEIGHT) * level;

        // Выводим левую метку уровня
        if (level == HEIGHT) {
            cout << setw(5) << fixed << setprecision(1) << maxAvg << "-| ";
        }
        else if (level == 1) {
            cout << "  0.0-| ";
        }
        else {
            cout << "      | ";
        }

        // Выводим столбцы для каждого предмета
        for (int i = 0; i < numSubjects; i++) {
            if (averages[i] >= threshold) {
                cout << "***";  // Столбец - 3 символа
            }
            else {
                cout << "   ";  // Пустое место - ТОЖЕ 3 символа!
            }

            // ОДИН пробел между столбцами (не добавляем лишних пробелов!)
            if (i < numSubjects - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    // Линия под графиком - должна соответствовать ширине столбцов
    cout << "      |-";
    for (int i = 0; i < numSubjects; i++) {
        cout << "---";  // Три черточки для столбца
        if (i < numSubjects - 1) {
            cout << "-";  // Одна черточка для расстояния
        }
    }
    cout << endl;

    // Подписи под графиком
    cout << "        ";
    for (int i = 0; i < numSubjects; i++) {
        // Выводим метку предмета с выравниванием
        string label = labels[i];
        int labelLength = label.length();

        // Все метки выравниваем в 3 символа
        if (labelLength == 1) {
            cout << " " << label << " ";  // Пробел слева и пробел справа
        }
        else if (labelLength == 2) {
            cout << label << " ";  // Два символа + пробел справа
        }
        else if (labelLength == 3) {
            cout << label;  // Три символа без пробелов
        }

        // ОДИН пробел между метками
        if (i < numSubjects - 1) {
            cout << " ";
        }
    }
    cout << endl;

    // Расшифровка меток
    cout << "\n=================================================" << endl;
    cout << "Расшифровка меток:" << endl;
    for (int i = 0; i < numSubjects; i++) {
        cout << labels[i] << " = " << subjects[i] << " (ср. балл: "
            << fixed << setprecision(2) << averages[i] << ")" << endl;
    }
    cout << "=================================================\n" << endl;

    // Очистка памяти
    delete[] averages;
    delete[] labels;
}