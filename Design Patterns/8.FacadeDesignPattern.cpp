#include <bits/stdc++.h>
using namespace std;

//subsystems
class PowerSupply {
public:
    void providePower() {
        cout << "Power Supply: Providing power to the system." << endl;
    }
};

class CoolingSystem {
public:
    void startFans() {
        cout << "Cooling System: Activating cooling." << endl;
    }
};

class CPU {
public:
    void initialize() {
        cout << "CPU: Initializing CPU." << endl;
    }
};

class Memory {
public:
    void selfTest() {
        cout << "Memory: Loading data into memory." << endl;
    }
};

class HardDrive {
public:
    void spinUp() {
        cout << "Hard Drive: Loading data from disk." << endl;
    }
};

class BIOS {
public:
    void boot(CPU& cpu, Memory& memory) {
        cout << "BIOS: Running diagnostics." << endl;
        cpu.initialize();
        memory.selfTest();
    }
};

class OperatingSystem {
public:
    void load() {
        cout << "Operating System: Loading OS." << endl;
    }
};

//facade class
class ComputerFacade {
private:
    PowerSupply powerSupply;
    CoolingSystem coolingSystem;
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
    BIOS bios;
    OperatingSystem os;
public: 
void startComputer() {
    cout << "Computer Facade: Starting up the computer." << endl;
    powerSupply.providePower();
    coolingSystem.startFans();
    bios.boot(cpu, memory);
    hardDrive.spinUp();
    os.load();
    cout << "Computer Facade: Computer is now ON." << endl;
}
};

//client code
int main(){
    ComputerFacade computer; // create a facade object
    computer.startComputer(); // start the computer using the facade
    return 0;
}