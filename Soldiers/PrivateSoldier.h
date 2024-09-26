/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 9 Question 1
Program doc: managing classes of  private , commander and officer soldiers and the medals they get.
it has options to add new soldiers print those who deserves medal print the commander with the highest sociometric score and so on..
you can choose an operation from the menu in the main page of the program.*/

#include "Soldier.h"
#pragma once

class PrivateSoldier : public Soldier
{
protected:
    int *grades;

public:
    /*rule of 5*/

    /*ctor*/
    PrivateSoldier();

    /*dtor*/
    ~PrivateSoldier();

    /*cpy ctor*/
    PrivateSoldier(const PrivateSoldier &ps);

    /*move ctor*/
    PrivateSoldier(PrivateSoldier &&ps);

    /*operator methods*/
    PrivateSoldier &operator=(const PrivateSoldier &ps);

    PrivateSoldier &operator=(PrivateSoldier &&ps);

    /*entry: by a soldier object, exit: return true if the soldier object deserves a medal*/
    virtual bool medal() const override;

    /*entry: by a soldier object, exit: print the soldier data*/
    virtual void print() const override;

    /*entry: by soldier object, exit: return the type of that soldier ( private / commander / officer )*/
    virtual string soldierType() const override { return "private"; };

    /*get method*/
    int *getGrades() { return grades; };

    /*entry: by a private soldier object, exit: returns the */
    virtual float operationsAverage() const;

    /*entry: by a soldier object of any range, exit: get input and set it to the new soldier*/
    virtual void input() override;

    virtual bool operator<(PrivateSoldier &ps) { return 1; };
};