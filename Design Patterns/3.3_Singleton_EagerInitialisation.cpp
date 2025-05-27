#include <bits/stdc++.h>
#include <mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {
        cout<<"Singleton instance created!"<<endl;
    } // Private constructor to prevent instantiation
public:
    static Singleton* getInstance() {
        return instance;
    }
};

//inititlaize the static members
Singleton* Singleton::instance = new Singleton(); // Eager initialization

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if (s1 == s2) {
        cout << "Both instances are the same!" << endl;
    } else {
        cout << "Instances are different!" << endl;
    }

    return 0;
}