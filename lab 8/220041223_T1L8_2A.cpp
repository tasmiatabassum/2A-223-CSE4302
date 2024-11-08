#include <iostream>
using namespace std;

class Person{
    protected:
    string name;

    public:
    Person(string name): name(name) {}

    virtual void display() const{
        cout<<"Name: "<<name<<endl;
    }

};

class Employee: public Person{
    private:
    int employeeID;

    protected:
    float salary;

    public:
    Employee(const string& name, int employeeID, float salary): Person(name), employeeID(employeeID), salary(salary) {}

    void display() const {
        Person::display();
        cout<<"Employee ID: "<<employeeID<<endl;
        cout<<"Salary: "<<salary<<endl;
    }


};

class Intern: public Employee{
    private:
    string schoolName;

    public:
    Intern(const string& name, int employeeID, float salary, const string& schoolName): Employee(name, employeeID, salary), schoolName(schoolName) {}

    void display() const {
        Employee::display();
        cout<<"School Name: "<<schoolName<<endl;
    }
};
class Manager: protected Employee{
    private:
    string department;

    public:
    Manager(const string& name, int employeeID, float salary, const string& department): Employee(name, employeeID, salary), department(department) {}

    void display() const {
        Employee::display();
        cout << "Department: " << department << endl;
    }
};

class Director: public Manager{
    private:
    float bonus;

    public:
    Director(const string& name, int employeeID, float salary, const string& department, float bonus) : Manager(name, employeeID, salary, department) , bonus(bonus) {}

    void display() const {
        Manager::display();
        cout << "Bonus: " <<bonus<< endl;
    }

};

int main() {
    Person p("Tasmia");
    cout<<"Person:"<<endl;
    p.display();
    cout<<endl;

    Employee e1("Nashat", 211, 500000);
    cout<<"Employee:"<<endl;
    e1.display();
    cout<<endl;

    Intern i1("Mrittika", 227, 15000, "IUT");
    cout<<"Intern:"<<endl;
    i1.display();
    cout<<endl;

    Manager m1("Maliha", 225, 70000, "IT");
    cout<<"Manager:"<<endl;
    m1.display();
    cout<<endl;

    Director d1("Humaira", 228, 100000, "IT", 5678.678);
    cout<<"Director:"<<endl;
    d1.display();
    cout<<endl;

    return 0;
}
