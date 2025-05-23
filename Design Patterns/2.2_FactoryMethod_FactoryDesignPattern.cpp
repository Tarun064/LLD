#include <bits/stdc++.h>
using namespace std;

//product class and subclasses
class Burger{
    public:
        virtual void prepare()=0; // pure virtual function
        virtual ~Burger(){} // virtual destructor
};

class BasicBurger: public Burger{
    public:
        void prepare() override{
            cout<<"Preparing basic burger"<<endl;
        }
};

class StandardBurger: public Burger{
    public:
        void prepare() override{
            cout<<"Preparing standard burger"<<endl;
        }
};
class PremiumBurger: public Burger{
    public:
        void prepare() override{
            cout<<"Preparing premium burger"<<endl;
        }
};
class BasicWheatBurger: public Burger{
    public:
        void prepare() override{
            cout<<"Preparing basic wheat burger"<<endl;
        }
};
class StandardWheatBurger: public Burger{
    public:
        void prepare() override{
            cout<<"Preparing standard wheat burger"<<endl;
        }
};
class PremiumWheatBurger: public Burger{
    public:
        void prepare() override{
            cout<<"Preparing premium wheat burger"<<endl;
        }
};

//factory and is concretion
class BurgerFactory{
    public:
        virtual Burger* createBurger(string& type)=0;
};

class SinghBurger: public BurgerFactory{
    public:
        Burger* createBurger(string& type) override{
            if(type=="basic"){
                return new BasicBurger();
            }
            else if(type=="standard"){
                return new StandardBurger();
            }
            else if(type=="premium"){
                return new PremiumBurger();
            }
            else{
                throw invalid_argument("Invalid burger type");
            }
        }
};
class KingBurger: public BurgerFactory{
    public:
        Burger* createBurger(string& type) override{
            if(type=="basic"){
                return new BasicWheatBurger();
            }
            else if(type=="standard"){
                return new StandardWheatBurger();
            }
            else if(type=="premium"){
                return new PremiumWheatBurger();
            }
            else{
                throw invalid_argument("Invalid burger type");
            }
        }
};

int main(){
    string type="basic";
    BurgerFactory* factory=new KingBurger();
    Burger* burger=factory->createBurger(type);
    burger->prepare(); // Preparing basic burger
    delete burger;
}