/* Author: Yael Farber 
Course: Advanced Programming
Exercise 8 Question 1
Program doc: managing classes of  BA , MA and PHD  students.
it has the options to print the students it get by input and declear if the student can get a milga*/

#pragma once
#include <iostream>

using namespace std;

class Student
{
protected:
    /*fields*/
    int id;
    string firstName;
    string lastName;
    int numberOfCourses;

public:
    /*ctor*/
    Student() : id(0), firstName(""), lastName(""), numberOfCourses(0){};

    /*cpy ctor*/
    Student(const Student &student1);

    /*virtual dtor*/
    virtual ~Student(){};

    /*get methods, return the asked field*/
    int getId() const { return id; };

    int getCourses() const { return numberOfCourses; };

    string getFirstName() const { return firstName; };

    string getLastName() const { return lastName; };

    /*set methods, set the parameter to the asked field*/

    void setId(int id1) { id = id1; };

    void setFirstName(string first) { firstName = first; };

    void setLastName(string last) { lastName = last; };

    void setCourses(int courses1) { numberOfCourses = courses1; }

    /*entry: by a student object of any range, exit: get input and set it to the new student*/
    virtual void input() = 0;

    /*entry: by a student object of any range, exit: print the details of that student object*/
    virtual void print() const = 0;

    /*pure virtual methods*/
    virtual string studType() const = 0;

    virtual bool milga() const = 0;

    virtual float averageGrades() const = 0;

    virtual int getHours() const = 0;

    /*operator methods*/
    virtual bool operator<(const Student &rhs) const = 0;
};
