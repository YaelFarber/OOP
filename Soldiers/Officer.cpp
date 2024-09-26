/* Author: Yael Farber 
Course: Advanced Programming
Exercise 9 Question 1
Program doc: managing classes of  private , commander and officer soldiers and the medals they get.
it has options to add new soldiers print those who deserves medal print the commander with the highest sociometric score and so on..
you can choose an operation from the menu in the main page of the program.*/

#include "Officer.h"
/*cpy ctor*/
Officer::Officer(const Officer &of) : Soldier(of)
{
    sociometricScore = of.sociometricScore;
}

/*move ctor*/
Officer::Officer(Officer &&of) : Soldier(of)
{
    sociometricScore = of.sociometricScore;
}

/*entry: by a soldier object, exit: return true if the soldier object deserves a medal*/
bool Officer::medal() const
{
    return (getNumOperations() >2 && sociometricScore >= 92);
}

/*entry: by a soldier object, exit: print the soldier data*/
void Officer::print() const
{
    Soldier::print();
    cout << "sociometric score: " << sociometricScore << endl;
}

/*entry: by a soldier object of any range, exit: get input and set it to the new soldier*/
void Officer::input()
{
    Soldier::input();
    cout << "enter the sociometric score\n";
    cin >> sociometricScore;
}

bool Officer::operator<(Officer &officer)
{
    return (this->getSociometric() < officer.getSociometric());
}
