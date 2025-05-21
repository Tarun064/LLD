#include <bits/stdc++.h>
using namespace std;

// sub class mehtods are not allowed state changes whtra base class never allowed to do so.

class BankAccount{
    protected:
     double balance;
    public:
        BankAccount(double b){
            if(b<0) throw invalid_argument("Balance can not be negative!");
            balance=b;
        }
        //History constraint : withdraw should be allowed.
        virtual void withdraw(double amount){
            if(balance - amount < 0){
                throw runtime_error("Insufficient funds!");
            }
            balance-=amount;
            cout<<"Withdrawn "<<amount<<" from bank account. New balance: "<<balance<<endl;
        }
};

class FixedDepositAccount: public BankAccount{
    public:
        FixedDepositAccount(double b):BankAccount(b){}

        //LSP break! history constraint broke
        //parent class behavior changed : now withdrar is not allowed
        //this class will break the client code taht relies ont he withdraw
        void withdraw(double amount) override{
            throw runtime_error("Withdrawal not allowed from fixed deposit account!");
        }
};

int main(){
    BankAccount* account = new BankAccount(1000);
    account->withdraw(1000); // Withdrawn 500 from bank account. New balance: 500
}