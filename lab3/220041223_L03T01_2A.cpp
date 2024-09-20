#include <iostream>
 using namespace std;

 class Temperature{
    private:
        int inc;
        int temp;


    public:
        Temperature(){
            temp =0;
        }
        int settemp(int s){
            temp=s;
        }
        int setIncrementStep(int s){
            inc=s;
        }
        int getTemperature(){
            temp = temp + inc;
            return temp;
        }
        void resetTemperature(){
            temp = 0;
        }

 };

 int main(){
     Temperature temp;
     temp.settemp(6);
     temp.setIncrementStep(6);
     int p =temp.getTemperature();
     cout<<p<<endl;
     temp.resetTemperature();


    return 0;
 }
