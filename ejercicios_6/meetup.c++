#include "meetup.h"
namespace meetup {
int day_of_week(int y, int m, int d) {
    if (m < 3) {
        m += 12;
        y--;
    }
    int K = y % 100;
    int J = y / 100;
    int h = (d + (13*(m+1))/5 + K + K/4 + J/4 + 5*J) % 7;
    return (h + 5) % 7;
}
int days_in_month(int year, int month) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            return 29;
        return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;

    return 31;
}
Date meetup_day(int year, int month, Weekday weekday, Schedule schedule) {
    int target = static_cast<int>(weekday);
    int count = 0;
    int last_match = 0;
    for (int d = 1; d <= days_in_month(year, month); d++) {
        if (day_of_week(year, month, d) == target) {
            count++;
            last_match = d;
            if (schedule == Schedule::First && count == 1)
                return {year, month, d};
            if (schedule == Schedule::Second && count == 2)
                return {year, month, d};
            if (schedule == Schedule::Third && count == 3)
                return {year, month, d};
            if (schedule == Schedule::Fourth && count == 4)
                return {year, month, d};

            if (schedule == Schedule::Teenth && d >= 13 && d <= 19)
                return {year, month, d};
        }
    }
    return {year, month, last_match};
}
}