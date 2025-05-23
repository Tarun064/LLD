#include <iostream>
#include <string>
using namespace std;

class Car{
protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    void startEngine(){
        isEngineOn = true;
        cout<<"Engine started and car is ready to roar!"<<endl;
    }
    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout<<"Engine stopped. Car is now off."<<endl;
    }

    virtual void accelerate(){} //abstract method for dynamic polymorphism
    virtual void brake(){} //mtlb hmm yha kehna cha rhe hai ki hmne sirf ek method define kiya but jo bhi unhe use krega abb unki responsiility hogi usse define krne ki kyunki 
    virtual ~Car(){} //hmne isse abstract class bna diya hai aur jo bhi isse use krega unka tareeka alg alg ho slta hai iss method ko krne ka isse kehte hai method overriding
};

class ManualCar : public Car{
    private:
        int currentGear;
    public:
        ManualCar(string b, string m) : Car(b,m){
            currentGear=0;
        }
        void shiftGear(int gear){
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
};
class AutomaticCar : public Car{
private:
    int batteryLevel;
public:
    AutomaticCar(string b, string m) : Car(b,m){
        batteryLevel=100;
    }
    void chargeBattery(){
        batteryLevel = 100;
        cout<<"Battery charged to "<<batteryLevel<<"%"<<endl;
    }
    void accelerate(){
        if(!isEngineOn){
            cout<<"Engine is off. Start the engine first!"<<endl;
            return;
        }
        if(batteryLevel <= 0){
            cout<<"Battery is dead. Please charge the battery!"<<endl;
            return;
        }
        currentSpeed += 15;
        cout<<"Accelerating to "<<currentSpeed<<" km/h"<<endl;
    }
    void brake(){
        currentSpeed -= 15;
        if(currentSpeed < 0) currentSpeed = 0;
        cout<<"Braking. Current speed is "<<currentSpeed<<" km/h"<<endl;
    }

};

int main(){
    ManualCar* myManualCar = new ManualCar("Toyota", "Corolla");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"-----------------------------"<<endl;


    AutomaticCar* myAutomaticCar = new AutomaticCar("Tesla", "Model S");
    myAutomaticCar->startEngine();  
    myAutomaticCar->accelerate();
    myAutomaticCar->accelerate();
    myAutomaticCar->brake();        
    myAutomaticCar->chargeBattery();
    myAutomaticCar->stopEngine();
    delete myAutomaticCar;

    return 0;
}