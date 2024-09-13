#include <iostream>
using namespace std;

int main(){
    struct fraction{
        int num, deno;
    };
    fraction fract1, fract2, res;
    char div;

    cout<<"Enter the first fraction: ";
    cin>>fract1.num>>div>>fract1.deno;

    cout<<"Enter the second fraction: ";
    cin>>fract2.num>>div>>fract2.deno;

    res.num = (fract1.num*fract2.deno)+(fract2.num*fract1.deno);
    res.deno= fract1.deno*fract2.deno;

    cout<<"Sum is: "<<res.num<<"/"<<res.deno<<endl;
    
    return 0;
}