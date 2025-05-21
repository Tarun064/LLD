#include <bits/stdc++.h>
using namespace std;

//a post condition must be satisfied after method is executed
//sub class can strengthen the post condition but cannot weaken it.

class Car{
    protected:
        int speed;
    public:
        Car(){
            speed=0;
        }
        virtual void accelerate(){
            cout<<"Car accelerated "<<endl;
            speed+=20;
        }
        //post condition: speed should reduce after brake
        virtual void brake(){
            cout<<"Car braked "<<endl;
            speed-=20;
        }
};

//sub class can strengthen the post condition - doesnot violate the LSP
class HybridCar: public Car{
    private:
    int charge;
    public:
        HybridCar():Car(){
            charge=0;
        }
        //post condition:speed should reduce after brake
        //post condition: cahrge must increase
        void brake() override{
            cout<<"Hybrid car braked "<<endl;
            speed-=20; 
            charge+=10; //strengthened post condition
        }
};

int main(){
    Car* hybrid = new HybridCar();
    hybrid->brake(); //works fine hybrid reduces speed and increases charge
    //client doesnot feel any difference between the two classes
}