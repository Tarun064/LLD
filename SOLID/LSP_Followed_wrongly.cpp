#include <bits/stdc++.h>
using namespace std;

class Account{
    public:
      virtual void deposit(double amount)=0; // pure virtual function
        virtual void withdraw(double amount)=0; // pure virtual function
};

class SavingsAccount: public Account{
    private:
        double balance;
    public:
        SavingsAccount(){
            balance=0;
        }
        void deposit(double amount){
            balance+=amount;
            cout<<"Deposited "<<amount<<" to savings account. New balance: "<<balance<<endl;
        }
        void withdraw(double amount){
            if(amount>balance){
                cout<<"Insufficient funds!"<<endl;
                return;
            }
            balance-=amount;
            cout<<"Withdrawn "<<amount<<" from savings account. New balance: "<<balance<<endl;
        }
};

class CurrentAccount: public Account{
    private:
        double balance;
    public:
        CurrentAccount(){
            balance=0;
        }
        void deposit(double amount){
            balance+=amount;
            cout<<"Deposited "<<amount<<" to current account. New balance: "<<balance<<endl;
        }
        void withdraw(double amount){
            if(amount>balance){
                cout<<"Insufficient funds!"<<endl;
                return;
            }
            balance-=amount;
            cout<<"Withdrawn "<<amount<<" from current account. New balance: "<<balance<<endl;
        }
}; 

class FixedTermAccount: public Account{
    private:
        double balance;
    public:
        FixedTermAccount(){
            balance=0;
        }
        void deposit(double amount){
            balance+=amount;
            cout<<"Deposited "<<amount<<" to fixed term account. New balance: "<<balance<<endl;
        }
        void withdraw(double amount){
            throw logic_error("Cannot withdraw from fixed term account!"); // Cannot withdraw from fixed term account
        }
};

class BankClient{
    private:
        vector<Account*> accounts;
    public:
        BankClient(vector<Account*> accounts){
            this->accounts=accounts;
        }
        void processTransactions(){
            for(Account* account:accounts){
                account->deposit(1000); // deposit 1000 to each account
                
                if(typeid(*account) == typeid(FixedTermAccount)){
                    cout<<"Skipping withdrawal for Fixed Term Account."<<endl;
                }
                else{
                    try{
                        account->withdraw(500); // withdraw 500 from each account
                    }
                    catch(logic_error& e){
                        cout<<"Exception: "<<e.what()<<endl; // handle exception for fixed term account
                    }
                }
            }
        }
};

int main(){
    vector<Account*> accounts;
    accouts.push_back(new SavingsAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());
    
    BankClient* client = new BankClient(accounts);
    client->processTransactions(); //Throws exception for fixed term account while withdrawing

    return 0;
}