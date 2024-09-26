/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 10 Question 4
Program doc: implemnting a BST tree, with options to:
add, remove, reflect, sort get the height of the tree, number of leaves, number of left leaves,and a level of asked node.
In addition-> managing student in the Search-Tree. */

#pragma once
#include <iostream>
using namespace std;

class Student
{
    /*fields*/
    int ID;
    string fName;
    string lName;

public:
    /*ctor*/
    Student() : ID(0), fName(""), lName(""){};

    /*cpy ctor*/
    Student(int id, string first, string last) : ID(id), fName(first), lName(last){};

    /*operator >> input*/
    friend istream &operator>>(istream &is, Student &student1);

    /*operator << output*/
    friend ostream &operator<<(ostream &os, const Student &student1);

    /*operator = assignment*/
    Student &operator=(const Student &student1);

    /*operator <= compare (less or equal than...) */
    bool operator<=(const Student &student1);

    /*operator == equal comarasion */
    bool operator==(const Student &student1);

    /*operator != not equal comarasion */
    bool operator!=(const Student &student1);

    /*operator > compare (greater than...) */
    bool operator>(const Student &student1);
};