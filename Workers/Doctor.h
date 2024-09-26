#pragma once
#include <iostream>
#include <cstring>

using namespace std;
class Doctor
{
    /*fields*/
public:
    char name[25];
    int number_waitings;
    int* patients_waiting;

public:
Doctor(char*_name,int num,int* waitings);
~Doctor();
Doctor(Doctor && d);
void print();
int next();


};