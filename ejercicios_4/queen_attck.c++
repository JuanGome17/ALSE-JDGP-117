#include <iostream>
#include <cmath>
using namespace std;
bool PuedeAtacar(int fil1, int col1, int fil2, int col2) {
    if (fil1 == fil2 ) return true;
    if (col1 == col2 ) return true;
    if (abs(fil1 - fil2) == abs(col1 - col2)) return true;
    return false;
}
int main() {
    int fil1 = 7, col1 = 2;
    int fil2 = 6, col2 = 3;
    if (PuedeAtacar(fil1, col1, fil2, col2)) {
        cout << "Las reinas pueden atacarse entre sí." << endl;
    } else {
        cout << "Las reinas no pueden atacarse entre sí." << endl;
    }
    return 0;
}