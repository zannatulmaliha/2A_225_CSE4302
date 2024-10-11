#include<bits/stdc++.h>
using namespace std;

class Car{
    private:
    string make;
    string model;
    double fuelCapacity;
    double fuelLevel;
    
    public:
        
    Car():fuelLevel(0.0){} 
    Car(string a,string b,double c,double d):make(a),model(b),fuelCapacity(c),fuelLevel(d){}
    
    Car operator + (double a)const{
        double d=fuelLevel+a;
        if(d>fuelCapacity){
            cout<<"Limit exceeded\n";
           d=fuelLevel;
        }
        return *this;
    }
    
       Car operator - (double a)const{
        double d=fuelLevel-a;
        if(d<0){
            cout<<"cannot decrement\n";
            d=fuelLevel;
        }
        return Car(make,model,fuelCapacity,d);
    }
    
    Car operator += (double a)const{
         double d=fuelLevel+a;
        if(d>fuelCapacity){
            cout<<"Limit exceeded\n";
           d=fuelLevel;
        }
        return *this;
    }
    
    bool operator ==(Car car1)const{
        return (car1.make==make && car1.model==model && car1.fuelCapacity==fuelCapacity && car1.fuelLevel==fuelLevel);
    }
    
    bool operator <(Car car1)const{
        return fuelLevel<car1.fuelLevel;
    }
      bool operator >(Car car1)const{
        return fuelLevel>car1.fuelLevel;
    }
    
  
    friend ostream& operator<<(ostream& os, const Car& car) {
    os << "Make: " << car.make << "\n"
       << "Model: " << car.model << "\n"
       << "Fuel Capacity: " << car.fuelCapacity << " liters\n"
       << "Fuel Level: " << car.fuelLevel << " liters\n";
    return os;
}

friend istream& operator>>(istream& is, Car& car) {
    cout << "Enter make: ";
    is >> car.make;
    cout << "Enter model: ";
    is >> car.model;
    cout << "Enter fuel capacity: ";
    is >> car.fuelCapacity;
    cout << "Enter fuel level: ";
    is >> car.fuelLevel;
    return is;
}

    
};

    
int main(){
  Car c1("Toyota", "Corolla", 50.0, 10.0);
    Car c2("Honda", "Civic", 55.0, 20.0);

    cout << "Initial Cars:\n";
    cout << c1;
    cout << c2;

    c1 += 30.0; 
    cout << "\nAfter adding fuel to c1:\n";
    cout << c1;

    c1 - 15.0; 
    cout << "\nAfter consuming fuel from c1:\n";
    cout << c1;

    if (c1 == c2) {
        cout << "Cars are identical.\n";
    } else {
        cout << "Cars are not identical.\n";
    }

    if (c1 < c2) {
        cout << "c1 has less fuel than c2.\n";
    } else {
        cout << "c1 has more fuel than c2.\n";
    }

   
    Car c3;
    cin >> c3; 
    cout << "\nNew Car Details:\n";
    cout << c3; 

    return 0;
}
