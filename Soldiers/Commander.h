/* Author: Yael Farber 
Course: Advanced Programming
Exercise 9 Question 1
Program doc: managing classes of  private , commander and officer soldiers and the medals they get.
it has options to add new soldiers print those who deserves medal print the commander with the highest sociometric score and so on..
you can choose an operation from the menu in the main page of the program.*/

#include "PrivateSoldier.h"
#pragma once

class Commander : public PrivateSoldier
{
    bool combat;

public:
    /*ctor*/
    Commander() : combat(0){};

    /*cpy ctor*/
    Commander(const Commander &co);

    /*move ctor*/
    Commander(Commander &&co);

    /*entry: by a soldier object, exit: print the soldier data*/
    virtual void print() const override;

    /*entry: by soldier object, exit: return the type of that soldier ( private / commander / officer )*/
    virtual string soldierType() const override { return "commander"; };

    /*entry: by a soldier object, exit: return true if the soldier object deserves a medal*/
    virtual bool medal() const override;

    /*entry: by a soldier object of any range, exit: get input and set it to the new soldier*/
    virtual void input() override;

    /*get methods*/
    bool getCombat() { return combat; };

    bool operator<(Commander &co) { return 1; };
};
