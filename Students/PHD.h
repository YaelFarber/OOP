/* Author: Yael Farber
Course: Advanced Programming
Exercise 8 Question 1
Program doc: managing classes of  BA , MA and PHD  students.
it has the options to print the students it get by input and declear if the student can get a milga*/

#pragma once
using namespace std;

#include "Student.h"

class PHD : public Student
{
private:
    /*fields*/
    int hours;

public:
    /*ctor*/
    PHD() : hours(0){};

    /*get and set methods*/
    int getHours() const override { return hours; };

    void setHours(int h) { hours = h; };

    /*entry: by a PHD student , exit: return 1 if the student can get a milga or 0 if can't */
    virtual bool milga() const override;

    /*entry: by a PHD student object, exit: get input and set it to the new PHD student*/
    virtual void input() override;

    /*entry: by a PHD student object, exit: print the details of that PHD student object*/
    virtual void print() const override;

    /*override methods*/
    string studType() const override { return "PHD"; };

    /*entry: by student object + get a student object, exit: return true if the student < the student parameter, as asked in the question*/
    virtual bool operator<(const Student &rhs) const override;

    /*(impliment so PHD won't be abstact)*/
    /*return hours of research*/
    virtual float averageGrades() const override { return 0; };
};
