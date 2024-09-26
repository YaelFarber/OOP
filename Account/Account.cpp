/* Author: Yael Farber ID: 326770468
Course: Advanced Programming
Targil 5 Sheela 1
Program doc: creating a class that manage ATM, with the options to create account, deposite or withdraw nis */

#include "Clock.h"
#include "Account.h"
#include <string>

/*static fields*/

/*the sum of all draws in the "bank" (all the accounts together)*/
int Account::sumWithdraw = 0;

/*the sum of all deposits in the "bank" (all the accounts together)*/
int Account::sumDeposit = 0;

/*set parameters constructor*/
Account::Account(int accNum, int _code, float _balance, string _email)
{
    inputCheck(accNum, _code, _email);
    
    accountNumber = accNum;
    code = _code;
    balance = _balance;
    email = _email;
}

/*operator method*/

/*entry: by oopertator >>account object , exit: set the input in the account object*/
istream &operator>>(istream &is, Account &account1)
{
    int accNum, _code;
    string _email;

    is >> accNum >> _code >> _email;

    account1.inputCheck(accNum, _code, _email);

    account1.accountNumber = accNum;
    account1.code = _code;
    account1.email = _email;

    return is;
}

/*entry: get a nis parameter, exit: withdraw the nis from the balance with the requested input check*/
void Account::withdraw(int nis)
{
    if (balance - nis < (-6000))
        throw "ERROR: cannot have less than - 6000 NIS!\n";
    if (nis > 2500)
        throw "ERROR: cannot withdraw more than 2500 NIS!\n";
    balance -= nis;
    sumWithdraw += nis;
}

/*entry: get a nis for deposit parameter, exit: deposit the nis to the balance with the requested input check*/
void Account::deposit(int de)
{
    if (de > 10000)
        throw "ERROR: cannot deposit more than 10000 NIS!\n";
    balance += de;
    sumDeposit += de;
}

void Account::inputCheck(int accNum, int _code, string _email) /* entry: get account object , exit: throw the requested errors of incorrect input*/
{
    if (_code > 9999 || _code < 1000)
        throw "ERROR: code must be of 4 digits!\n";
    if (_code / 3 == 0)
        throw "ERROR: wrong code!\n";
    if (_email.find("@") > _email.length())
        throw "ERROR: email must contain @!\n";
    if (_email.find(".com") > _email.length())
        if (_email.find(".co.il") > _email.length())
            throw "ERROR: email must end at .com or .co.il!\n";
    if (_email.find(" ") < _email.length())
        throw "ERROR: wrong email!\n";
}