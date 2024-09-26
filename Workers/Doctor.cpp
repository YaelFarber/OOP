#include "Doctor.h"
#include <string>
Doctor::Doctor(char *_name, int num, int *waitings)
{
    cout << "In constructor" << endl;
    strcpy(name, _name);
    number_waitings = num;
    patients_waiting = new int[num];
    for (int i = 0; i < num; i++)
    {
        patients_waiting[i] = waitings[i];
    }
}
Doctor::~Doctor()
{
    cout << "In destructor" << endl;
}

Doctor::Doctor(Doctor &&d)
{
    strcpy(name, d.name);
    number_waitings = d.number_waitings;
    for (int i = 0; i < d.number_waitings; i++)
    {
        patients_waiting[i] = d.patients_waiting[i];
    }
}

void Doctor::print()
{
    cout << "patients waiting:\n";
    for (int i = 0; i < number_waitings; i++)
    {
        cout << patients_waiting[i] << " ";
    }
    cout << endl;
}
int Doctor::next()
{
    int num = patients_waiting[0];
    patients_waiting++;
    number_waitings--;
    return num;
}