#include <iostream>
using namespace std;
void coutAuto(float new_average, int sum, int size) {
    for (int i = 0; (10 - i) > new_average; i++) {
        int count = 0;
        float new_sum = sum;
        while (new_sum / (size + count) < new_average) {
            new_sum += 10 - i;
            count++;
        }
        cout << "надо " << count << " отметок " << 10 - i << "\n";
    }
}
