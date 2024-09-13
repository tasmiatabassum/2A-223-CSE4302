#include <iostream>

using namespace std;

int main(){
    enum etype{laborer, secretary, manager, accountant, executive, researcher};
    etype etype1;
    char emp;

    cout<<"Enter employee type (first letter only) laborer, secretary, manager, accountant, executive, researcher): ";
    cin>>emp;

    switch(emp){
        case 'l': etype1 = laborer; break;
        case 's': etype1 = secretary; break;
        case 'm': etype1= manager; break;
        case 'a': etype1= accountant; break;
        case 'e': etype1= executive; break;
        case 'r': etype1 = researcher; break;

    }
    switch(etype1){
        case laborer: cout<<"Employee type is laborer."; break;
        case secretary: cout<<"Employee type is secretary."; break;
        case manager: cout<<"Employee type is manager."; break;
        case accountant: cout<<"Employee type is accountant."; break;
        case executive: cout<<"Employee type is executive."; break;
        case researcher: cout<<"Employee type is researcher."; break;

    }
    cout<<endl;
    return 0;
}
