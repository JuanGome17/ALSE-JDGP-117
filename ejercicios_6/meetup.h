#ifndef MEETUP_H
#define MEETUP_H
namespace meetup {
enum class Weekday {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};
enum class Schedule {
    First, Second, Third, Fourth, Last, Teenth
};
struct Date {
    int year;
    int month;
    int day;
};
Date meetup_day(int year, int month, Weekday weekday, Schedule schedule);
}
#endif