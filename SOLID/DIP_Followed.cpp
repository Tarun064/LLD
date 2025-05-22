#include <iostream>
using namespace std;

class Database{ //Interface (Abstraction)
    public:
        virtual void save(string data)=0; //pure virtual function
};

class MySQLDatabase:public Database{ //Low level module
    public:
        void save(string data){
            cout<<"Connected to MySQL database and data inserted into user values"<<data<<endl;
        }
};

class MongoDBDatabase:public Database{ //Low level module
    public:
        void save(string data){
            cout<<"Connected to MongoDB database and inserted value for user {name: "<<data<<"},"<<endl;
        }
};

class UserService{  //High level module (loosely coupled)
    private:
        Database* db; //Dependency injection
    public:
        userService(Database* database){
            db=database;
        }

        void storeUser(string name){
            db->save(name); //db specific code
        }
};

int main(){
    // Database* sqlDb = new MySQLDatabase(); //Low level module
    // Database* mongoDb = new MongoDBDatabase(); //Low level module
    // UserService userService(sqlDb); //Dependency injection
    // userService.storeUser("John Doe"); //store user to sql database

    MySQLDatabase sqlDb; //Low level module
    MongoDBDatabase mongoDb; //Low level module
    userService userService(&sqlDb); //Dependency injection
    userService.storeUser("John Doe"); //store user to sql database 
    userService userService2(&mongoDb); //Dependency injection
    userService2.storeUser("Jane Doe"); //store user to mongo database
    return 0;
}