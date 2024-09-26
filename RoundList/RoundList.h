/* Author: Yael Farber 
Course: Advanced Programming
Targil 6 Sheela 1
Program doc: creating a class that manage Round List - the last link points to the first link.
the options are: create a Round List, add a new link to the start, to the end, to remove a link from the start and to search for a link */

#pragma once
#include "List.h"
#include <iostream>
using namespace std;

class RoundList : public List
{
public:

    /*dtor*/
    ~RoundList();

    /*override methods*/

    void clear();

    void add(int val);

    void removeFirst();

    /*entry: get a number, exit: add the parameter to a new link in the end of the list*/
    void addToEnd(int val);

    /*entry: get a number as an index, exit: find the link in the n place and return it's value */
    int search(int n);
};
