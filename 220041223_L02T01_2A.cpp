#include <iostream>

using namespace std;

int main(){
    int a, b, c, d, num, deno;
    char frac;

    cout<<"Enter the first fraction: ";
    cin>>a>>frac>>b;

    cout<<"Enter the second fraction: ";
    cin>>c>>frac>>d;

    num = (a*d)+(b*c);
    deno= b*d;

    cout<<"The sum is "<<num<<"/"<<deno<<endl;

    
}