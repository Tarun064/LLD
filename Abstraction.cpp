#include <iostream>
#include <string>
using namespace std;

class Car{ //abstracted class directly instatiate nhi krr skte
public:
    virtual void startEngine() = 0; // virtual se hmm yha sirf methods ko hmm sirf declare krr rhe hai define uski child class jo usse inherit krega krega voh krega
    virtual void shiftGear() = 0; // pure virtual function
    virtual void accelerate() = 0; // pure virtual function
    virtual void brake() = 0; // pure virtual function
    virtual void stopEngine() = 0; // pure virtual function
    virtual ~Car() {} // virtual destructor
};

class SportsCar : public Car{
public:
    string brand;
    string model;
    bool isEngineOn;
    int currentGear;
    int currentSpeed;

    SportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout<<"Engine started and car is ready to roar!"<<endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout<<"Engine is off. Start the engine first!"<<endl;
            return;
        }
        currentGear=gear;
        cout<<"Gear shifted to "<<currentGear<<endl;
    }

    void accelerate(){
        if(!isEngineOn){
            cout<<"Engine is off. Start the engine first!"<<endl;
            return;
        }
        currentSpeed += 20;
        cout<<"Accelerating to "<<currentSpeed<<" km/h"<<endl;
    }

    void brake(){
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout<<"Braking. Current speed is "<<currentSpeed<<" km/h"<<endl;
    }
    
    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout<<"Engine stopped. Car is now off."<<endl;
    }
};

int main(){
    Car* myCar = new SportsCar("Ferrari", "488 GTB");
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    myCar->stopEngine();
}


