#include <iostream>
using namespace std;
int main(){
    string c1, c2;
    cout << "Ingrese la primera cadena: ";
    cin >> c1;
    cout << "Ingrese la segunda cadena: ";
    cin >> c2;
    if (c1.length() != c2.length()) {
        cout << "Las cadenas no son de la misma longitud." << endl;
        return 0;
    }
    int HamDist = 0;
    for (int i = 0; i < c1.length(); i++) {
        if (c1[i] != c2[i]) {
            HamDist++;
        }
    }
    cout << "La distancia de Hamming es: " << HamDist << endl;
    return 0;
}