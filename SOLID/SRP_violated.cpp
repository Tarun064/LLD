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

    void addProduct(Product* p){
        products.push_back(p);
    }
    const vector<Product*>& getProducts(){
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
    //2. violating SRP - print invoice should be in different class
    void printInvoice(){
        cout<<"Invoice: "<<endl;
        for(Product* p:products){
            cout<<p->name<<" - "<<p->price<<endl;
        }
        cout<<"Total Price: "<<calculateTotalPrice()<<endl;
    }

    //3. violating SRP saving db should be in different class
    void saveToDatabase(){
        cout<<"Saving to database..."<<endl;
        //Database code here depends on oiur logic how we are connecting to db and all
    }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    Product* p1=new Product("Laptop", 100000);
    cart->addProduct(p1);
    cart->addProduct("Mobile", 50000.0);

    cart->printInvoice(); // prints invoice
    cart->saveToDatabase(); // saves to database

    return 0;
}