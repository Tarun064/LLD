#include <iostream>
#include <stdexcept>

using namespace std;

class TwoDimensionalShape {
    public:
        virtual double area() = 0; // pure virtual function for area
};

class ThreeDimensionalShape {
    public:
    virtual double area() = 0; // pure virtual function for volume
        virtual double volume() = 0; // pure virtual function for volume
};

class Square:public TwoDimensionalShape{
    private:
        double side;
    public:
        Square(double s):side(s){}
        double area() override {
            return side * side;
        }
};

//recatangle is also a 2d shape and forced to implement volume method
class Rectangle:public TwoDimensionalShape{
    private:
        double length;
        double width;
    public:
        Rectangle(double l,double w):length(l),width(w){}
        double area() override {
            return length * width;
        }
};

//cube is a 3d shape so it actually has a volume
class Cube:public ThreeDimensionalShape{
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
    TwoDimensionalShape* square = new Square(5);
    TwoDimensionalShape* rectangle = new Rectangle(5,10);
    ThreeDimensionalShape* cube = new Cube(5);
    cout<<"Area of square: "<<square->area()<<endl; // Area of square: 25
    cout<<"Area of rectangle: "<<rectangle->area()<<endl; // Area of rectangle: 50
    cout<<"Area of cube: "<<cube->area()<<endl; // Area of cube: 150
    cout<<"Volume of cube: "<<cube->volume()<<endl; // Volume of cube: 125
    delete square;
    delete rectangle;
    delete cube;

    return 0;
}