//
// Created by aolei.bao on 7/7/2021.
//

#ifndef LEARNCPP_ALGORITHM_OOP3_H
#define LEARNCPP_ALGORITHM_OOP3_H
#include <iostream>
#include <string>

using namespace std;


class Account{
protected:
    float balance;
public:
    Account(float b){
        balance = b;
    }

    virtual void Withdraw(float amount) = 0;
    virtual void Deposit(float amount) = 0;
    virtual void printBalance() = 0;
};

class Savings: public Account{
private:
    float interest_rate = 0.8;
public:
    Savings(float b): Account(b){

    }

    void Withdraw(float amount) override{
        balance -= amount * interest_rate;
    }

    void Deposit(float amount) override{
        balance += amount * interest_rate;
    }

    void printBalance() override{
        cout<<"Balance in your saving account: "<<to_string(balance)<<endl;
    }
};

class Current: public Account{
public:
    Current(float b): Account(b){

    }

    void Withdraw(float amount) override{
        balance -= amount;
    }

    void Deposit(float amount) override{
        balance += amount;
    }

    void printBalance() override{
        cout<<"Balance in your saving account: "<<to_string(balance)<<endl;
    }
};


#endif //LEARNCPP_ALGORITHM_OOP3_H
