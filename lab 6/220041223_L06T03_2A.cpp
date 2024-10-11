#include <iostream>

using namespace std;

class Celcius;
class Fahrenheit;
class Kelvin;

class Celcius{
    private:
        float temp;
    public:
        Celcius(float t = 0.0){
            if(t>=-273.15) temp = t;
            else{
                temp = -273.15;
            }
        }
        
        void assign(float t){
            if(temp>=-273.15) temp = t;
            else temp = -273.15;
        }
        void display() const{
            cout<<"The temperature is "<<temp<<" Celcius."<<endl;
        }
        operator Fahrenheit();
        operator Kelvin();
        
        float getTemperature() const{
            return temp;
        }
        
};

class Fahrenheit{
    private:
        float temp;
    public:
        Fahrenheit(float t=32.0){
            if(t>=-459.67) temp= t;
            else temp = -459.67;
        }
        void assign(float t){
        if(t>=-459.67) temp = t;
        else temp = -459.67;
        }
        
        void display() const{
            cout<<"The temperature is "<<temp<<" Fahrenheit."<<endl;
        }
        
         operator Celcius(){
             return Celcius((temp-32)*5/9);
         };
         operator Kelvin();
};

class Kelvin{
    private:
        float temp;
        
    public:
        Kelvin(float t = 273.15){
            if(t>=0.0) temp = t;
            else temp = 0.0;
        }
        
        void assign(float t){
            if(t>=0.0) temp = t;
            else temp = 0.0;
        }
        void display() const{
            cout<<"The temperature is "<<temp<<" Kelvin."<<endl;
        }
        
        operator Fahrenheit(){
            return Fahrenheit(((temp-273.15)*9/5)+32);
        }
        operator Celcius(){
            return Celcius(temp-273.15);
        }
};

Celcius::operator Kelvin(){
    return Kelvin(temp+273.15);
}
Celcius::operator Fahrenheit(){
    return Fahrenheit((temp*9/5)+32);
}
Fahrenheit::operator Kelvin(){
    return Kelvin((temp + 459.67)*5/9);
}


int main() {
    //celcius ops
    Celcius ctemp(257.0);
    ctemp.display();
    
    Fahrenheit ftemp = ctemp;
    ftemp.display();
    
    Kelvin ktemp = ctemp;
    ktemp.display();
    cout<<endl;
    //fahrenheit ops
    Fahrenheit ftemp1(34.56);
    ftemp1.display();
    
    Celcius ctemp1 = ftemp1;
    ctemp1.display();
    
    Kelvin ktemp1 = ftemp1;
    ktemp1.display();
    cout<<endl;
    //kelvin opps
    
    Kelvin ktemp2(23.25);
    ktemp2.display();
    
    Celcius ctemp2 = ktemp2;
    ctemp2.display();
    
    Fahrenheit ftemp2 = ktemp2;
    ftemp2.display();
    cout<<endl;
    
    

    return 0;
}
