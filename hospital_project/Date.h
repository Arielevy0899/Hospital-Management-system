#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;

    void printTwoDigit(int num) const {
        if (num < 10) cout << "0";
        cout << num;
    }

public:
    Date() {
        day = 23;
        month = 1;
        year = 2025;
        hour = 12;
        minute = 0;
        second = 0;
    }

    Date(int d, int m, int y, int h = 0, int min = 0, int sec = 0)
        : day(d), month(m), year(y), hour(h), minute(min), second(sec) {
    }

    void showDate() const {
        printTwoDigit(day);
        cout << "/";
        printTwoDigit(month);
        cout << "/" << year << endl;
    }

    void showTime() const {
        printTwoDigit(hour);
        cout << ":";
        printTwoDigit(minute);
        cout << ":";
        printTwoDigit(second);
        cout << endl;
    }

    void showDateTime() const {
        printTwoDigit(day);
        cout << "/";
        printTwoDigit(month);
        cout << "/" << year << " ";
        printTwoDigit(hour);
        cout << ":";
        printTwoDigit(minute);
        cout << ":";
        printTwoDigit(second);
        cout << endl;
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
};

#endif // DATE_H