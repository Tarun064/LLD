#include <bits/stdc++.h>
using namespace std;

//class Invariant of parent class object should not be broken by the child class object
//hence child class can either maintain or strenghten the parent class invariant but never narrows it down.

//invariant: balance can not be negative in any case
class BankAccount{
    protected:
     double balance;
    public:
        BankAccount(double b){
            if(b<0) throw invalid_argument("Balance can not be negative!");
            balance=b;
        }
        virtual void withdraw(double amount){
            if(balance - amount < 0){
                throw runtime_error("Insufficient funds!");
            }
            balance-=amount;
            cout<<"Withdrawn "<<amount<<" from bank account. New balance: "<<balance<<endl;
        }
};

//Brakes Invariant: should not be allowed.
class CheatAccount: public BankAccount{
    public:
        CheatAccount(double b):BankAccount(b){}
        void withdraw(double amount) override{
            balance-=amount; //LSP break -ve balance allowed in this case
            cout<<"Withdrawn "<<amount<<" from cheat account. New balance: "<<balance<<endl;
        }
};

int main(){
    BankAccount* account = new BankAccount(1000);
    account->withdraw(1000); // Withdrawn 500 from bank account. New balance: 500
}