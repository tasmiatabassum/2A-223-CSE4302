#include <iostream>
using namespace std;


class Car{
    private:
        string make;
        string model;
        double fuelCapacity;
        double fuelLevel;
        
    public:
        Car(){fuelLevel =0.0;}
        Car(string m, string d, double fcap,double flev): make(m), model(d), fuelCapacity(fcap), fuelLevel(flev){}
    Car operator+(double add){
        fuelLevel +=add;
        if(fuelLevel>fuelCapacity){
            fuelLevel = fuelCapacity;
            cout<<"Reached max capacity"<<endl;
        }
        cout<<"Current fuel level: "<<fuelLevel<<endl;
        return *this;
    }
    Car operator-(double sub){
        fuelLevel -=sub;
        if(fuelLevel<0){
            fuelLevel = 0;
            cout<<"Reached min capacity"<<endl;
        }
        cout<<"Current fuel level: "<<fuelLevel<<endl;
        return *this;
    }
    
    Car operator +=(float add){
        fuelLevel +=add;
        if(fuelLevel>fuelCapacity){
            fuelLevel = fuelCapacity;
            cout<<"Reached max capacity"<<endl;
        }
        cout<<"Current fuel level: "<<fuelLevel<<endl;
        return *this;
    }
    bool operator ==(const Car& car2) const{
        return (make==car2.make && model==car2.model && fuelLevel==car2.fuelLevel && fuelCapacity ==car2.fuelCapacity);
    }
    bool operator <(const Car & car2) const{
        return fuelLevel <car2.fuelLevel;
    }
    bool operator >(const Car& car2) const{
        return fuelLevel >car2.fuelLevel;
    }
    
    void display(){
        cout<<"Make: "<<make<<", Model: "<<model<<", Fuel Level: "<<fuelLevel<<", Fuel Capacity: "<<fuelCapacity<<endl;
    }
  
};

int main() {
    Car car1("jdfj", "sdff", 300.56, 123.56);
    Car car2("fnbdf", "wnjdebj", 423.45, 23.56);
    
    car1.display();
    car2.display();
    
    car1 = car1+24.34;
    car1.display();
    
    car2+= 10.05;
    car2.display();
    
    car1 = car1-5.798;
    car1.display();
    
    if(car1==car2){
        cout<<"Car1 and Car2 are identical"<<endl;
    }
    else cout<<"Car1 and Car2 are not identical"<<endl;
    
    if(car1>car2) cout<<"Car1's fuel level is more than Car2"<<endl;
    else if(car2>car1) cout<<"Car2's fuel level is more than Car1"<<endl;
    else cout<<"Car1's fuel level is the same as Car2"<<endl;

    return 0;
}