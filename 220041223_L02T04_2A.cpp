#include <iostream>
#include <string>

using namespace std;

struct car{
    string brand;
    string model;
    int year;
    string fuel;
    int mileage;
};

void carinfo(const car& car1){
    cout<<"Brand: "<<car1.brand<<endl;
    cout<<"Model: "<<car1.model<<endl;
    cout<<"Year: "<<car1.year<<endl;
    cout<<"Fuel type: "<<car1.fuel<<endl;
    cout<<"Mileage: "<<car1.mileage<<" km/l"<<endl;
}

int main(){
    int n,i;
    int distance = 100;
    float cost, fprice;
    cout<<"Enter the number of cars: ";
    cin>>n;

    car cars[n];
    for(i=0;i<n;i++){
        cout<<"Enter info about Car "<<i+1<<endl;

        cout<<"Brand: ";
        cin>>cars[i].brand;

        cout<<"Model: ";
        cin>>cars[i].model;

        cout<<"Year: ";
        cin>>cars[i].year;

        cout<<"Fuel type (Petrol, Diesel, Electric, Hybrid: ";
        cin>>cars[i].fuel;

        cout<<"Mileage: ";
        cin>>cars[i].mileage;
    }

    for(i=0;i<n;i++){
        cout<<"\nCar "<<i+1<<":"<<endl;
        carinfo(cars[i]);

        if(cars[i].mileage>15){
            cout<<"This car is fuel-efficient."<<endl;
        }
        else cout<<"This car is not fuel-efficient."<<endl;

        if(cars[i].fuel=="Electric"){
            cout<<"This car is electric, efficiency measured in km/charge."<<endl;

        }
        else{
            if(cars[i].fuel == "Petrol"){
                cost = (distance/cars[i].mileage)*0.89;
            }
            else if(cars[i].fuel == "Diesel"){
                cost = (distance/cars[i].mileage)*3.24;
            }
            else{
                cost = (distance/cars[i].mileage)*2.45;
            }
            cout<<"Estimated fuel cost for 100 km: "<<"$"<<cost<<endl;
        }
    }



    return 0;
}
