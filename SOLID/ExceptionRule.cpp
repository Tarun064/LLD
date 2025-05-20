#include <bits/stdc++.h>
using namespace std;

//Exception Rule:
//A subclass should throw fewer or narrower exceptions than the parent class.
//(but not additonal or broader exceptions) than parent class.
//c++ does not enforce this rule. So no compiation error will be thrown if we do this.

/*

|--std::logic_error    <-- for logical errors detected before runtime
|   |--std::invalid_argument   <-- for invalid arguments passed to a function
|   |--std::domain_error   <-- (Function arg. domain error)for domain errors (e.g., square root of negative number)
|   |--std::length_error   <--exceeding valid length limits
|   |--std::out_of_range   <--array or container index out of range
|
|--std::runtime_error   <-- for errors thagt occur at runtime   
|   |--std::range_error   <--Numeric result out of range
|   |--std::overflow_error   <--Arithmetic overflow error
|   |--std::underflow_error   <--Arithmetic underflow error

*/

class Parent{
    public: // in c++ jhaa noexcept false hoga mtlb voh exception throw krega
    virtual void getValue() noexcept(false){ // parent class method
        throw logic_error("Parent class: Exception thrown"); // throwing exception    
    }
};

class Child: public Parent{
    public:
    void getValue() noexcept(false) override{ // overriding parent class method
        throw invalid_argument("Child class: Exception thrown"); // throwing exception    
    }
};

class Client{
    private:
    Parent* p;
    public:
    Client(Parent* p){
        this->p=p;
    }

    void takeValue(){
        try{
            p->getValue(); // calling parent class method
        }
        catch(const logic_error& e){
            cout<<e.what()<<endl; // catching parent class exception
        }
    }
};

int main(){
    Parent* parent = new Parent();
    Child* child = new Child(); // child class object

    Client* c = new Client(child); // passing child class object to client class
    c->takeValue(); // calling takeValue method of child class

    return 0;
}