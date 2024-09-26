/* Author: Yael Farber 
Course: Advanced Programming
Exercise 10 Question 4
Program doc: implemnting a BST tree, with options to:
add, remove, reflect, sort get the height of the tree, number of leaves, number of left leaves,and a level of asked node.
In addition-> managing student in the Search-Tree. */

#include "Student.h"

/*operator >> input*/
istream &operator>>(istream &is, Student &student1)
{
    is >> student1.ID >> student1.lName >> student1.fName;
    return is;
}

/*operator << output*/
ostream &operator<<(ostream &os, const Student &student1)
{
    os << student1.ID << " " << student1.lName << " " << student1.fName<<endl;
    return os;
}

/*operator = assignment*/
Student &Student::operator=(const Student &student1)
{
    this->ID = student1.ID;
    this->fName = student1.fName;
    this->lName = student1.lName;
    return *this;
}

/*operator <= compare (less or equal than...) */
bool Student::operator<=(const Student &student1)
{
    return (this->lName <= student1.lName);
}

/*operator == equal comarasion */
bool Student::operator==(const Student &student1)
{
    return (this->ID == student1.ID && this->fName == student1.fName && this->lName == student1.lName);
}

/*operator != not equal comarasion */
bool Student::operator!=(const Student &student1)
{
    return !(*this == student1);
}

/*operator > compare (greater than...) */
bool Student::operator>(const Student &student1)
{
    return !(*this <= student1);
}
