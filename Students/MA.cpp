/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 8 Question 1
Program doc: managing classes of  BA , MA and PHD  students.
it has the options to print the students it get by input and declear if the student can get a milga*/

#include "MA.h"

/*entry: by a MA student , exit: return 1 if the student can get a milga or 0 if can't */
bool MA::milga() const
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += grades[i];
    return research && (numberOfCourses >= 7) && (sum / size) + (sum % size) > 90;
}

/*entry: by a MA student object, exit: get input and set it to the new MA student*/
void MA::input()
{
    BA::input();
    cout << "enter 1 if the student does research and 0 if not\n";
    cin >> research;
}

/*entry: by a MA student object, exit: print the details of that MA student object*/
void MA::print() const
{
    BA::print();
    cout << "research: ";
    if (research)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;
}

