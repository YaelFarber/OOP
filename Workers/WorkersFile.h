// Author: Yael Farber ID: 326770468
// Course: Advanced Programming
// Targil 4 Sheela 1
/* Program doc: creating worker file with options to use operators with workers,merg two files and sort the file.
 */
#pragma once
#include "Worker.h"
#include <fstream>
#include <iostream>
using namespace std;

enum FILE_STATUS
{
    ERROR,
    CLOSED,
    OPEN_R,
    OPEN_W
};

class WorkersFile
{
private:
    /*fields*/
    string fileName;
    fstream iofile;
    FILE_STATUS status;
    int size;

    /*private methods*/
    bool openNewFileForWriting(); /*entry: by WorkersFile object, exit: opening the iofile field for writing */
    bool openFileForReading();    /*entry: by WorkersFile object, exit: opening the iofile field for reading */
    void closeFile();             /*entry: by WorkersFile object, exit: closeing the iofile field*/

public:
    /*constructors*/
    WorkersFile(string name);               /*ctor :entry:  gets name of file, exit: creating a WorkersFile object */
    WorkersFile(const WorkersFile &source); /* cpy ctor: entry:  gets a WorkersFile object, exit: copy the parameter values to another new created WorkersFile */
    ~WorkersFile();                         /*destructor*/

    /*global friends functions*/
    friend istream &operator>>(istream &is, WorkersFile &source); /*entry: >>WorkersFile object, exit: sets the input into the WorkersFile parameter*/
    friend ostream &operator<<(ostream &os, WorkersFile &source); /*entry: >>WorkersFile object, exit: prints the WorkersFile paramete*/

    /*public methods*/
    void sort(bool ascending = true);           /*entry: get true for ascending sortion / false for descending sortion, exit: sorts the file from the salarys*/
    Worker operator[](const int index);         /*entry: (WorkersFile object)[index] ,exit: returns the worker that placed in the WorkersFile index*/
    WorkersFile &operator+=(const float bonus); /*entry: by a WorkersFile object, exit: add bonus to the all the workers salary  in the WorkersFile, returns that WorkersFile*/
    WorkersFile operator+(WorkersFile &source); /*entry: WorkersFile + WorkersFile ,  exit: merge the 2 files to a third file ,returns that new merged file*/

    /*temp functions*/
                             /*entry: by a WorkersFile, exit: returns the amount of workers in the file*/
    void AscendingSort(Worker *vec);  /*entry: by a WorkersFile obj, exit: sorts the file by salarys low to high*/
    void DescendingSort(Worker *vec); /*entry: by a WorkersFile obj, exit: sorts the file by salarys high to low*/
};