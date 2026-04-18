#include <iostream>
using namespace std;
class Clock {
private:
    int hours;
    int minutes;
    void normalize() {
        int totalMinutes = hours * 60 + minutes;
        totalMinutes = ((totalMinutes % (24 * 60)) + (24 * 60)) % (24 * 60);
        hours = totalMinutes / 60;
        minutes = totalMinutes % 60;
    }
public:
    Clock(int h, int m) {
        hours = h;
        minutes = m;
        normalize();
    }
    void addMinutes(int m) {
        minutes += m;
        normalize();
    }
    void subtractMinutes(int m) {
        minutes -= m;
        normalize();
    }
    bool equals(const Clock& other) const {
        return hours == other.hours && minutes == other.minutes;
    }
    void display() const {
        if (hours < 10) cout << "0";
        cout << hours << ":";
        if (minutes < 10) cout << "0";
        cout << minutes << endl;
    }
};
int main() {
    Clock c1(10, 30);
    Clock c2(9, 90); // debería ser igual a 10:30
    c1.display();
    c2.display();
    if (c1.equals(c2)) {
        cout << "Son iguales" << endl;
    } else {
        cout << "No son iguales" << endl;
    }
    c1.addMinutes(40);
    c1.display();
    c1.subtractMinutes(70);
    c1.display(); // 10:00
    return 0;
}