/* Author: Yael Farber 
Course: Advanced Programming
Targil 5 Sheela 1
Program doc: creating a class that manage ATM, with the options to create account, deposite or withdraw nis */

#include "Clock.h"

/*ctor*/

Clock::Clock(int _hour, int _minutes, int _second)
{
    if (_second < 0)
        throw "Invalid time - negative number of seconds.\n";
    if (_second > 60)
        throw "Invalid time - more than 60 seconds.\n";
    if (_minutes < 0)
        throw "Invalid time - negative number of minutes.\n";
    if (_minutes > 60)
        throw "Invalid time - more than 60 minutes.\n";
    if (_hour < 0)
        throw "Invalid time - negative number of hours.\n";
    if (_hour > 24)
        throw "Invalid time - more than 24 hours.\n";

    hour = _hour;
    minute = _minutes;
    second = _second;
}

/*set methods*/

/*entry: get a clock object parameter, exit: set the hour as the parameter hour*/
void Clock::setHour(const Clock &time)
{
    if (hour > 0 && hour <= 24)
        hour = time.hour;
}

/*entry: get a clock object parameter, exit: set the minute as the parameter minute*/
void Clock::setMinute(const Clock &time)
{
    if (minute > 0 && minute <= 60)
        minute = time.minute;
}

/*entry: get a clock object parameter, exit: set the second as the parameter second*/
void Clock::setSecond(const Clock &time)
{
    if (second > 0 && second <= 60)
        second = time.second;
}

/*operator methods*/

/*entry: by  a clock obj + get seconds parameter, exit: add the parameter to the hour in a clean way*/
Clock &Clock::operator+=(const int s)
{

    if (second + s < 60) /*minutes won't change*/
        second += s;
    else
    {
        if (((second + s) / 60 + minute) < 60) /*hour won't change*/
        {
            minute += (second + s) / 60;
            second = (second + s) % 60;
        }
        else
        {
            if (((second + s) / 120 + minute / 60 + hour) < 24) /*right hour*/
            {
                hour += (second + s) / 120 + minute / 60;
                minute = minute % 60 + (second + s) / 60;
                second = (second + s) % 120;
            }
            else
            {
                hour += (second + s) / 120 + minute / 60 - 24; /* fix the error of => hour > 24*/
                second = 0;
                minute = 0;
            }
        }
    }
    return *this;
}

/*print in format: hh:mm:ss */
/*entry: by operator <<clock object ,exit: print the clock object in in format: hh:mm:ss*/
ostream &operator<<(ostream &os, const Clock &clock1)
{
    if (clock1.hour < 10)
        os << '0';
    os << clock1.hour << ":";
    if (clock1.minute < 10)
        os << '0';
    os << clock1.minute << ":";
    if (clock1.second < 10)
        os << '0';
    os << clock1.second;
    return os;
}

/*get in format: hh:mm:ss */
/*entry: by operator >>clock object ,exit: get input of clock object in in format: hh:mm:ss*/
istream &operator>>(istream &is, Clock &clock1)
{
    int _hour, _minute, _second;
    char colon1, colon2;
    is >> clock1.hour >> colon1 >> clock1.minute >> colon2 >> clock1.second;
    if (colon1 != ':' || colon2 != ':')
    {
        clock1.hour = 0;
        clock1.minute = 0;
        clock1.second = 0;
        throw "Wrong time format. \n";
    }

    clock1.hour = _hour;
    clock1.minute = _minute;
    clock1.second = _second;

    return is;
}
