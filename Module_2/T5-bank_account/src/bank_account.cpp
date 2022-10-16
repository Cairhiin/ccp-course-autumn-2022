/*
**Objective:** Get familiar with basic use of classes and methods,
learning to implement your own simple classes based on a given class
definition.

In this task you will implement a full class handling a bank account,
starting from constructor, along with a few functions for accessing
the class content and operating it. There is also one function outside
the class, *Transfer*, that will transfer money between two bank
accounts.

Read file *bank_account.hpp* carefully, there are comments on each
class member describing what the function should do, and based on the
comments you should write your implementation in *bank_account.cpp*

The given main function prints the following output when everything works:

    Owner: Rasse Rikas
    Number: 21345
    Balance: 0
    Depositing 100 to account.
    Balance: 100
    Withdrawing 50 from account.
    Balance: 50
    Trying to withdraw 100.
    Balance: 50
    Account num: 43662, owned by: Kaisa Kroisos, balance: 1000 eur.
    Transfering 100.0 from Kaisa Kroisos to Rasse Rikas.
    Transfer succesful!
    Transfering 500.0 from Rasse Rikas to Kaisa Kroisos.
    Transfer failed!
*/

#include "bank_account.hpp"
#include <iostream>

BankAccount::BankAccount(std::string const& owner, std::string const& account_number, double balance) 
: owner_(owner), account_number_(account_number), balance_(balance) { 
}

std::string BankAccount::GetOwner() const {
    return owner_;
}

std::string BankAccount::GetNumber() const {
    return account_number_;
}

double BankAccount::GetBalance() const {
    return balance_;
}

void BankAccount::Deposit(double amount) {
    balance_ += amount;
}

bool BankAccount::Withdraw(double amount) {
    if (balance_ - amount < 0) {
        return false;
    }
    else {
        balance_ -= amount;
        return true;
    }
}

void BankAccount::Print() const {
    std::cout << "Account num: " << account_number_ << ", owned by: " << owner_ << ", balance: " << balance_ << " eur." << std::endl;
}

bool Transfer(BankAccount& source_account, BankAccount& target_account, double amount) {
    if (!source_account.Withdraw(amount)) {
        return false;
    }
    else { 
        target_account.Deposit(amount);
        return true;
    }
}