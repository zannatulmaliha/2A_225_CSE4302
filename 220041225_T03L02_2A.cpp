#include<bits/stdc++.h>
using namespace std;

struct fraction{
    int numerator,denominator;
};

int main(){
    fraction f1,f2,f3;
    cout<<"Enter the numerator and denominator for first fraction: ";
    int a,b;
    cin>>a>>b;
    f1.numerator=a;
    f1.denominator=b;
     cout<<"\nEnter the numerator and denominator for second fraction: ";
    int c,d;
    cin>>c>>d;
    f2.numerator=c;
    f2.denominator=d;
    
    f3.numerator=(f1.numerator*f2.denominator)+(f1.denominator*f2.numerator);
    f3.denominator=f1.denominator*f2.denominator;
    
    cout<<"the fraction is :"<<f3.numerator<<"/"<<f3.denominator;
    
    
    return 0;
}