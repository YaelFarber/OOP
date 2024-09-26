/* Author: Yael Farber 
Course: Advanced Programming
Exercise 8 Question 1
Program doc: managing classes of  BA , MA and PHD  students.
it has the options to print the students it get by input and declear if the student can get a milga*/

#include "BA.h"

/*ctor*/
BA::BA()
{
    grades = new int;
    size = 0;
}

/*dtor*/
BA::~BA()
{
    if (grades)
        grades = nullptr;
    size = 0;
}

/*entry: by a BA student , exit: return 1 if the student can get a milga or 0 if can't */
bool BA::milga() const
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += grades[i];
    return (numberOfCourses >= 10) && (sum / size) + (sum % size) > 95;
}

/*entry: by a BA student object, exit: get input and set it to the new BA student*/
void BA::input()
{
    int grade1;
    Student::input();

    size = this->getCourses();
    grades = new int[size];

    cout << "and enter a list of student grades\n";
    for (int i = 0; i < size; i++)
    {
        cin >> grade1;
        if (grade1 < 0)
            throw "Invalid grade\n";
        grades[i] = grade1;
    }
}

/*entry: by a BA student object, exit: print the details of that BA student object*/
void BA::print() const
{
    Student::print();
    cout << "Grades: ";
    for (int i = 0; i < size; i++)
    {
        cout << grades[i] << " ";
    }
    cout << "\nAverage: " << averageGrades();
    cout << endl;
}

/*copy ctor*/
BA::BA(const BA &rba)
{
    id = rba.id;
    firstName = rba.firstName;
    lastName = rba.lastName;
    numberOfCourses = rba.numberOfCourses;
    size = rba.size;
    size = rba.size;
    grades = new int[size];
    for (int i = 0; i < size; i++)
        grades[i] = rba.grades[i];
}

/*move ctor*/
BA::BA(BA &&ba)
{
    id = ba.id;
    firstName = ba.firstName;
    lastName = ba.lastName;
    numberOfCourses = ba.numberOfCourses;
    size = ba.size;
    grades = ba.grades;
    ba.grades = nullptr;
}

/*copy assignment operator*/
BA &BA::operator=(BA &rba)
{
    id = rba.id;
    firstName = rba.firstName;
    lastName = rba.lastName;
    numberOfCourses = rba.numberOfCourses;
    size = rba.size;
    this->setSize(rba.getSize());
    for (int i = 0; i < rba.getSize(); i++)
        this->getGrades()[i] = rba.getGrades()[i];
    return *this;
};

/*move assignment operator*/
BA &BA::operator=(BA &&rba)
{
    id = rba.id;
    firstName = rba.firstName;
    lastName = rba.lastName;
    numberOfCourses = rba.numberOfCourses;
    size = rba.size;
    if (grades != rba.getGrades())
        grades = rba.getGrades();
    rba.grades = nullptr;
    return *this;
}

/*entry: by a student object exit: return the average grade*/
float BA::averageGrades() const
{
    if (size == 0)
        return 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += grades[i];
    return (float)sum / size;
}

/*entry: by student object + get a student object, exit: return true if the student < the student parameter, as asked in the question*/
bool BA::operator<(const Student &rhs) const
{
    if (this->studType() != rhs.studType())
        cout << "cannot compare students of different types\n";
    if (!this->milga() && rhs.milga())
        return true;
    if (this->milga() && !rhs.milga())
        return false;
    if ((this->milga() && rhs.milga()) || !this->milga() && !rhs.milga())
        if (this->averageGrades() < rhs.averageGrades())
            return true;
    return false;
}
