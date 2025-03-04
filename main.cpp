#include <iomanip>
#include<iostream>
using namespace std;

int main(){

    setlocale(LC_ALL,"Rus");

    int a;
    cin >> a;
    cout << (a*10) / 100 << endl;
    cout << a/10; 

    return 0;
}