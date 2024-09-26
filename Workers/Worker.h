// Author: Yael Farber ID: 326770468
// Course: Advanced Programming
// Targil 4 Sheela 1
/* Program doc: creating worker file with options to use operators with workers,merg two files and sort the file.
 */
#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Worker
{
    /*fields*/
    long id = 0;
    string name = "";
    float salary = 0;

public:
    /*methods*/
    Worker &operator+=(const float bonus); /*entry: by a worker object, exit: add bonus to the worker salary ,returns that object*/
    bool operator<(const Worker &worker2); /*entry: by a worker object, exit: returns true if the objects salary is smaller than the parameter salary, else return false*/
    /*friends - global (in this case-operator) functions*/
    friend bool operator==(long id, const Worker &worker2);      /*entry: id (long parameter) == worker object ,exit: returns true if the id parameter is the worker2 parameter id , else returns false*/
    friend bool operator==(string name, const Worker &worker2);  /*entry: name (string parameter) == worker object, exit: returns true if the name parameter is the worker2 parameter name ,else returns false*/
    friend istream &operator>>(istream &is, Worker &worker2);   /*entry: >>worker object, exit: sets the input into the worker parameter*/
    friend ostream &operator<<(ostream &os, const Worker &worker2); /*entry: <<worker object, exit: prints the worker parameter*/

    friend class WorkersFile; /*so i can get to Worker fields in WorkersFile class*/
};