#include <time.h>;
#include<math.h>;
#include <iostream>
using namespace std;

void input(int* a, int x) {
    for (int i = 0; i < x; i++) {
        *(a + i) = rand() % 101 - 50;
    }
}

void output(int* a, int x) {
    for (int i = 0; i < x; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
}

int Min(int* arr, int len) {
    int min = 100, indexmin = 0;
    for (int i = 0; i < len; i++) {
        if (abs(*(arr + i)) < abs(min)) {
            min = abs(*(arr + i));
            indexmin = i;
        }
    }
    return min;
}

int Max(int* arr, int len) {
    int max = 0, indexmax = 0;
    for (int i = 0; i < len; i++) {
        if (abs(*(arr + i)) > abs(max)) {
            max = abs(*(arr + i));
            indexmax = i;
        }
    }
    return max;
}

int MaxIndex(int* arr, int len) {
    int max = 0, indexmax = 0;
    for (int i = 0; i < len; i++) {
        if (abs(*(arr + i)) > abs(max)) {
            max = abs(*(arr + i));
            indexmax = i;
        }
    }
    return indexmax;
}

int MinIndex(int* arr, int len) {
    int min = 999, indexmin = 0;
    for (int i = 0; i < len; i++) {
        if (abs(*(arr + i)) < abs(min)) {
            min = abs(*(arr + i));
            indexmin = i;
        }
    }
    return indexmin;
}

int SummOfPlus(int* arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        if (*(arr + i) > 0) sum += *(arr + i);
    }
    cout << "Сумма положительных элементов массива равна ";
    return sum;
}

int Sandwitch(int* arr, int len) {
    int ans = 1;
    int indexmax = MaxIndex(arr, len);
    int indexmin = MinIndex(arr, len);
    if ((indexmin - indexmax) > 2) {
        for (int i = indexmax + 1; i < indexmin; i++) {
            ans *= *(arr + i);
        }
    }
    else if ((indexmax - indexmin) > 2) {
        for (int i = indexmin + 1; i < indexmax; i++) {
            ans *= *(arr + i);
        }
    }
    return ans;
}


int main(){

    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int size;
    cout << "Введите размер массива -> ";
    cin >> size;

    int* arr = new int[size];

    input(arr, size);

    cout << "Исходный массив:" << "\n";
    output(arr, size);

    cout << SummOfPlus(arr, size);

    if (Sandwitch(arr, size) == 1) cout << endl << "Междду элементами нечего умножать";
    else cout << endl << "Произведение между макс. и мин. равно " << Sandwitch(arr, size);

    delete[] arr;

    return 0;
}
