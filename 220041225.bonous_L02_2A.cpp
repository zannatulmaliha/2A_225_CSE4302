#include<bits/stdc++.h>
using namespace std;

struct car{
  string brand;
  string model;
  int year;
  string fuel_type;
  float mileage;
};

void efficiency(int a){
    if(a>15)
    cout<<"\nThe car is fuel efficient";
    else
    cout<<"\nThe car is not fuel efficient";
}

float fuel_consumption(int mileage){
    return 100/mileage;
}

float fuel_cost_calc(int mileage,string s){
    if(s=="petrol"){
        return ((100/mileage)*.89);
    }
    else if(s=="diesel"){
        return ((100/mileage)*3.24);
    }
    else if(s=="hybrid"){
    return ((100/mileage)*2.45);
    }
}

int main(){
   car car1,car2,car3;
   cout<<"Enter info for car1: \n";
   cout<<"brand: ";
   cin>>car1.brand;
   cout<<"\nmodel: ";
   cin>>car1.model;
   cout<<"\nyear: ";
   cin>>car1.year;
    cout<<"\nfuel type: ";
   cin>>car1.fuel_type;
   cout<<"\nmilage: ";
   cin>>car1.mileage;
   
   
   efficiency(car1.mileage);
   float f_con=fuel_consumption(car1.mileage);
   float cost=fuel_cost_calc(car1.mileage,car1.fuel_type);
   cout<<"\nfuel consumption: "<<f_con;
    cout<<"\nfuel cost: $"<<cost;
   
    return 0;
}