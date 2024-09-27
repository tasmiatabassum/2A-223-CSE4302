#include <iostream>
 using namespace std;

 class BankAccount{
    private:
        string customer_name;
        string acc_number;
        string acc_type;
        float current_balance;
        float min_balance;
        int interest;
        int tax;

        float totaltax;

        static int totalacc_created;
        static int totalacc_present;

    public:
        BankAccount(string name, string n, string type):customer_name(name), acc_number(n), acc_type(type){
            min_balance = 500.00;
            current_balance = min_balance;
            interest = 3;
            tax = 10;
            totaltax =0;
            totalacc_created++;
        }
        //void customerDetails(string name, int number){
            //customer_name = name;
            //acc_number = number;
       //}
        void showBalance(){
            cout<<"Your balance is: "<<current_balance<<endl;
        }
        void deposit(float deposit){
            current_balance += deposit;
            cout<<"Your current balance is: "<<current_balance<<endl;
        }
        void withdrawal(float amount){
            if(current_balance>=amount){
                if(current_balance-amount>=min_balance){
                   current_balance -=amount;
                    cout<<"Your current balance is: "<<current_balance<<endl;
                }
            }
            else {
                    cout<<"You don't have sufficient balance"<<endl;

            }
            return;

        }
        void giveInterest(){
            float intamount = (interest/100.00)*current_balance;
            float taxamount = intamount -((tax/100.00)*intamount);
            current_balance += taxamount;

            totaltax += taxamount;

        }

        ~BankAccount(){
            cout<<"Account of "<<customer_name<<" with account no "<<acc_number<<" is destroyed with a balance BDT "<<current_balance<<endl;
            totalacc_present--;
        }

        int getstat1(){
            return totalacc_created;
        }
        int getstat2(){
            return totalacc_present;
        }
        float getstat3(){
            return totaltax;
        }

 };

 int BankAccount::totalacc_created=0;
 int BankAccount::totalacc_present=0;

void display_stat(BankAccount p){
     cout<<"Total BankAccount objects created: "<<p.getstat1()<<endl;
     cout<<"Total BankAccount objects current present: "<<p.getstat2()<<endl;

     cout<<"Total amount of source tax collected from all the bank accounts: "<<p.getstat3()<<endl;
 }

 int main(){
     BankAccount acc1("Tasmia", "0001", "Saving");
     acc1.showBalance();
     acc1.deposit(5000.344);
     acc1.withdrawal(100.45);
     acc1.showBalance();
     acc1.giveInterest();
     acc1.showBalance();

     BankAccount acc2("Maliha", "0002", "Saving");
     acc2.showBalance();
     acc2.deposit(3000.344);
     acc2.withdrawal(200.45);
     acc2.showBalance();
     acc2.giveInterest();
     acc2.showBalance();



    return 0;
 }
