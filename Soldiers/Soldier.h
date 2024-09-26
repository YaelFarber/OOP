/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 9 Question 1
Program doc: managing classes of  private , commander and officer soldiers and the medals they get.
it has options to add new soldiers print those who deserves medal print the commander with the highest sociometric score and so on..
you can choose an operation from the menu in the main page of the program.*/

#include <iostream>

#pragma once

using namespace std;

class Soldier
{
protected:
    /*fields*/
    int ID;
    string firstName;
    string lastName;
    int numOperations;

public:
    /*ctor*/
    Soldier(int id = 0, string fName = "", string lName = "", int num = 0) : ID(id), firstName(fName), lastName(lName), numOperations(num){};

    /*cpy ctor*/
    Soldier(const Soldier &soldier1);

    /*move ctor*/
    Soldier(Soldier &&soldier1);

    /*dtor*/
    virtual ~Soldier(){};

    /*entry: by a soldier object, exit: return true if the soldier object deserves a medal*/
    virtual bool medal() const = 0;

    /*entry: by a soldier object, exit: print the soldier data*/
    virtual void print() const;

    /*entry: by soldier object, exit: return the type of that soldier ( private / commander / officer )*/
    virtual string soldierType() const = 0;

    /*get methods*/
    int getID() const { return ID; };

    string getFirstName() const { return firstName; };

    string getLastName() const { return lastName; };

    int getNumOperations() const { return numOperations; };

    /*entry: by a soldier object of any range, exit: get input and set it to the new soldier*/
    virtual void input();
};
