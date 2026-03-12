#include <iostream>
using namespace std;
int main(){
    int num;
    cout << "Ingrese un numero: ";
    cin >> num;
    int count = 0;
    int og = num;
    int sum = 0;
    int temp = num;
    while (temp > 0) {
        count = count + 1;
        temp /= 10;
    }
    while (num > 0) {
        int digit = num % 10;
        int power = 1;
        for (int i = 0; i < count; i++) {
            power *= digit; 
        }
        sum = sum + power;
        num /= 10;
    }
    if (sum == og) {
        cout << og << " es un numero de Armstrong." << endl;
    } else {
        cout << og << " no es un numero de Armstrong." << endl;
    }
    return 0;
}