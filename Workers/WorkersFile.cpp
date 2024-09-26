
// Author: Yael Farber ID: 326770468
// Course: Advanced Programming
// Targil 4 Sheela 1
/* Program doc: creating worker file with options to use operators with workers,merg two files and sort the file.
 */
#include "WorkersFile.h"
#include "Worker.h"
/*private methods*/

/*entry: by WorkersFile object, exit: opening the iofile field for writing */
bool WorkersFile::openNewFileForWriting()
{
    if (status != CLOSED)
    {
        cout << "ERROR\n";
        return false;
    }
    iofile.open(fileName, ios::out);
    if (!iofile)
    {
        cout << "file couldn't be opened\n";
    }
    if (iofile)
    {
        status = OPEN_W;
        return true;
    }
    else
    {
        status = ERROR;
        cout << "ERROR\n";
        return false;
    }
}

/*entry: by WorkersFile object, exit: opening the iofile field for reading */
bool WorkersFile::openFileForReading()
{
    if (status != CLOSED)
    {
        cout << "ERROR\n";
        return false;
    }
    iofile.open(fileName, ios::in);
    if (!iofile)
    {
        cout << "file couldn't be opened\n";
    }
    if (iofile)
    {
        status = OPEN_R;
        return true;
    }
    else
    {
        status = ERROR;
        cout << "ERROR\n";
        return false;
    }
}
/*entry: by WorkersFile object, exit: closeing the iofile field*/
void WorkersFile::closeFile()
{
    iofile.close();
    status = CLOSED;
}

/*constructors*/

WorkersFile::WorkersFile(string name) /*ctor :entry:  gets name of file, exit: creating a WorkersFile object */
{
    fileName = name;
    size = 0;
    status = CLOSED;
    openNewFileForWriting();
    closeFile();
}

/* cpy ctor: entry:  gets a WorkersFile object, exit: copy the parameter values to another new created WorkersFile */
WorkersFile::WorkersFile(const WorkersFile &source)
{
    fileName = source.fileName;
    size = source.size;
    status = CLOSED;
}

/*destructor*/
WorkersFile::~WorkersFile()
{
    closeFile();
}

/*global friends functions*/

/*entry: >>WorkersFile object, exit: sets the input into the WorkersFile parameter*/
istream &operator>>(istream &is, WorkersFile &source)
{
    source.openNewFileForWriting();
    Worker w;
    while (is >> w)
    {
        if (0 == w)
            break;
        source.size++;
        source.iofile << w;
    }
    source.closeFile();
    return is;
}

/*entry: >>WorkersFile object, exit: prints the WorkersFile paramete*/
ostream &operator<<(ostream &os, WorkersFile &source)
{
    source.openFileForReading();
    Worker w;
    while (source.iofile >> w)
    {
        os << w;
    }
    source.closeFile();
    return os;
}

/*public methods*/

/*entry: get true for ascending sortion / false for descending sortion, exit: sorts the file from the salarys*/
void WorkersFile::sort(bool ascending)
{
    Worker w;
    Worker *vec = new Worker[size];
    openFileForReading();
    for (int i = 0; i < size; i++)
    {
        iofile >> w;
        vec[i] = w;
    }
    closeFile();
    if (ascending)
        AscendingSort(vec);
    else
        DescendingSort(vec);
    openNewFileForWriting();
    if (!iofile)
    {
        cout << "file couldn't be opened\n";
    }
    int j = 0;
    while (j < size)
        iofile << vec[j++];
    closeFile();
    if (vec)
    {
        delete[] vec;
        vec = nullptr;
    }
}

/*entry: (WorkersFile object)[index] ,exit: returns the worker that placed in the WorkersFile index*/
Worker WorkersFile::operator[](const int index)
{
    Worker w;
    openFileForReading();
    for (int i = 0; i <= index; i++)
    {
        iofile >> w;
    }
    closeFile();
    return w;
}

/*entry: by a WorkersFile object, exit: add bonus to the all the workers salary  in the WorkersFile, returns that WorkersFile*/
WorkersFile &WorkersFile::operator+=(const float bonus)
{
    Worker w;
    Worker *vec = new Worker[size];
    openFileForReading();
    for (int j = 0; j < size; j++)
    {
        iofile >> w;
        vec[j] = w;
        vec[j] += bonus;
    }
    closeFile();
    openNewFileForWriting();
    int j = 0;
    while (j <= size)
        iofile << vec[j++];
    closeFile();
    if (vec)
    {
        delete[] vec;
        vec = nullptr;
    }
    return *this;
}

/*entry: WorkersFile + WorkersFile ,  exit: merge the 2 files to a third file ,returns that new merged file*/
WorkersFile WorkersFile::operator+(WorkersFile &source)
{
    WorkersFile mergedFile("merge"); /*creating the merged file*/
    openFileForReading();
    source.openFileForReading(); /*opening the files*/
    if (!iofile && !source.iofile)
        return mergedFile;
    mergedFile.openNewFileForWriting();
    if (!mergedFile.iofile)
        return mergedFile;
    mergedFile.iofile << iofile.rdbuf();
    mergedFile.iofile << source.iofile.rdbuf();
    mergedFile.size = size + source.size;
    closeFile();
    source.closeFile();
    mergedFile.closeFile();
    return mergedFile;
}

/*temp functions*/

/*entry: by a WorkersFile, exit: returns the amount of workers in the file*/
void WorkersFile::AscendingSort(Worker *vec)
{ /*using bubble sort*/
    int last, i;
    for (last = size - 1; last > 0; last--)
        for (int i = 0; i < last; i++)
            if (vec[i + 1] < vec[i])
            {
                Worker temp = vec[i + 1];
                vec[i + 1] = vec[i];
                vec[i] = temp;
            }
}

/*entry: by a WorkersFile obj, exit: sorts the file by salarys low to high*/
void WorkersFile::DescendingSort(Worker *vec)
{ /*using bubble sort*/
    int last, i;
    for (last = size - 1; last > 0; last--)
        for (int i = 0; i < last; i++)
            if (vec[i] < vec[i + 1])
            {
                Worker temp = vec[i + 1];
                vec[i + 1] = vec[i];
                vec[i] = temp;
            }
}
