#include<bits/stdc++.h>
using namespace std;

int main(){
    int w,x,y,z;
    cout<<"Enter numerator and denominator for first fraction: ";
    cin>>w>>x;
    cout<<"\nEnter numerator and denominator for second fraction: ";
    cin>>y>>z;
    
    cout<<((w*z)+(x*y))<<"/"<<(x*z);
    return 0;
}