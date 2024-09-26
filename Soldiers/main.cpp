/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Exercise 9 Question 1
Program doc: managing classes of  private , commander and officer soldiers and the medals they get.
it has options to add new soldiers print those who deserves medal print the commander with the highest sociometric score and so on..
you can choose an operation from the menu in the main page of the program.*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include "Soldier.h"
#include "Officer.h"
#include "Commander.h"
#include "PrivateSoldier.h"
#include "Soldier.cpp"
#include "Officer.cpp"
#include "Commander.cpp"
#include "PrivateSoldier.cpp"

using namespace std;

enum option
{
    EXIT,
    ADD_NEW_SOLDIER,
    DESERVES_MEDAL,
    HIGHEST_SOCIOMETRIC,
    PRIVATE_MEDAL_COUNT,
    NONCOMBAT_COMMANDER,
    SUPER_SOLDIER,
    REMOVE_OFFICER,
};

/* add a new soldier*/
void add(list<Soldier *> &lst);

/*prints the soldiers who deserves medal*/
void printMedalList(list<Soldier *> lst);

/*prints the name of the soldier withh the highest sociometric score*/
Soldier *highestSociometricScore(list<Soldier *> lst);

int main()
{
    Soldier *s;
    list<Soldier *> lst;
    int op;
    cout << "enter 0-7\n";
    cin >> op;
    while (op != EXIT)
    {
        switch (op)
        {
        case ADD_NEW_SOLDIER:
            add(lst);
            break;
        case DESERVES_MEDAL:
            printMedalList(lst);
            break;
        case HIGHEST_SOCIOMETRIC:
            s = highestSociometricScore(lst);
            cout << "Officer with the highest sociometric score: ";
            cout << s->getFirstName() << ' ' << s->getLastName() << endl;
            break;
        case PRIVATE_MEDAL_COUNT:
            cout << "number of privates that received medals: ";
            /*prints the number of privates soldiers who deserves medal*/
            cout << count_if(lst.begin(), lst.end(), [](Soldier *s)
                             { return (s->soldierType() == "private" && s->medal()); });
            cout << endl;
            break;
        case NONCOMBAT_COMMANDER:
            cout << "list of noncombat commanders: ";
            /*prints name of commanders that aren't combat*/
            for_each(lst.begin(), lst.end(), [](Soldier *s)
                     {if(s->soldierType() =="commander"&&((Commander *)(s))->getCombat()==0)cout<<s->getFirstName()<<" "<<s->getLastName()<<" "; });
            cout << endl;
            break;
        case SUPER_SOLDIER:
            /*return true if a soldier who did more than 15 operation exist in the list*/
            if (any_of(lst.begin(), lst.end(), [](Soldier *s)
                       { return (s->getNumOperations() > 15); }))
                cout << "there is at least one soldier that did more than 15 operations\n";
            else
                cout << "no soldier did more than 15 operations\n";
            break;
        case REMOVE_OFFICER:
            /*delete all the officers who never cooperated operation*/
            list<Soldier *>::iterator pend = remove_if(lst.begin(), lst.end(), [](Soldier *s)
                                                       { return ((s->soldierType() == "officer") && (s->getNumOperations() == 0)); });
            lst.erase(pend, lst.end());
            /*print all the soldiers*/
            for_each(lst.begin(), lst.end(), [](Soldier *s)
                     { s->print(); });
            break;
        };
        cout << "enter 0-7\n";
        cin >> op;
    }
    return 0;
}

/* add a new soldier*/
void add(list<Soldier *> &lst)
{
    int choice = 1, id, numOfOperations, socScore;
    string fName, lName;
    bool comb;
    int *grd;
    cout << "choose a soldier\n";
    cout << "enter 1 to add a private\n";
    cout << "enter 2 to add a commander\n";
    cout << "enter 3 to add an officer\n";
    cin >> choice;
    if (choice == 1)
    {
        PrivateSoldier *ps = new PrivateSoldier();
        ps->input();
        lst.push_back(ps);
    }
    else if (choice == 2)
    {
        Commander *comm = new Commander();
        comm->input();
        lst.push_back(comm);
    }
    else if (choice == 3)
    {

        Officer *officer = new Officer();
        officer->input();
        lst.push_back(officer);
    }
}

/*prints the soldiers who deserves medal*/
void printMedalList(list<Soldier *> lst)
{
    for (list<Soldier *>::iterator itr = lst.begin(); itr != lst.end(); itr++)
    {
        if ((*itr)->medal())
            (*itr)->print();
    }
}

/*prints the name of the soldier withh the highest sociometric score*/
Soldier *highestSociometricScore(list<Soldier *> lst)
{
    Soldier *soldier = new Officer();
    int max = 0;
    for (list<Soldier *>::iterator itr = lst.begin(); itr != lst.end(); itr++)
    {
        if ((*itr)->soldierType() == "officer")
            if (((Officer *)*itr)->getSociometric() > max)
            {
                soldier = *itr;
                max = ((Officer *)*itr)->getSociometric();
            }
    }
    return soldier;
}

/*example:

enter 0-7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
1
enter id, first name, last name and number of operations
111 aaa aaa 3
enter 3 grades
100 95 98
enter 0-7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
2
enter id, first name, last name and number of operations
222 bbb bbb 0
enter 1 if the soldier is combat and 0 if not
1
enter 0-7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
3
enter id, first name, last name and number of operations
333 ccc ccc 0
enter the sociometric score
100
enter 0-7
3
Officer with the highest sociometric score: ccc ccc
enter 0-7
4
number of privates that received medals: 0
enter 0-7
5
list of noncombat commanders:
enter 0-7
6
no soldier did more than 15 operations
enter 0-7
7
private
ID: 111
first name: aaa
last name: aaa
num operations:  3
grades: 100 95 98
commander
ID: 222
first name: bbb
last name: bbb
num operations:  0
combat: yes
enter 0-7
0
Process exited with status 0

Saving session...
...copying shared history...
...saving history...truncating history files...
...completed.

[התהליך הושלם]

*/