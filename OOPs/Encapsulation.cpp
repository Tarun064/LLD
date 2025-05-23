#include <iostream>
#include <string>
using namespace std;

class SportsCar{
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentGear;
        int currentSpeed;
        string tyre;
    public:
        SportsCar(string b, string m) {
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
            tyre="Michelin"; // default tyre
        }

        int getCurrentSpeed(){
            return this->currentSpeed;
        }

        string getTyre(){
            return this->tyre;
        }

        void setTyre(string t){
            this->tyre=t; //yha direct tyre ki value set krne se pehle agr chahe toh kuch validations lgaa skte hai aur uske baad change krr skte haoi
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

        ~SportsCar() {
            // Destructor
            cout << "Car object destroyed." << endl;
        }
    };
    
    int main(){
        SportsCar* myCar = new SportsCar("Ferrari", "488 GTB");
        myCar->startEngine();
        myCar->shiftGear(1);
        myCar->accelerate();
        myCar->shiftGear(2);
        myCar->accelerate();
        myCar->brake();
        myCar->stopEngine();
        // myCar->currentSpeed = 500; //abb agr hmm yeah =krenge toh error aayega kyuki currentSpeed private hai aur private members ko access nahi kar sakte
    }
    
    
    