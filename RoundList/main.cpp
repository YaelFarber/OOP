/* Author: Yael Farber 
Course: Advanced Programming
Targil 6 Sheela 1
Program doc: creating a class that manage Round List - the last link points to the first link.
the options are: create a Round List, add a new link to the start, to the end, to remove a link from the start and to search for a link */

// The program implements round linked list

#include "RoundList.h"
#include "RoundList.cpp"
#include "List.h"
#include "List.cpp"

#include <iostream>
using namespace std;

enum CHOICES
{
    EXIT,
    ADD,
    ADD_TO_END,
    REMOVE_FIRST,
    SEARCH,
    CLEAR,
    EMPTY
};
int main()
{
    try
    {
        RoundList ls1;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        while (choice != EXIT)
        {
            int num;
            switch (choice)
            {
            case ADD:
                cout << "Enter 5 numbers: ";
                for (int i = 0; i < 5; i++)
                {
                    cin >> num;
                    ls1.add(num);
                }
                break;

            case ADD_TO_END:
                cout << "Enter 5 numbers: ";
                for (int i = 0; i < 5; i++)
                {
                    cin >> num;
                    ls1.addToEnd(num);
                }
                break;

            case REMOVE_FIRST:
                ls1.removeFirst();
                break;

            case SEARCH:
                cout << "Enter a number: ";
                cin >> num;
                cout << ls1.search(num) << endl;
                break;

            case CLEAR:
                ls1.clear();
                break;

            case EMPTY:
                if (ls1.isEmpty())
                    cout << "Empty" << endl;
                else
                    cout << "Not empty" << endl;
                break;

            default:
                cout << "ERROR!" << endl;
            }
            cout << "Enter your choice: ";
            cin >> choice;
        }
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    return 0;
}

/*example:
Enter your choice: 1
Enter 5 numbers: 5 4 3 2 1
Enter your choice: 3
Enter your choice: 3
Enter your choice: 3
Enter your choice: 3
Enter your choice: 3
Enter your choice: 6
Empty
Enter your choice: 0
Process exited with status 0

Saving session...
...copying shared history...
...saving history...truncating history files...
...completed.

[התהליך הושלם]
 */
