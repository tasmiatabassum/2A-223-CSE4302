#include <iostream>
using namespace std;

class Employee{
private:
    string EmpName;
    int ID;
    float BaseSalary;
    int JoiningYear;
    
    float calculateTotalSalary(){
        int currentYear = 2024;
        int service = currentYear - JoiningYear;
        
        float updatedBaseSalary = BaseSalary;
        for(int i =0; i<service;i++){
            updatedBaseSalary += updatedBaseSalary*0.03;
        }
        
        float tallowance = updatedBaseSalary*0.10;
        float hallowance = updatedBaseSalary*0.30;
        float mallowance = updatedBaseSalary*0.10;
        
        float totalsalary = updatedBaseSalary+tallowance+hallowance+mallowance;
        
        return totalsalary;
    }
    float calculateBonus(string status){
        float updatedBaseSalary = BaseSalary;
        int currentYear = 2024;
        int service = currentYear - JoiningYear;
        
        for(int i=0;i<service;i++){
            updatedBaseSalary += updatedBaseSalary*0.03;
        }
        
        if(status == "Low"){
            return updatedBaseSalary*0.05;
        }
        else if(status == "Moderate"){
            return updatedBaseSalary*0.10;
        }
        else return updatedBaseSalary*0.15;
    }
    string getStatus(int age, float total){
        if(age<=25){
            if(total<=20000) return "Low";
            else return "Moderate";
        }
        else{
            if(total<=21000) return "Low";
            else if (total> 21000 && total <= 6000) return "Moderate";
            else return "High";
        }
    }

public:
    Employee(string name, int id, float salary, int year){
        EmpName = name;
        ID = id;
        BaseSalary = salary;
        JoiningYear = year;
    }
    void ShowInfo(int age){
        float total = calculateTotalSalary();
        string status = getStatus(age,total);
        float bonus = calculateBonus(status);

        cout << "Employee Name: " << EmpName << endl;
        cout << "Employee ID: " << ID << endl;
        cout << "Base Salary: " << BaseSalary << endl;
        cout << "Joining Year: " << JoiningYear << endl;
        cout << "Total Salary: " << total<< endl;
        cout << "Employee Status: " << status << endl;
        cout << "Bonus: " << bonus << endl;
    }
};


int main() {
    
    Employee emp("Tasmia", 1001, 270045.00, 2019);
    
    emp.ShowInfo(21);
    

    return 0;
}
