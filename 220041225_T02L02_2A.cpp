#include<bits/stdc++.h>
using namespace std;

enum etype{laborer,secretary,manager,accountant,executive,researcher};
int main(){
     etype profession;
   
    char data;
    cout<<"Enter employee type: ";
    cin>>data;
    
    switch(data){
        case 'l' :
        {
            profession=laborer;
            break;
        }
         case 's' :
        {
            profession=secretary;
            break;
        }
         case 'm':
        {
            profession=manager;
            break;
        }
         case 'a':
        {
            profession=accountant;
            break;
        }
         case 'e':
        {
            profession=executive;
            break;
        }
        case 'r':
        {
            profession=researcher;
            break;
        }
    }
    
    switch(profession){
        case laborer:
        {
            cout<<"Employee type is laborer";
            break;
        }
         case secretary:
        {
            cout<<"Employee type is secretary";
            break;
        }
        case manager:
        {
            cout<<"Employee type is manager";
            break;
        }
         case accountant:
        {
            cout<<"Employee type is accountant";
            break;
        }
         case executive:
        {
            cout<<"Employee type is executive";
            break;
        }
        case researcher:
        {
            cout<<"Employee type is researcher";
            break;
        }
        default:{
        break;
        }
    }
    
    return 0;
}