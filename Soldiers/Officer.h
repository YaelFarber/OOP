/* Author: Yael Farber
Course: Advanced Programming
Exercise 9 Question 1
Program doc: managing classes of  private , commander and officer soldiers and the medals they get.
it has options to add new soldiers print those who deserves medal print the commander with the highest sociometric score and so on..
you can choose an operation from the menu in the main page of the program.*/

#include "Soldier.h"
#pragma once
class Officer : public Soldier
{
    int sociometricScore;

public:
    /*ctor*/
    Officer() : sociometricScore(0){};

    /*cpy ctor*/
    Officer(const Officer &of);

    /*move ctor*/
    Officer(Officer &&of);

    /*entry: by a soldier object, exit: print the soldier data*/
    virtual void print() const override;

    /*entry: by soldier object, exit: return the type of that soldier ( private / commander / officer )*/
    string soldierType() const override { return "officer"; };

    /*entry: by a soldier object, exit: return true if the soldier object deserves a medal*/
    virtual bool medal() const override;

    /*entry: by a soldier object of any range, exit: get input and set it to the new soldier*/
    virtual void input() override;

    /*get method*/
    int getSociometric() { return sociometricScore; };

    virtual bool operator<(Officer &officer);
};
