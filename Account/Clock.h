/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Targil 5 Sheela 1
Program doc: creating a class that manage ATM, with the options to create account, deposite or withdraw nis */

#pragma once
#include <iostream>
using namespace std;

class Clock
{
private:
    /*fields*/

    int hour = 0;

    int minute = 0;

    int second = 0;

public:
    /*ctor*/

    Clock(int _hour, int _minutes, int _second);

    /*get methods*/

    int getHour() const { return hour; }; /*entry: by clock object, exit: return the hour*/

    int getMinute() const { return minute; }; /*entry: by clock object, exit: return the minute*/

    int getSecond() const { return second; }; /*entry: by clock object, exit: return the second*/

    /*set methods*/

    void setHour(const Clock &time); /*entry: get a clock object parameter, exit: set the hour as the parameter hour*/

    void setMinute(const Clock &time); /*entry: get a clock object parameter, exit: set the minute as the parameter minute*/

    void setSecond(const Clock &time); /*entry: get a clock object parameter, exit: set the second as the parameter second*/

    /*equal hours*/

    bool equals(const int _hour) const { return hour == _hour; }; /*entry: by a clock object + get an hour parameter, exit: return true if the hour equals to the parameter ,else return false*/

    bool before(const int _hour) const { return hour < _hour; }; /*entry: by a clock object + get an hour parameter, exit: return true if the hour less than the parameter ,else return false*/

    bool after(const int _hour) const { return hour > _hour; }; /*entry: by a clock object + get an hour parameter, exit: return true if the hour greater than the parameter ,else return false*/

    /*operator methods*/

    Clock &operator+=(const int add_seconds); /*entry: by  a clock obj + get seconds parameter, exit: add the parameter to the hour in a clean way*/

    /*print in format: hh:mm:ss */
    friend ostream &operator<<(ostream &os, const Clock &clock1); /*entry: by operator <<clock object ,exit: print the clock object in in format: hh:mm:ss*/

    /*get in format: hh:mm:ss */
    friend istream &operator>>(istream &is, Clock &clock1); /*entry: by operator >>clock object ,exit: get input of clock object in in format: hh:mm:ss*/
};