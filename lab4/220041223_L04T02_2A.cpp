#include <iostream>
using namespace std;

class BankAccount {
private:
    string customer_name;
    string acc_number;
    string acc_type;
    float current_balance;
    const float min_balance;
    float totaltax; 
    static int totalacc_created;
    static int totalacc_present;
    static float total_tax_collected;

public:
    BankAccount(string name, string n, string type, float min_bal = 500.0):customer_name(name), acc_number(n), acc_type(type), min_balance(min_bal){
        current_balance = min_balance;
        totaltax = 0.0;
        totalacc_created++;
        totalacc_present++;
    }

    void showBalance(){
        cout << "Your balance is: " << current_balance << endl;
    }

    void deposit(float deposit) {
        current_balance += deposit;
        cout << "Your current balance is: " << current_balance << endl;
    }

    void withdrawal(float amount) {
        if (current_balance >= amount) {
            if (current_balance - amount >= min_balance) {
                current_balance -= amount;
                cout << "Your current balance is: " << current_balance << endl;
            } else {
                cout << "Cannot withdraw as it will go below the minimum balance." << endl;
            }
        } else {
            cout << "You don't have sufficient balance." << endl;
        }
    }

    void giveInterest(float interest = 3.0) {
        float int_amount = (interest / 100.0) * current_balance;
        float tax_amount = (10.0 / 100.0) * int_amount; 
        current_balance += (int_amount - tax_amount);
        totaltax += tax_amount;
        total_tax_collected += tax_amount;
        cout << "Interest credited, after deducting source tax." << endl;
    }

    ~BankAccount() {
        cout << "Account of " << customer_name << " with account no " << acc_number
             << " is destroyed with a balance BDT " << current_balance << endl;
        totalacc_present--;
    }

    static int getTotalAccCreated() {
        return totalacc_created;
    }

    static int getTotalAccPresent() {
        return totalacc_present;
    }

    static float getTotalTaxCollected() {
        return total_tax_collected;
    }
};


int BankAccount::totalacc_created = 0;
int BankAccount::totalacc_present = 0;
float BankAccount::total_tax_collected = 0.0;


void display_stat() {
    cout << "Total BankAccount objects created: " << BankAccount::getTotalAccCreated() << endl;
    cout << "Total BankAccount objects currently present: " << BankAccount::getTotalAccPresent() << endl;
    cout << "Total amount of source tax collected from all the bank accounts: " << BankAccount::getTotalTaxCollected() << " BDT" << endl;
}

int main() {
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


    display_stat();

    return 0;
}
