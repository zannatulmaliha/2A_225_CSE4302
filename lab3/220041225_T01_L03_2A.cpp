#include<bits/stdc++.h>
using namespace std;

class Temperature{
  private:
  int temperature;
  int increment_step;
  
  public:
  Temperature():temperature(0),increment_step(1){}
  
  void setIncrementStep(int s){
      increment_step=s;
  }
  
  int getTemperature(){
      return temperature;
  }
  
  void increment(){
      temperature+=increment_step;
  }
  void resetTemperature(){
      temperature=0;
  }
  
};

int main(){
    Temperature temp;
    temp.setIncrementStep(5);
    
    temp.increment();
    cout<<temp.getTemperature()<<"\n";
    
    temp.resetTemperature();
    cout<<temp.getTemperature();
    return 0;
}
