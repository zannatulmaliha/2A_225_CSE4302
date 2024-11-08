#include<bits/stdc++.h>
using namespace std;

class Person{
  protected:
  string name;
  public:
  Person(string n):name(n){}
  virtual void display(){
      cout<<name<<" ";
  }
};

class Employee:public Person{
    private:
    int employeeId;
    protected:
    float salary;

    public:
    Employee(const string& name,int employeeId,float salary):Person(name),employeeId(employeeId),salary(salary){}

    void display(){
        cout<<name<<" "<<employeeId<<" "<<salary<<" ";
    }

};

class Intern:public Employee{
    private:
    string schoolName;
    public:
    Intern(const string& name,int employeeId,float salary,string schoolName):Employee(name,employeeId,salary),schoolName(schoolName) {}
    void display(){
        Employee::display();
         cout<<schoolName<<" ";
    }
};

class Manager:protected Employee{
    private:
    string department;
    public:
    Manager(const string& name,int employeeId,float salary,string department):Employee(name,employeeId,salary),department(department){}
       void display(){
           Employee::display();
         cout<<department<<" ";
    }
};

class Director:public Manager{
   private:
   float bonus;
   public:
   Director(const string& name,int employeeId,float salary,string department,float bonus):Manager(name,employeeId,salary,department),bonus(bonus){}

    void display(){
       Manager::display();
       cout<<bonus<<"\n";
   }
};

int main(){
    Person p1("Maliha");
    cout<<"Person: ";
    p1.display();
    cout<<"\n";
    Employee e1("bob",223,100.32);
     cout<<"Employee: ";
    e1.display();
     cout<<"\n";

    Intern i1("steve",225,3943.23,"IUT");
    cout<<"Intern: ";
    i1.display();
     cout<<"\n";

     Manager m1("david",555,45.2,"CSE");
     cout<<"Manager: ";
    m1.display();
     cout<<"\n";

    Director d1("oggy",785,525.4,"CSE",5465);
     cout<<"Director: ";
    d1.display();
     cout<<"\n";

    return 0;
}
