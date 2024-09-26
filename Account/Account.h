/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Targil 5 Sheela 1
Program doc: creating a class that manage ATM, with the options to create account, deposite or withdraw nis */

#pragma once
#include <iostream>
#include <string>
#include "Clock.h"
using namespace std;

class Account
{
private:
    /*fields*/

    int accountNumber;

    int code;

    float balance;

    string email;

    /*static fields*/

    static int sumWithdraw; /*the sum of all draws in the "bank" (all the accounts together)*/

    static int sumDeposit; /*the sum of all deposits in the "bank" (all the accounts together)*/

public:
    /*constructors*/

    Account() : accountNumber(0), code(0), balance(0), email(""){}; /*empty - default constructor*/

    Account(int accNum, int _code, float _balance, string _email); /*set parameters constructor*/

    /*get methods*/

    int getAccountNumber() const { return accountNumber; }; /*entry: by account object, exit: return the account number*/

    int getCode() const { return code; }; /*entry: by account object, exit: return the code*/

    float getBalance() const { return balance; }; /*entry: by account object, exit: return the balance*/

    string getEmail() const { return email; }; /*entry: by account object, exit: return the email address*/

    /*operator method*/

    friend istream &operator>>(istream &is, Account &account1); /*entry: by oopertator >>account object , exit: set the input in the account object*/

    void withdraw(int nis); /*entry: get a nis parameter, exit: withdraw the nis from the balance with the requested input check*/

    void deposit(int de); /*entry: get a nis for deposit parameter, exit: deposit the nis to the balance with the requested input check*/

    /*static methods*/

    static int getSumWithdraw() { return sumWithdraw; }; /*return the final sum of draws from all the accounts together*/

    static int getSumDeposit() { return sumDeposit; }; /*return the final sum of deposits from all the accounts together*/

    /*temp method*/

    void inputCheck(int accNum, int _code, string _email);/* entry: get account object , exit: throw the requested errors of incorrect input*/
};