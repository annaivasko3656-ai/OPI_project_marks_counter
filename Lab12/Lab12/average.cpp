#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_CTYPE, "Russian");
    int numSubjects;

    cout << "Введите количество предметов: ";
    cin >> numSubjects;

    
    int* grades = new int[numSubjects];

    // Ввод оценок по предметам
    cout << "";
    for (int i = 0; i < numSubjects; i++) {
        do {
            cout << "Предмет #" << i + 1 << " (оценка 2-5): ";
            cin >> grades[i];

            if (grades[i] < 2 || grades[i] > 5) {
                cout << "Ошибка! Оценка должна быть от 2 до 5.\n";
            }
        } while (grades[i] < 2 || grades[i] > 5);
    }

    // Вывод введенных оценок
    cout << "\n=== ВАШИ ОЦЕНКИ ===\n";
    for (int i = 0; i < numSubjects; i++) {
        cout << "Предмет #" << i + 1 << ": " << grades[i] << endl;
    }

    // Вычисление среднего балла
    double sum = 0;
    for (int i = 0; i < numSubjects; i++) {
        sum += grades[i];
    }

    double average = sum / numSubjects;

    // Вывод результата
    cout << fixed << setprecision(2);
    cout << "\n=== РЕЗУЛЬТАТ ===\n";
    cout << "Количество предметов: " << numSubjects << endl;
    cout << "Сумма оценок: " << sum << endl;
    cout << "Средний балл: " << average << endl;

    // Освобождение памяти
    delete[] grades;

    return 0;
}