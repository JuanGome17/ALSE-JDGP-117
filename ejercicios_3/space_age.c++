#include <iostream>
using namespace std;
class space_age {
private:
    long long seconds;
public:
    space_age(long long s) {
        seconds = s;
    }
    double on_earth() {
        return seconds / 31557600.0;
    }
    double on_mercury() {
        return on_earth() / 0.2408467;
    }
    double on_venus() {
        return on_earth() / 0.61519726;
    }
    double on_mars() {
        return on_earth() / 1.8808158;
    }
    double on_jupiter() {
        return on_earth() / 11.862615;
    }
    double on_saturn() {
        return on_earth() / 29.447498;
    }
    double on_uranus() {
        return on_earth() / 84.016846;
    }
    double on_neptune() {
        return on_earth() / 164.79132;
    }
};
int main() {
    long long seconds;
    cout << "Ingrese su edad en segundos: ";
    cin >> seconds;
    space_age age(seconds);
    cout << "Edad en la Tierra: " << age.on_earth() << endl;
    cout << "Edad en Mercurio: " << age.on_mercury() << endl;
    cout << "Edad en Venus: " << age.on_venus() << endl;
    cout << "Edad en Marte: " << age.on_mars() << endl;
    cout << "Edad en Jupiter: " << age.on_jupiter() << endl;
    cout << "Edad en Saturno: " << age.on_saturn() << endl;
    cout << "Edad en Urano: " << age.on_uranus() << endl;
    cout << "Edad en Neptuno: " << age.on_neptune() << endl;
    return 0;
}