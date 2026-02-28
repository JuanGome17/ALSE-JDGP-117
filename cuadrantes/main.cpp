#include <iostream>
using namespace std;

struct Point {
    double x;
    double y;
};

int contarPuntosEnCuadrante(Point puntos[], int n, int cuadrante) {
    int contador = 0;

    for (int i = 0; i < n; i++) {
        double x = puntos[i].x;
        double y = puntos[i].y;

        if (x == 0 || y == 0) {
            continue;
        }

        switch (cuadrante) {
            case 1:
                if (x > 0 && y > 0)
                    contador++;
                break;

            case 2:
                if (x < 0 && y > 0)
                    contador++;
                break;

            case 3:
                if (x < 0 && y < 0)
                    contador++;
                break;

            case 4:
                if (x > 0 && y < 0)
                    contador++;
                break;

            default:
                cout << "Cuadrante invalido" << endl;
                return 0;
        }
    }

    return contador;
}

int main() {
    int n;

    cout << "Ingrese cantidad de puntos: ";
    cin >> n;

    Point puntos[n];

    for (int i = 0; i < n; i++) {
        cout << "Punto " << i + 1 << endl;
        cout << "x: ";
        cin >> puntos[i].x;
        cout << "y: ";
        cin >> puntos[i].y;
    }

    int cuadrante;
    cout << "Ingrese cuadrante (1-4): ";
    cin >> cuadrante;

    int resultado = contarPuntosEnCuadrante(puntos, n, cuadrante);

    cout << "Cantidad de puntos en el cuadrante "
         << cuadrante << ": "
         << resultado << endl;

    return 0;
}