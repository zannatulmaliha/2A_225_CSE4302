#include<bits/stdc++.h>
using namespace std;

class RationalNumber{
  private:
  int numerator;
  int denominator;
  
  public:
  RationalNumber():numerator(0),denominator(1){}
  
  void assign(int num,int den){
      if(den==0){
          cout<<"You can not assign 0 as denominator.\n";
          return;
      }
      numerator=num;
      denominator=den;
  }
  
  double convert(){
      return static_cast<double>(numerator)/denominator;
  }
  
  void invert(){
      if(numerator==0){
          cout<<"You can not assign 0 as denominator.\n";
          return;
      }
      swap(numerator,denominator);
  }
  void print(){
      cout<<numerator<<"/"<<denominator<<"\n";
  }
};


int main(){
    RationalNumber num;
    
    num.assign(5,2);
    num.print();
    
    cout<<num.convert()<<"\n";
    
    num.invert();
    num.print();
    cout<<num.convert()<<"\n";
    num.print();
    
    
    return 0;
}
