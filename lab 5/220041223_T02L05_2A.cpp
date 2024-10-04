#include <iostream>
#include<string>
#include <cmath>
#include <ctime>
#include <cstdlib> 
using namespace std;

class Employee{
    private:
        string name;
        string dob;
        float basesalary;
        int joinyear;
        int age;
    void setName(const string& gname){
        if(gname.length()>2) name = gname;
        else name = "John Doe";
    }
    
    void setDOB(const string& inpdob){
        int year = stoi(inpdob.substr(6,4));
        age = 2024-year;
        if(age>=18) dob = inpdob;
        else dob= "01-01-2002";
        age =22;
    }
    void setBaseSalary(float salary){
        if(salary>=10000 && salary<=100000) basesalary = salary;
        else basesalary = 10000;
    }
    
    void setJoinYear(int year){
        joinyear = year;
    }
    
    public:
        Employee(): name("John Doe"), dob("01-01-2002"), basesalary(10000), joinyear(2024), age(22){}
        
        void setInfo(const string& gname, const string& inpdob, float salary, int year){
            setName(gname);
            setDOB(inpdob);
            setBaseSalary(salary);
            setJoinYear(year);
        }
        
        float calculateTotalSalary(){
            int service =2024 - joinyear;
            float updatedBaseSalary = basesalary;
            for(int i =0; i<service;i++){
                updatedBaseSalary += updatedBaseSalary*0.03;
            }
            float tallowance = updatedBaseSalary*0.10;
            float hallowance = updatedBaseSalary*0.30;
            float mallowance = updatedBaseSalary*0.10;
        
            float totalsalary = updatedBaseSalary+tallowance+hallowance+mallowance;
            return totalsalary;
        }
        
        
        string getStatus(const string& status) const{
            float total = calculateTotalSalary();
            if(age<=25){
                if(total<=20000) return "Low";
                else return "Moderate";
            }
            else{
                if(total<=21000) return "Low";
                else if(total>21000 && total<=60000) return "Moderate";
                else return "High"; 
            }
            
        }
        float calculateBonus(const string& status){
             float updatedBaseSalary = basesalary * pow(1.03, 2024 - joinyear);
            if(status == "Low"){
                return updatedBaseSalary*0.05;
            }
            else if(status == "Moderate"){
                return updatedBaseSalary*0.10;
            }
            else return updatedBaseSalary*0.15;
        }
        
        void getInfo() const{
            cout<<"Name: "<<name<<"\nDOB: "<<dob<<"\nBase Salary: "<<basesalary<<"\nJoining Year: "<<joinyear<<"\nTotal Salary: "<<calculateTotalSalary()<<"\nStatus: "<<getStatus()<<endl;
        }
        //const Employee* compareTotalSalary(Employee& e) const{
            //if(calculateTotalSalary()> e.calculateTotalSalary()){
                //return this;
            //}
            //else{
                //return &e;
            //}
       // }
};
        void swap(Employee &a, Employee &b){
            Employee temp =a;
            a=b;
            b=temp;
        }
        void ascorder(Employee arr[], int size){
            for(int i=0; i<size-1; i++){
                for(int j =0;j<size-i-1;j++){
                    if(arr[j].calculateTotalSalary()>arr[j+1].calculateTotalSalary()){
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
        }
        
       string generateRandomString(int length) {
           string randomString;
           const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
           int alphabetSize = sizeof(alphabet) - 1;
           srand(static_cast<unsigned int>(time(0)));
           for (int i = 0; i < length; ++i) {
               randomString += alphabet[rand() % alphabetSize];
               
           }
           return randomString;
           
       }
       int randomInRange(int min, int max) {
           if (min > max) {
               int temp = min;
               min = max;
               max = temp;
               
           }
           return rand() % (max - min + 1) + min;
           
       }
       void generateInformaiotnRandom(Employee& e) {
        string randomName = generateRandomString(6);
        string randomDOB = to_string(randomInRange(1, 28)) + "-" + to_string(randomInRange(1, 12)) + "-" + to_string(randomInRange(1960, 2006));
        float randomSalary = randomInRange(10000, 100000);
        int randomYear = randomInRange(2000, 2024);
        e.setInfo(randomName, randomDOB, randomSalary, randomYear);
    }

    void ShowAllBasedOnTotalSalary(Employee ar[], int size) {
        sortEmployeesBySalary(ar, size);
        for (int i = 0; i < size;i++) {
            ar[i].getInfo();
        }
    }
 
int main() {
    const int n= 100;
    Employee employees[n];

    for(int i = 0; i <n; ++i){
        generateInformationRandom(employees[i]);
    }
    ShowAllBasedOnTotalSalary(employees,n);

    return 0;
}
