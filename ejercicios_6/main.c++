#include <iostream>
#include "meetup.h"
using namespace std;
using namespace meetup;
int main() {
    Date d = meetup_day(2024, 5, Weekday::Monday, Schedule::First);
    cout << "Fecha: "
         << d.year << "-"
         << d.month << "-"
         << d.day << endl;
    return 0;
}