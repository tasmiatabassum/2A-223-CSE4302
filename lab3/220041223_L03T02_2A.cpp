#include <iostream>
 using namespace std;

 class RationalNumber{
    private:
        int num;
        int deno;


    public:
        RationalNumber(){
            num =1;
            deno =1;
        }
        void assign(int numerator,int denominator){
            num = numerator;
            if(denominator==0){
                cout<<"You can not assign 0 as denominator"<<endl;
                return;
            }
            else deno = denominator;
        }
        float convert(){
            float p = num;
            return p/deno;
        }
        void invert(){
            if(num==0){
                cout<<"You can not assign 0 as denominator."<<endl;
                return;
            }
            else{
                swap(num, deno);
            }

        }
        void print(){
            cout<<"The Rational Number is "<<num<<"/"<<deno<<endl;

        }

 };

 int main(){
     RationalNumber frac;
     frac.assign(3,2);
     frac.print();
     float m= frac.convert();
     cout<<"Your converted number is "<<m<<endl;
     frac.invert();
     frac.print();


    return 0;
 }
