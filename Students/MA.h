/* Author: Yael Farber 
Course: Advanced Programming
Exercise 8 Question 1
Program doc: managing classes of  BA , MA and PHD  students.
it has the options to print the students it get by input and declear if the student can get a milga*/

#pragma once

#include "BA.h"

class MA : public BA
{
private:
    /*field*/
    bool research;

public:
    /*ctor*/
    MA() : research(false){};

    /*get and set methods*/
    bool getResearch() const { return research; };

    void setResearch(bool res) { research = res; };

    /*entry: by a MA student , exit: return 1 if the student can get a milga or 0 if can't */
    virtual bool milga() const override;

    /*entry: by a MA student object, exit: get input and set it to the new MA student*/
    virtual void input() override;

    /*entry: by a MA student object, exit: print the details of that MA student object*/
    virtual void print() const override;

    /*override methods*/
    string studType() const override { return "MA"; };

    /*entry: by student object + get a student object, exit: return true if the student < the student parameter, as asked in the question*/
    virtual bool operator<(const Student &rhs) const override { return BA::operator<(rhs); };

    /*(impliment so MA won't be abstact)*/
    /*return hours of research*/
    virtual int getHours() const override { return 0; };
};
