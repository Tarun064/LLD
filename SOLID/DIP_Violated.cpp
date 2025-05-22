#include <iostream>
using namespace std;

class MySQLDatabase{ //Low level module
    public:
        void saveToSql(string data){
            cout<<"Connected to MySQL database and data inserted into user values"<<data<<endl;
        }
};

class MongoDBDatabase{ //Low level module
    public:
        void saveToMongo(string data){
            cout<<"Connected to MongoDB database and inserted value for user {name: "<<data<<"},"<<endl;
        }
};

//abb yha userservice jo hai voh trightly coupled ho gya hai low level module se
class UserService{  //High level module
    private:
        MySQLDatabase sqlDb; //direct dependency ON MYSQL
        MongoDBDatabase mongoDb; //deirect dependency on mongo db
    public:
        void storeUserToSQL(string name){
            sqlDb.saveToSql(name); //sql db specific code
        }

        void storeUserToMongo(string name){
            mongoDb.saveToMongo(name); //mongo db specific code
        }
};

int main(){
    UserService userService;
    userService.storeUserToSQL("John Doe");
    userService.storeUserToMongo("Jane Doe");
    return 0;
}