#include <bits/stdc++.h>
using namespace std;

//Return Type Rule:
//subtype overriding methods return type can be identical or narrower than the supertype/parent's 
// method return type. This also called as covariant return type.
//c++ inforces this by covariance

class Animal{
    //some commmon animal methods
};

class Dog: public Animal{
    //some additional dog methods related to dog
};

class Parent{
    public:
    virtual Animal* getAnimal(){ // parent class method
        cout<<"Parent class: "<<endl;     
        return new Animal(); // returning animal object
    }
};

class Child: public Parent{
    public:
    Dog* getAnimal() override{ // overriding parent class method
        cout<<"Child class: "<<endl;     
        return new Dog(); // returning dog object
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
           p->getAnimal(); // calling parent class method
       }
};

int main(){
    Parent* parent = new Parent(); 
    Child* child = new Child(); // child class object
    Client* c = new Client(child); // passing child class object to client class
    c->PrintMsg(); // calling print method of child class
}