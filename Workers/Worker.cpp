// Author: Yael Farber ID: 326770468
// Course: Advanced Programming
// Targil 4 Sheela 1
/* Program doc: creating worker file with options to use operators with workers,merg two files and sort the file.
 */
#include "Worker.h"
#include <fstream>

/*entry: by a worker object, exit: add bonus to the worker salary ,returns that object*/
Worker &Worker::operator+=(const float bonus)
{
    salary += bonus;
    return *this;
}

/*entry: by a worker object, exit: returns true if the objects salary is smaller than the parameter salary, else return false*/
bool Worker::operator<(const Worker &worker2)
{
    return salary < worker2.salary;
}

/*friends - global (in this case-operator) functions*/

/*entry: id (long parameter) == worker object ,exit: returns true if the id parameter is the worker2 parameter id , else returns false*/
bool operator==(long id, const Worker &worker2)
{
    return id == worker2.id;
}

/*entry: name (string parameter) == worker object, exit: returns true if the name parameter is the worker2 parameter name ,else returns false*/
bool operator==(string name, const Worker &worker2)
{
    return name == worker2.name;
}

/*entry: >>worker object, exit: sets the input into the worker parameter*/
istream &operator>>(istream &is, Worker &worker2) // input
{
    is >> worker2.id >> worker2.name >> worker2.salary;
    return is;
}

/*entry: <<worker object, exit: prints the worker parameter*/
ostream &operator<<(ostream &os, const Worker &worker2) // output
{
    os << worker2.id << " " << worker2.name << " " << worker2.salary<<endl;
    return os;
}