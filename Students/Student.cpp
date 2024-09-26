/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 8 Question 1
Program doc: managing classes of  BA , MA and PHD  students.
it has the options to print the students it get by input and declear if the student can get a milga*/

#include "Student.h"

/*cpy ctor*/
Student::Student(const Student &student1)
    : id(student1.id), firstName(student1.firstName), lastName(student1.lastName), numberOfCourses(student1.numberOfCourses){};

/*entry: by a student object of any range, exit: get input and set it to the new student*/
void Student::input()
{
    int coursesNum;
    cout << "enter id, first name, last name, number of courses\n";
    cin >> id >> firstName >> lastName >> coursesNum;

    if (coursesNum < 0)
        throw "Invalid number of courses";
    numberOfCourses = coursesNum;
}

/*entry: by a student object of any range, exit: print the details of that student object*/
void Student::print() const
{
    cout<<endl;
    if (studType() != "PHD")
        cout << studType() << " student ";
    else
        cout << "PhD student";

    if (this->milga())
        cout << "*** Scholarship ***\n";
    else
        cout << endl;
    cout << "ID: " << id;
    cout << "\nName: " << firstName << " " << lastName << endl;
}