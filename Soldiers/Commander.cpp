/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 9 Question 1
Program doc: managing classes of  private , commander and officer soldiers and the medals they get.
it has options to add new soldiers print those who deserves medal print the commander with the highest sociometric score and so on..
you can choose an operation from the menu in the main page of the program.*/

#include "Commander.h"

/*cpy ctor*/
Commander::Commander(const Commander &co):PrivateSoldier(co)
{
    combat = co.combat;
}

/*move ctor*/
Commander::Commander(Commander &&co):PrivateSoldier(co)
{
    combat = co.combat;
}

/*entry: by a soldier object, exit: return true if the soldier object deserves a medal*/
bool Commander::medal() const
{
    return (getNumOperations() >= 7 && operationsAverage() > 90 && combat);
}

/*entry: by a soldier object, exit: print the soldier data*/
void Commander::print() const
{
    PrivateSoldier::print();
    cout << "combat: ";
    if (combat)
        cout << "yes\n";
    else
        cout << "no\n";
}

/*entry: by a soldier object of any range, exit: get input and set it to the new soldier*/
void Commander::input()
{
    PrivateSoldier::input();
    cout << "enter 1 if the soldier is combat and 0 if not\n";
    cin >> combat;
}
