#include <iostream>
#include <string>
#include <cmath> 
using namespace std;

class Employee {
private:
    string EmpName;       
    int ID;             
    float BaseSalary;   
    int JoiningYear;      

  
    int calculateYearsOfService(int currentYear) {
        return currentYear - JoiningYear;
    }

 
    float calculateTotalSalary(int currentYear) {
        int yearsOfService = calculateYearsOfService(currentYear);
        
        
        float updatedBaseSalary = BaseSalary * pow(1.03, yearsOfService);
        
      
        float transportAllowance = 0.1 * updatedBaseSalary;  
        float housingAllowance = 0.3 * updatedBaseSalary;    
        float miscellaneousAllowance = 0.1 * updatedBaseSalary; 
        
      
        return updatedBaseSalary + transportAllowance + housingAllowance + miscellaneousAllowance;
    }

 
    float calculateBonus(int currentYear) {
        float totalSalary = calculateTotalSalary(currentYear);
        string status = getStatus(currentYear);
        float bonusPercentage = 0.0;

        if (status == "Low") {
            bonusPercentage = 0.05;
        } else if (status == "Moderate") {
            bonusPercentage = 0.10;
        } else if (status == "High") {
            bonusPercentage = 0.15;
        }

        return totalSalary * bonusPercentage;
    }

 
    string getStatus(int currentYear) {
        int age = currentYear - JoiningYear;
        float totalSalary = calculateTotalSalary(currentYear);

        if (age <= 25 && totalSalary <= 20000) {
            return "Low";
        } else if (age <= 25 && totalSalary > 20000) {
            return "Moderate";
        } else if (age > 25 && age <= 30 && totalSalary <= 21000) {
            return "Low";
        } else if (age > 25 && age <= 30 && totalSalary > 21000 && totalSalary <= 60000) {
            return "Moderate";
        } else if (age > 25 && totalSalary > 60000) {
            return "High";
        }
        return "Unknown"; 
    }

public:

    void FeedInfo() {
        cout << "Enter Employee Name: ";
        getline(cin, EmpName);
        cout << "Enter Employee ID: ";
        cin >> ID;
        cout << "Enter Base Salary: ";
        cin >> BaseSalary;
        cout << "Enter Joining Year: ";
        cin >> JoiningYear;
        cin.ignore();  
    }

   
    void ShowInfo(int currentYear) {
        cout << "Employee Name: " << EmpName << endl;
        cout << "Employee ID: " << ID << endl;
        cout << "Base Salary: " << BaseSalary << endl;
        cout << "Joining Year: " << JoiningYear << endl;
        cout << "Total Salary: " << calculateTotalSalary(currentYear) << endl;
        cout << "Bonus: " << calculateBonus(currentYear) << endl;
        cout << "Status: " << getStatus(currentYear) << endl;
    }
};

int main() {
    Employee emp;
    emp.FeedInfo();

  
    int currentYear;
    cout << "Enter the current year: ";
    cin >> currentYear;

    emp.ShowInfo(currentYear);

    return 0;
}
