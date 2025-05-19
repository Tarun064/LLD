#include <bits/stdc++.h>
using namespace std;

class Product{
    public:
    string name;
    double price;

    Product(string name,double price){
        this->name=name;
        this->price=price;
    }
};

class ShoppingCart{
    private:
    vector<Product*> products;
    public:

    void addProduct(Product* p){ //setter method
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){ //getter method
        return products;
    }

    //1. calculates total price of all products in the cart
    double calculateTotalPrice(){
        double totalPrice=0;
        for(Product* p:products){
            totalPrice+=p->price;
        }
        return totalPrice;
    }
};

class ShoppingCartPrinter{
    private:
    ShoppingCart* cart;
    public:
    void ShoppingCartPrinter(ShoppingCart* cart){
        this->cart=cart;
    }

    void printInvoice(){
        cout<<"Shopping Cart Invoice: "<<endl;
        for(Product* p:cart->getProducts()){
            cout<<p->name<<" - "<<p->price<<endl;
        }
        cout<<"Total Price: "<<cart->calculateTotalPrice()<<endl;
    }
};

//abstract class worked as a interface for all the db classes
class Persistence{
    private:
    ShoppingCart* cart;
    public:
        virtual void save(ShoppingCart* cart)=0; // pure virtual function
};

class SqlPersistence: public Persistence{
    public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving to SQL database..."<<endl;
        //Database code here depends on oiur logic how we are connecting to db and all
    }
};
class MongoDBPersistence: public Persistence{
    public:
    void save(ShoppingCart* cart) override{
        cout<<"Saving to NoSQL database..."<<endl;
        //Database code here depends on oiur logic how we are connecting to db and all
    }
};

class FilePersistence: public Persistence{
    public:
    void save(ShoppingCart* cart)override{
        cout<<"Saving to file..."<<endl;
        //Database code here depends on oiur logic how we are connecting to db and all
    }
};


    private:
    ShoppingCart* cart;
    public:
    void ShoppingCartDatabase(ShoppingCart* cart){
        this->cart=cart;
    }

    void saveToSQLDatabase(){
        cout<<"Saving to database..."<<endl;
        //Database code here depends on oiur logic how we are connecting to db and all
    }

    //here we are violating OCP as we are adding new method to save to different db
    void saveToMongoDB(){
        cout<<"Saving to NoSQL database..."<<endl;
        //Database code here depends on oiur logic how we are connecting to db and all
    }

    void saveToFile(){
        cout<<"Saving to file..."<<endl;
        //Database code here depends on oiur logic how we are connecting to db and all
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 100000));
    cart->addProduct(new Product("Mobile", 50000.0));
    cart->totalPrice(); // calculates total price

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice(); // prints invoice

    Persistence* db = new SqlPersistence();
    Persistence* mongo = new MongoDBPersistence();
    Persistence* file = new FilePersistence();

    db->save(cart); // saves to SQL database
    mongo->save(cart); // saves to MongoDB
    file->save(cart); // saves to File

    return 0;
}