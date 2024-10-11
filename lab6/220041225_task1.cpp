#include<bits/stdc++.h>
using namespace std;

class Car{
    private:
    string make;
    string model;
    double fuelCapacity;
    double fuelLevel;
    
    public:
    Car(string a,string b,double c,double d):make(a),model(b),fuelCapacity(c),fuelLevel(d){}
    
    Car():fuelLevel(0.0){} 
    
    Car operator + ()const{
        double d=fuelLevel+1;
        if(d>fuelCapacity){
            cout<<"Limit exceeded\n";
           d=fuelLevel;
        }
        return Car(make,model,fuelCapacity,d);
    }
    
       Car operator - ()const{
        double d=fuelLevel-1;
        if(d<0){
            cout<<"cannot decrement\n";
            d=0;
        }
        return Car(make,model,fuelCapacity,d);
    }
    
    Car operator += (double a)const{
         double d=fuelLevel+a;
        if(d>fuelCapacity){
            cout<<"Limit exceeded\n";
           d=fuelLevel;
        }
        return Car(make,model,fuelCapacity,d);
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
    
   // friend void operator<< (Car);
    //friend void operator >>(Car);
    
};
//   void operator <<(){
//         cout<<make<<"\n";
//         cout<<model<<"\n";
//         cout<<fuelCapacity<<"\n";
//         cout<<fuelLevel<<"\n";
//     }
//     void operator >>(Car c1)const{
          
//     }
    
int main(){
    Car c1;
    c1("dfd","dfe",34.2,1.0);
    return 0;
}