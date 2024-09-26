/* Author: Yael Farber 
Course: Advanced Programming
Exercise 8 Question 1
Program doc: managing classes of  BA , MA and PHD  students.
it has the options to print the students it get by input and declear if the student can get a milga*/

#include <iostream>

#include "MA.h"
#include "PHD.h"

#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

Student *addStudent();

using namespace std;
int main()
{
    /*list*/
    list<Student *> lst1;
    list<Student *>::iterator itr;
    itr = lst1.begin();
    do
    {
        try
        {
            lst1.push_back((addStudent()));
        }
        catch (const char *msg)
        {
            cout << msg << endl;
            itr--;
        }
        itr++;
    } while (*itr);

    /*vector*/
    vector<BA> vectorBA;
    vector<MA> vectorMA;
    vector<PHD> vectorPHD;

    itr = lst1.begin();

    while (*itr) /*sorting the list nodes to the vector by the student type*/
    {
        if ((*itr)->studType() == "BA")
            vectorBA.push_back(*((BA *)*itr));
        else
        {
            if ((*itr)->studType() == "MA")
                vectorMA.push_back(*((MA *)*itr));

            else if ((*itr)->studType() == "PHD")
                vectorPHD.push_back(*((PHD *)*itr));
        }
        if (!lst1.empty())
            lst1.remove(*itr);
        itr = lst1.begin();
    }

    /*sort the vectors by the overloade operator< */
    sort(vectorBA.begin(), vectorBA.end());
    sort(vectorMA.begin(), vectorMA.end());
    sort(vectorPHD.begin(), vectorPHD.end());

    /*queue and stack*/
    queue<BA> queueBA;
    queue<MA> queueMA;

    stack<PHD> stackPHD;

    vector<BA>::const_reverse_iterator itrBA = vectorBA.rbegin();
    vector<MA>::const_reverse_iterator itrMA = vectorMA.rbegin();
    vector<PHD>::iterator itrPHD = vectorPHD.begin();

    while (itrBA != vectorBA.rend())
    {
        queueBA.push(*itrBA);
        itrBA++;
    }

    while (itrMA != vectorMA.rend())
    {
        queueMA.push(*itrMA);
        itrMA++;
    }

    while (itrPHD != vectorPHD.end())
    {
        stackPHD.push(*itrPHD);
        itrPHD++;
    }

    /*print*/
    for (int i = 0; i < vectorBA.size(); i++)
    {
        BA b = queueBA.front();
        b.print();
        queueBA.pop();
    }

    for (int i = 0; i < vectorMA.size(); i++)
    {
        MA m = queueMA.front();
        m.print();
        queueMA.pop();
    }
    for (int i = 0; i < vectorPHD.size(); i++)
    {
        PHD p = stackPHD.top();
        p.print();
        stackPHD.pop();
    }

    /*delete the objects in the list*/
    itr = lst1.begin();
    while (*itr)
    {
        lst1.begin()++;
        delete *itr;
        *itr = nullptr;
        itr = lst1.begin();
    }

    return 0;
}

/*input the student type and return pointer to that student*/
Student *addStudent()
{
    int degree;
    cout << "Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish\n";
    cin >> degree;
    if (degree == 0)
        return nullptr;
    if (degree == 1)
    {
        BA *ba = new BA();
        ba->input();
        return ba;
    }
    if (degree == 2)
    {
        MA *ma = new MA();
        ma->input();
        return ma;
    }
    if (degree == 3)
    {
        PHD *phd = new PHD();
        phd->input();
        return phd;
    }

    throw "Exception: no such degree\n";
}

/*example:

Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
1
enter id, first name, last name, number of courses
123 Reuven Reuveni 10
and enter a list of student grades
100 100 100 100 100 100 100 100 100 100
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
1
enter id, first name, last name, number of courses
234 Shimon Shimoni 10
and enter a list of student grades
95 95 95 95 95 95 95 95 95 95
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
1
enter id, first name, last name, number of courses
345 Levi Levi 10
and enter a list of student grades
99 99 99 99 99 99 99 99 99 99
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
1
enter id, first name, last name, number of courses
444 Ploni Almoni 0
and enter a list of student grades
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
2
enter id, first name, last name, number of courses
555 Yehuda Yehuda 7
and enter a list of student grades
95 95 95 95 95 95 95
enter 1 if the student does research and 0 if not
1
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
2
enter id, first name, last name, number of courses
678 Dan Dani 7
and enter a list of student grades
97 97 97 97 97 97 97
enter 1 if the student does research and 0 if not
1
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
3
enter id, first name, last name, number of courses
789 Naphtali Naphtali 2
enter number of research hours:
26
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
7
Exception: no such degree
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
3
enter id, first name, last name, number of courses
890 Gad Gadi 2
enter number of research hours:
32
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
3
enter id, first name, last name, number of courses
901 Asher Asher 1
enter number of research hours:
36
Enter degree: 1 for BA, 2 for MA, or 3 for PhD, 0 to finish
0


BA student *** Scholarship ***
ID: 123
Name: Reuven Reuveni
Grades: 100 100 100 100 100 100 100 100 100 100
Average: 100

BA student *** Scholarship ***
ID: 345
Name: Levi Levi
Grades: 99 99 99 99 99 99 99 99 99 99
Average: 99

BA student
ID: 234
Name: Shimon Shimoni
Grades: 95 95 95 95 95 95 95 95 95 95
Average: 95

BA student
ID: 444
Name: Ploni Almoni
Grades:
Average: 0

MA student *** Scholarship ***
ID: 678
Name: Dan Dani
Grades: 97 97 97 97 97 97 97
Average: 97
research: YES

MA student *** Scholarship ***
ID: 555
Name: Yehuda Yehuda
Grades: 95 95 95 95 95 95 95
Average: 95
research: YES

PhD student*** Scholarship ***
ID: 890
Name: Gad Gadi
Number of research Hours: 32

PhD student*** Scholarship ***
ID: 789
Name: Naphtali Naphtali
Number of research Hours: 26

PhD student
ID: 901
Name: Asher Asher
Number of research Hours: 36
Process exited with status 0

Saving session...
...copying shared history...
...saving history...truncating history files...
...completed.

[התהליך הושלם]
 */
