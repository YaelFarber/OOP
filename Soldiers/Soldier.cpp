/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 9 Question 1
Program doc: managing classes of  private , commander and officer soldiers and the medals they get.
it has options to add new soldiers print those who deserves medal print the commander with the highest sociometric score and so on..
you can choose an operation from the menu in the main page of the program.*/

#include "Soldier.h"

/*cpy ctor*/
Soldier::Soldier(const Soldier &soldier1)
{
    ID = soldier1.ID;
    firstName = soldier1.firstName;
    lastName = soldier1.lastName;
    numOperations = soldier1.numOperations;
}

/*move ctor*/
Soldier::Soldier(Soldier &&soldier1)
{
    ID = soldier1.ID;
    firstName = soldier1.firstName;
    lastName = soldier1.lastName;
    numOperations = soldier1.numOperations;
}

void Soldier::print() const
{
    cout << soldierType() << endl;
    cout << "ID: " << ID << endl;
    cout << "first name: " << firstName << endl;
    cout << "last name: " << lastName << endl;
    cout << "num operations:  " << numOperations << endl;
}

/*entry: by a soldier object of any range, exit: get input and set it to the new soldier*/
void Soldier::input()
{
    int num;
    cout << "enter id, first name, last name and number of operations\n";
    cin >> ID >> firstName >> lastName >> num;
    if (num < 0)
        throw "Invalid number of courses";
    numOperations = num;
}