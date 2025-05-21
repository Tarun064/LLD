#include <iostream>
#include <stdexcept>

using namespace std;

//single shape for all shapes - (Violated ISP)
class Shape {
    public:
        virtual double area() = 0; // pure virtual function for area
        virtual double volume() = 0; // 2d shpes dont have volume
};

class Square:public Shape{
    private:
        double side;
    public:
        Square(double s):side(s){}
        double area() override {
            return side * side;
        }
        double volume() override {
            throw logic_error("Square does not have volume!");
        }
};

//recatangle is also a 2d shape and forced to implement volume method
class Rectangle:public Shape{
    private:
        double length;
        double width;
    public:
        Rectangle(double l,double w):length(l),width(w){}
        double area() override {
            return length * width;
        }
        double volume() override {
            throw logic_error("Rectangle does not have volume!");
        }
};

//cube is a 3d shape so it actually has a volume
class Cube:public Shape{
    private:
        double side;
    public:
        Cube(double s):side(s){}
        double area() override {
            return 6 * side * side;
        }
        double volume() override {
            return side * side * side;
        }
};


int main(){
    Shape* square = new Square(5);
    Shape* rectangle = new Rectangle(5,10);
    Shape* cube = new Cube(5);

    cout<<"Square area: "<<square->area()<<endl;
    cout<<"Rectangle area: "<<rectangle->area()<<endl;
    cout<<"Cube area: "<<cube->area()<<endl;
    cout<<"Cube volume: "<<cube->volume()<<endl;

    try{
        square->volume(); // this will throw an exception
    }
    catch(const logic_error& e){
        cout<<e.what()<<endl; // catching exception for square volume
    }

    return 0;
}