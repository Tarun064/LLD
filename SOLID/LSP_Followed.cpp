#include <bits/stdc++.h>
using namespace std;

class DepositOnlyAccount{
    public:
        virtual void deposit(double amount)=0; // pure virtual function
};

class WithdrawableAccount:public DepositOnlyAccount{
    public:
        virtual void withdraw(double amount)=0; // pure virtual function
};

class SavingsAccount: public WithdrawableAccount{
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

class CurrentAccount: public WithdrawableAccount{
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

class FixedTermAccount: public DepositOnlyAccount{
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
};

class BankClient{
    private:
        vector<WithdrawableAccount*> withdrawableAccounts;
        vector<DepositOnlyAccount*> depositOnlyAccounts;
    public:
        BankClient(vector<WithdrawableAccount*> withdrawableAccounts, 
            vector<DepositOnlyAccount*> depositOnlyAccounts){
            this->withdrawableAccounts=withdrawableAccounts;
            this->depositOnlyAccounts=depositOnlyAccounts;
        }
        void processTransactions(){
            for(DepositOnlyAccount* account: depositOnlyAccounts){
                account->deposit(1000); // deposit to all accounts
            }
            for(WithdrawableAccount* account: withdrawableAccounts){
                account->deposit(1000); // deposit to all accounts
                account->withdraw(500); // withdraw from all accounts
            }
        }
};

int main(){
    vector<WithdrawableAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingsAccount());
    withdrawableAccounts.push_back(new CurrentAccount());
    
    vector<DepositOnlyAccount*> depositOnlyAccounts;
    depositOnlyAccounts.push_back(new FixedTermAccount());
    
    BankClient* client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
    client->processTransactions(); //Throws exception for fixed term account while withdrawing

    return 0;
}