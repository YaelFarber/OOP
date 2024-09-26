/* Author: Yael Farber 
Course: Advanced Programming
Exercise 9 Question 1
Program doc: managing classes of  private , commander and officer soldiers and the medals they get.
it has options to add new soldiers print those who deserves medal print the commander with the highest sociometric score and so on..
you can choose an operation from the menu in the main page of the program.*/

#include "PrivateSoldier.h"

/*ctor*/
PrivateSoldier::PrivateSoldier()
{
    grades = nullptr;
}

/*dtor*/
PrivateSoldier::~PrivateSoldier()
{
    if (grades)
        delete[] grades;
    grades = nullptr;
    numOperations = 0;
}

/*cpy ctor*/
PrivateSoldier::PrivateSoldier(const PrivateSoldier &ps) : Soldier(ps)
{
    grades = new int[numOperations];
    for (int i = 0; i < ps.getNumOperations(); i++)
        grades[i] = ps.grades[i];
}

/*move ctor*/
PrivateSoldier::PrivateSoldier(PrivateSoldier &&ps) : Soldier(ps)
{
    if (grades)
        delete[] grades;
    grades = ps.grades;
    ps.grades = nullptr;
}

/*copy assignment operator*/
PrivateSoldier &PrivateSoldier::operator=(const PrivateSoldier &ps)
{
    ID = ps.ID;
    firstName = ps.firstName;
    lastName = ps.lastName;
    numOperations = ps.numOperations;
    grades = new int[numOperations];
    for (int i = 0; i < ps.getNumOperations(); i++)
        grades[i] = ps.grades[i];
    return *this;
}

/*move assignment operator*/
PrivateSoldier &PrivateSoldier::operator=(PrivateSoldier &&ps)
{

    ID = ps.ID;
    firstName = ps.firstName;
    lastName = ps.lastName;
    numOperations = ps.numOperations;
    if (grades)
        delete[] grades;
    grades = ps.grades;
    ps.grades = nullptr;
    return *this;
}

/*entry: by a private soldier object, exit: returns the */
float PrivateSoldier::operationsAverage() const
{
    int sum = 0;
    for (int i = 0; i < this->getNumOperations(); i++)
        sum += grades[i];
    return sum / getNumOperations();
}

/*entry: by a soldier object, exit: return true if the soldier object deserves a medal*/
bool PrivateSoldier::medal() const
{
    return (getNumOperations() >= 10 && operationsAverage() > 95);
}

/*entry: by a soldier object, exit: print the soldier data*/
void PrivateSoldier::print() const
{
    Soldier::print();
    if (getNumOperations() > 0 && grades)
    {
        cout << "grades: ";
        for (int i = 0; i < getNumOperations(); i++)
            cout << grades[i] << " ";
        cout << endl;
    }
}

/*entry: by a soldier object of any range, exit: get input and set it to the new soldier*/
void PrivateSoldier::input()
{
    Soldier::input();
    if (numOperations != 0)
    {
        cout << "enter " << this->getNumOperations() << " grades\n";
        grades = new int[numOperations];
        for (int i = 0; i < getNumOperations(); i++)
            cin >> grades[i];
    }
}
