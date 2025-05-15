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
    virtual ~Car(){}
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

};

int main(){
    ManualCar* myManualCar = new ManualCar("Toyota", "Corolla");
    myManualCar->startEngine();
    myManualCar->shiftGear(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout<<"-----------------------------"<<endl;


    AutomaticCar* myAutomaticCar = new AutomaticCar("Tesla", "Model S");
    myAutomaticCar->startEngine();  
    myAutomaticCar->accelerate();
    myAutomaticCar->brake();        
    myAutomaticCar->chargeBattery();
    myAutomaticCar->stopEngine();
    delete myAutomaticCar;

    return 0;
}