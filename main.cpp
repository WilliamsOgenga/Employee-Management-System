#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base Class: Employee
class Employee {
protected:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string name, int employeeID, double salary)
        : name(name), employeeID(employeeID), salary(salary) {}

    virtual void displayDetails() const {
        cout << "Name: " << name << ", ID: " << employeeID << ", Salary: " << salary << endl;
    }

    int getEmployeeID() const {
        return employeeID;
    }
};

// Derived Class: Manager
class Manager : public Employee {
private:
    string department;
    double bonus;

public:
    Manager(string name, int employeeID, double salary, string department, double bonus)
        : Employee(name, employeeID, salary), department(department), bonus(bonus) {}

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Department: " << department << ", Bonus: " << bonus << endl;
    }
};

// Derived Class: Engineer
class Engineer : public Employee {
private:
    string specialization;
    string projectAssigned;

public:
    Engineer(string name, int employeeID, double salary, string specialization, string projectAssigned)
        : Employee(name, employeeID, salary), specialization(specialization), projectAssigned(projectAssigned) {}

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Specialization: " << specialization << ", Project: " << projectAssigned << endl;
    }
};

// Class: EmployeeManagementSystem
class EmployeeManagementSystem {
private:
    vector<Employee*> employees;

public:
    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void displayAllEmployees() const {
        for (const auto& employee : employees) {
            employee->displayDetails();
        }
    }

    void searchEmployeeByID(int id) const {
        for (const auto& employee : employees) {
            if (employee->getEmployeeID() == id) {
                employee->displayDetails();
                return;
            }
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }
};

// Main Function
int main() {
    EmployeeManagementSystem system;

    Manager* manager = new Manager("John Doe", 101, 75000, "HR", 5000);
    Engineer* engineer = new Engineer("Jane Smith", 102, 60000, "Software Development", "Project X");

    system.addEmployee(manager);
    system.addEmployee(engineer);

    cout << "All Employees:" << endl;
    system.displayAllEmployees();

    cout << "\nSearching for Employee ID 102:" << endl;
    system.searchEmployeeByID(102);

    delete manager;
    delete engineer;

    return 0;
}
