#include <bits/stdc++.h>
using namespace std;

//command interface
class Command {
public:
    virtual void execute() = 0; // pure virtual function
    virtual void undo() = 0; // pure virtual function for undo operation
    virtual ~Command() {} // virtual destructor
};

//receiver class
class Light {
public:
    void turnOn() {
        cout << "Light is turned ON" << endl;
    }

    void turnOff() {
        cout << "Light is turned OFF" << endl;
    }
};

class Fan {
public:
    void turnOn() {
        cout << "Fan is turned ON" << endl;
    }

    void turnOff() {
        cout << "Fan is turned OFF" << endl;
    }
};

//concrete commands for light
class LightCommand : public Command {
private:
    Light* light;
public:
    LightCommand(Light* light) : light(light){
        this->light = light; // initialize the receiver
    }

    void execute() override {
        light->turnOn(); // execute the command to turn on the light
    }

    void undo() override {
        light->turnOff(); // undo the command to turn off the light
    }
};

//concrete commands for fan
class FanCommand : public Command {
private:
    Fan* fan;
public:
    FanCommand(Fan* fan) : fan(fan){
        this->fan = fan; // initialize the receiver
    }

    void execute() override {
        fan->turnOn(); // execute the command to turn on the fan
    }

    void undo() override {
        fan->turnOff(); // undo the command to turn off the fan
    }
};

//invoker class: Remote Controller with static 2d array of 6 buttons (3 rows and 2 columns)
class RemoteController {
private:
    static const int numButtons = 4;
    Command* buttons[numButtons]; // array of command pointers
    bool buttonPressed[numButtons]; // array to track button pressed state
public:
    RemoteController() {
        for(int i = 0; i < numButtons; i++) {
            buttons[i] = nullptr; // initialize all buttons to nullptr
            buttonPressed[i] = false; // initialize all buttons to not pressed
        }
    }
    void setCommand(int idx, Command* command) {
        if(idx >= 0 && idx < numButtons ) {
            if(buttons[idx] != nullptr) {
                delete buttons[idx]; // delete previous command if exists
            }
            buttons[idx] = command; // set the command for the button
            buttonPressed[idx] = false; // reset button pressed state
        }
    }

    void pressButton(int idx) {
        if(idx >= 0 && idx < numButtons && buttons[idx] != nullptr) {
            if(buttoPressed[idx]== false) {
                buttons[idx]->execute(); // execute the command if button is not pressed
            } else {
                buttons[idx]->undo(); // undo the command if button is already pressed
            }
            buttonPressed[idx] = !buttonPressed[idx]; // toggle the button pressed state
        }
        else{
            cout<<"No command assigned to that button!"<<endl; // handle invalid button index or no command assigned
        }
    }
    ~RemoteController() {
        for(int i = 0; i < numButtons; i++) {
            if(buttons[i] != nullptr) {
                delete buttons[i]; // delete all commands to free memory
            }
        }
    }
};

int main(){
    Light* light = new Light(); // create a light object
    Fan* fan = new Fan(); // create a fan object

    Command* lightCommand = new LightCommand(light); // create a command for light
    Command* fanCommand = new FanCommand(fan); // create a command for fan

    RemoteController* remote=new RemoteController(); // create a remote controller object

    remote->setCommand(0, lightCommand); // assign light command to button 0
    remote->setCommand(1, fanCommand); // assign fan command to button 1

    cout<<"-----Toggling light button 0-----"<<endl
    remote->pressButton(0); // press button 0 to turn on the light
    remote->pressButton(0); // press button 0 to turn off the light

    cout<<"-----Toggling fan button 1-----"<<endl;
    remote->pressButton(1); // press button 1  to turn on the fan
    remote->pressButton(1); // press button 1  to turn off the fan

    cout<<"-----Pressing invalid button 2-----"<<endl;
    remote->pressButton(2); // press button 2 which has no command assigned

    delete light; // delete light object
    delete fan; // delete fan object
    return 0; // return success
}