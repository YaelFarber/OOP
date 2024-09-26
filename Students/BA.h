/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 8 Question 1
Program doc: managing classes of  BA , MA and PHD  students.
it has the options to print the students it get by input and declear if the student can get a milga*/

#pragma once

#include "Student.h"

class BA : public Student
{
protected:
    /*fields*/
    int *grades;
    int size;

public:
    /*ctor*/
    BA();

    /*dtor*/
    ~BA();

    /*copy ctor*/
    BA(const BA &ba);

    /*move ctor*/
    BA(BA &&ba);

    /*get and set methods*/
    int *getGrades() const { return grades; };

    int getSize() const { return size; };

    void setGrades() { input(); };

    void setSize(const int s) { size = s; };

    /*entry: by a BA student , exit: return 1 if the student can get a milga or 0 if can't */
    virtual bool milga() const override;

    /*entry: by a BA student object, exit: get input and set it to the new BA student*/
    virtual void input() override;

    /*entry: by a BA student object, exit: print the details of that BA student object*/
    virtual void print() const override;

    /*override methods*/
    virtual string studType() const override { return "BA"; };

    /*operator methods*/

    /*entry: by student object + get a student object, exit: return true if the student < the student parameter, as asked in the question*/
    virtual bool operator<(const Student &rhs) const override;

    /*copy assignment operator*/
    BA &operator=(BA &rba);

    /*move assignment operator*/
    BA &operator=(BA &&rba);

    /*entry: by a student object exit: return the average grade*/
    virtual float averageGrades() const override;

    /*return hours of research*/
    virtual int getHours() const override { return 0; };
};
