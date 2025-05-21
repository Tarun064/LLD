#include <bits/stdc++.h>
using namespace std;

//a preconditionn must be satisfied before a mehtod can be executed
//sub class can wekaen the precondion but cannot strenghten it.

class User{
    //precondition : password should be 8 characters long
    virtual void setPassword(string password){
        if(password.length()<8){
            throw invalid_argument("Password should be at least 8 characters long!");
        }
        cout<<"Password set successfully!"<<endl;
    }
};

class AdminUser: public User{
    //precondition : password should be 6 characters long
    void setPassword(string password) override{
        if(password.length()<6){
            throw invalid_argument("Password should be at least 8 characters long!");
        }
        cout<<"Admin password set successfully!"<<endl;
    }
};

int main(){
    User* user = new AdminUser();
    user->setPassword("123456"); // Password set successfully!
}