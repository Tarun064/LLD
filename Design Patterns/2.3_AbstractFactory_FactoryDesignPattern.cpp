#include <bits/stdc++.h>
using namespace std;

//product 1:
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

//product 2:
class GarlicBread{
    public:
        virtual void prepare()=0; // pure virtual function
        virtual ~GarlicBread(){} // virtual destructor
};
class BasicGarlicBread: public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing basic garlic bread"<<endl;
        }
};
class StandardGarlicBread: public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing standard garlic bread"<<endl;
        }
};  
class PremiumGarlicBread: public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing premium garlic bread"<<endl;
        }
};
class BasicWheatGarlicBread: public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing basic wheat garlic bread"<<endl;
        }
};
class StandardWheatGarlicBread: public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing standard wheat garlic bread"<<endl;
        }
};
class PremiumWheatGarlicBread: public GarlicBread{
    public:
        void prepare() override{
            cout<<"Preparing premium wheat garlic bread"<<endl;
        }
};

//factory and is concretion
class MealFactory{
    public:
        virtual Burger* createBurger(string& type)=0;
        virtual GarlicBread* createGarlicBread(string& type)=0;
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
        GarlicBread* createGarlicBread(string& type) override{
            if(type=="basic"){
                return new BasicGarlicBread();
            }
            else if(type=="standard"){
                return new StandardGarlicBread();
            }
            else if(type=="premium"){
                return new PremiumGarlicBread();
            }
            else{
                throw invalid_argument("Invalid garlic bread type");
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
        GarlicBread* createGarlicBread(string& type) override{
            if(type=="basic"){
                return new BasicWheatGarlicBread();
            }
            else if(type=="standard"){
                return new StandardWheatGarlicBread();
            }
            else if(type=="premium"){
                return new PremiumWheatGarlicBread();
            }
            else{
                throw invalid_argument("Invalid garlic bread type");
            }
        }
};

int main(){
    string burgerType="standard";
    string garlicBreadType="premium";

    MealFactory* factory= new SinghBurger();
    Burger* burger = factory->createBurger(burgerType);
    GarlicBread* garlicBread = factory->createGarlicBread(garlicBreadType);
    burger->prepare(); // Preparing standard burger
    garlicBread->prepare(); // Preparing premium garlic bread
    
    delete burger;
    delete garlicBread;
    delete factory;

    return 0;

}