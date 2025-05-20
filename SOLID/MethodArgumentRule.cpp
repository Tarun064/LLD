#include <bits/stdc++.h>
using namespace std;

//Method Argument Rule: 
//subtype methods arguments can be idnetical or wider than the supertype method arguments
//c++ imposes this bhy keeping signature identical.

class Parent{
    public:
    virtual void print(string msg){
        cout<<"Parent class: "<<msg<<endl;     
    }

};

class Child: public Parent{
    public:
    void print(string msg) override{ // overriding parent class method
        cout<<"Child class: "<<msg<<endl;     
    }
};

class Client{
    private:
       Parent* p;
    public:
       Client(Parent* p){
           this->p=p;
       }
       void PrintMsg(){
           p->print("Hello"); // calling parent class method
       }
};

int main(){
    Parent* parent = new Parent(); 
    Parent* child = new Child(); // child class object
    Client* c = new Client(child); // passing child class object to client class
    c->PrintMsg(); // calling print method of child class
}