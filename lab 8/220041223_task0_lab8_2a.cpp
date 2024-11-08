#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

class Shape{
    public:
    virtual void whoAmI() const = 0;
};
class TwoDimensionalShape : public Shape{
    public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class ThreeDimensionalShape : public Shape{
    public:
    virtual double surfaceArea() const = 0;
    virtual double volume() const = 0;
};
class Square: public TwoDimensionalShape{
    private:
    double side;

    public:
    Square(double s) : side(s) {}

    void whoAmI() const{
        cout << "I am a Square. I am a two-dimensional shape." << endl;
    }
    double area() const {
        return side*side;
    }
    double perimeter() const{
        return 4*side;
    }
};

class Circle: public TwoDimensionalShape{
    private:
    double radius;

    public:
    Circle(double r) : radius(r) {}

    void whoAmI() const{
        cout << "I am a Circle. I am a two-dimensional shape." << endl;
    }
    double area() const {
        return PI*radius*radius;
    }
    double perimeter() const{
        return 2*PI*radius;
    }
};

class Cube: public ThreeDimensionalShape{
    private:
    double side;

    public:
    Cube(double s) : side(s) {}
    void whoAmI() const{
        cout << "I am a Cube. I am a three-dimensional shape." << endl;
    }
    double surfaceArea() const{
        return 6*side*side;
    }
    double volume() const{
        return side*side*side;
    }
};

class Sphere: public ThreeDimensionalShape{
    private:
    double radius;

    public:
    Sphere(double r) : radius(r) {}
    void whoAmI() const{
        cout << "I am a Sphere. I am a three-dimensional shape." << endl;
    }
    double surfaceArea() const{
        return 4*PI*radius*radius;
    }
    double volume() const{
        return (4/3)*PI*radius*radius*radius;
    }
};

int main() {
    Square square(5);
    square.whoAmI();
    cout << "Area: " << square.area() << endl;
    cout << "Perimeter: " << square.perimeter() << endl;
    cout << endl;

    Circle circle(3);
    circle.whoAmI();
    cout << "Area: " << circle.area() << endl;
    cout << "Perimeter (Circumference): " << circle.perimeter() << endl;
    cout << endl;


    Cube cube(4);
    cube.whoAmI();
    cout << "Surface Area: " << cube.surfaceArea() << endl;
    cout << "Volume: " << cube.volume() << endl;
    cout << endl;


    Sphere sphere(6);
    sphere.whoAmI();
    cout << "Surface Area: " << sphere.surfaceArea() << endl;
    cout << "Volume: " << sphere.volume() << endl;
    cout << endl;

    return 0;
}
