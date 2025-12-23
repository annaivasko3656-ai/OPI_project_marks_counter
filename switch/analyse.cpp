#include <iostream>
#include "analyseMarks.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    const int size = 3;
    float average, sum = 0;
    int A[size] = { 2,2,2 };

    for (int i = 0; i < size; i++) {
        sum += A[i];
    }

    cout << "Выберите следующее действие и введите соответствующую цифру:\n";
    cout << "1.Посчитать сколько и какие отметки надо получить для достижения определённого среднего балла\n";
    cout << "2.Посчитать как изменится средний балл если получить определённые отметки\n";
    cout << "3.Выбрать другие операции или предмет\n";

    int choice;
    cin >> choice;

    average = sum / size;

    switch (choice) {
    case 1: {

        float new_average;
        cout << "Введите желаемый средний балл: ";
        cin >> new_average;

        coutAuto(new_average, sum, size);
        break;
    }
    case 2: {
        cout << "Сколько отметок вы хотите добавить? ";
        int size_keyboard;
        cin >> size_keyboard;
        cout << "Введите отметки ";
        int* B = new int[size_keyboard];
        coutFromKeyboard(size_keyboard,size, sum, B);
        break;
    }
    case 3: {
        
    }
    }
    return 0;

}
