/* Author: Yael Farber 
Course: Advanced Programming
Targil 6 Sheela 1
Program doc: creating a class that manage Round List - the last link points to the first link.
the options are: create a Round List, add a new link to the start, to the end, to remove a link from the start and to search for a link */

#include "RoundList.h"
using namespace std;

/*dtor*/
RoundList::~RoundList()
{
    RoundList::clear();
}

void RoundList::clear()
{
    if (!this->isEmpty())
    {
        // empty all elements from the List
        Link *next;
        for (Link *p = head; p->next != head; p = next)
        {
            // delete the element pointed to by p
            next = p->next;
            p->next = nullptr;
            if (p)
                delete p;
        }
        // mark that the List contains no elements
        head = nullptr;
    }
}

void RoundList::add(int val)
{
    // Add new key to front of List
    Link *ptr = head;
    if (this->isEmpty())
    {
        head = new Link(val, head);
        head->next = head;
    }
    else
    {
        while (ptr->next != head)
            ptr = ptr->next;
        head = new Link(val, head);
        ptr->next = head;
        if (head == nullptr)
            throw "failed in memory allocation";
    }
}

void RoundList::removeFirst()
{
    // make sure there is a first element
    if (this->isEmpty())
        throw "List empty, no Elements to remove";
    if (head->next == head)
    {
        this->clear();
    }
    else
    {
        // save pointer to the removed node
        Link *p = head;
        Link *ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        // reassign the first node
        head = p->next;
        p->next = nullptr;
        ptr->next = head;
        delete p;
    }
}

/*entry: get a number, exit: add the parameter to a new link in the end of the list*/
void RoundList::addToEnd(int val)
{
    Link *ptr = head;
    if (this->isEmpty())
    {
        head = new Link(val, head);
        head->next = head;
    }
    else
    {
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = new Link(val, head);
    }
}

/*entry: get a number as an index, exit: find the link in the n place and return it's value */
int RoundList::search(int n)
{
    if (n < 0)
        throw "The index can't be negative";
    Link *ptr = head;
    for (int i = 0; i < n; i++)
        ptr = ptr->next;
    return ptr->value;
}
