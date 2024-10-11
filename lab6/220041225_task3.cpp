#include<bits/stdc++.h>
using namespace std;

class Celcius{
  private:
  double cel_temp;
  public:
  Celcius():cel_temp(0.0){}
   Celcius(double a):cel_temp(a){}
  void assign(float a){
      cel_temp=a;
  }
  void display(){
      cout<<"The temperature is "<<cel_temp<<" Celcius.\n";
  }
  operator class Kelvin();
  operator class Farenheit();
};

class Kelvin{
  private:
  double kel_temp;
  public:
  Kelvin():kel_temp(0.0){}
  Kelvin(float a):kel_temp(a){}
  void assign(float a){
      kel_temp=a;
  }
  void display(){
      cout<<"The temperature is "<<kel_temp<<" kelvin.\n";
  }
  operator class Celcius();
  operator class Farenheit();
};

class Farenheit{
  private:
  double Farenheit_temp;
  public:
  Farenheit():Farenheit_temp(0.0){}
  Farenheit(float a):Farenheit_temp(a){}
  void assign(float a){
      Farenheit_temp=a;
  }
  void display(){
      cout<<"The temperature is "<<Farenheit_temp<<" Farenheit.\n";
  }
  operator class Kelvin();
  operator class Celcius();
};

Celcius::operator Kelvin(){
    double temp=(cel_temp+273);
    return Kelvin(temp);
}

Celcius::operator Farenheit(){
    double temp=((cel_temp*9)/5)+32;
    return Farenheit(temp);
}

Kelvin::operator Celcius(){
    double temp=kel_temp-273;
    return Celcius(temp);
}

Kelvin::operator Farenheit(){
    double temp=((kel_temp-273)*(9/5))+32;
    return Farenheit(temp);
}

Farenheit::operator Celcius(){
    double temp=((Farenheit_temp-32)/9)*5;
    return Celcius(temp);
}
Farenheit::operator Kelvin(){
    double temp=(((Farenheit_temp-32)/9)*5)+273;
    return Kelvin(temp);
}

int main(){
    Celcius c1;
    c1.assign(54);
    c1.display();
    Farenheit converted=c1;
    converted.display();
    
    
    
    return 0;
}
