#include<iostream>;
#include <time.h>;
#include<math.h>;
#include<stdlib.h>;
using namespace std;

void Output(float* a, int x) {
    for (int i = 0; i < x; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
}

void InputX(float* a, int x) {
    for (int i = 0; i < x; i++) *(a + i) = (float)(rand() % 2100 - 1000) / 100;
}

void InputY(float* a, int x) {
    for(int i = 0; i < x; i++) *(a+i) = (float)(rand() % 2100 - 1000) / 100;
}

float SummaNeed(float* a, float* b, int x) {
    float ans = 0, summafirst = 0, summasecond = 0;
    for (int i = 0; i < 15; i++) summafirst += *(b + i);
    for (int i = 0; i < x; i++) if (*(a + i) < 0) summasecond += *(a + i);
    return summafirst - summasecond;
}

int main() {

    setlocale(LC_ALL, "Rus");
    srand(time(0));

    cout << "Введите количество элементов массивов -> ";
    int n;
    cin >> n;

    float* x = new float[n];
    InputX(x, n);

    cout << "Массив x: " << endl;
    Output(x, n);

    float* y = new float[n];
    InputY(y, n);

    cout << "Массив y: " << endl;
    Output(y, n);

    cout << "Результат решения задачи = " << SummaNeed(x,y,n);

    delete[] x;
    delete[] y;

    return 0;
}
