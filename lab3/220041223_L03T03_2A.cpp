#include <iostream>
 using namespace std;

 class BankAccount{
    private:
        string customer_name;
        int acc_number;// string should be a better choice
        string acc_type;// enum is a better choice
        float acc_balance;

    public:
        BankAccount(){
            acc_balance = 0;
        }
        void customerDetails(string name, int number){
            customer_name = name;
            acc_number = number;
        }
        void accountType(string type){
            acc_type = type;
        }
        void balance(){
            cout<<"Your balance is: "<<acc_balance<<endl;
        }
        void deposit(float deposit){
            acc_balance += deposit;
            cout<<"Your current balance is: "<<acc_balance<<endl;
        }
        void withdraw(float amount){
            if(acc_balance>=amount){
                acc_balance -=amount;
                cout<<"Your current balance is: "<<acc_balance<<endl;
            }
            else cout<<"You don't have sufficient balance"<<endl;

        }

         void display(){
             cout<<"Customer Name: "<<customer_name<<endl;
             cout<<"Account Number: "<<acc_number<<endl;
             cout<<"Account Type: "<<acc_type<<endl;
             cout<<"Account Balance: "<<acc_balance<<endl;
         }

 };

 int main(){
     BankAccount account;

     account.customerDetails("Tasmia Tabassum", 23455);
     account.accountType("Saving");
     account.balance();
     account.deposit(5000.344);
     account.withdraw(100.45);
     account.display();


    return 0;
 }
