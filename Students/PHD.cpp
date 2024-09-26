/* Author: Yael Farber
Course: Advanced Programming
Exercise 8 Question 1
Program doc: managing classes of  BA , MA and PHD  students.
it has the options to print the students it get by input and declear if the student can get a milga*/

#include "PHD.h"

/*entry: by a PHD student , exit: return 1 if the student can get a milga or 0 if can't */
bool PHD::milga() const
{
    return this->getCourses() >= 2 && hours > 25;
}

/*entry: by a PHD student object, exit: get input and set it to the new PHD student*/
void PHD::input()
{
    int hours1;
    Student::input();
    cout << "enter number of research hours \n";
    cin >> hours1;
    if (hours1 < 0)
        throw "Invalid hour\n";
    hours = hours1;
}

/*entry: by a PHD student object, exit: print the details of that PHD student object*/
void PHD::print() const
{
    Student::print();
    cout << "Number of research Hours: " << hours << endl;
}

/*entry: by student object + get a student object, exit: return true if the student < the student parameter, as asked in the question*/
bool PHD::  operator<(const Student &rhs) const 
{
    if (this->studType() != rhs.studType())
        cout << "cannot compare students of different types\n";
    if (!this->milga() && rhs.milga())
        return true;
    if (this->milga() && !rhs.milga())
        return false;
    if ((this->milga() && rhs.milga()) || !this->milga() && !rhs.milga())
        if (this->getHours() <rhs.getHours())
            return true;

    return false;
}
