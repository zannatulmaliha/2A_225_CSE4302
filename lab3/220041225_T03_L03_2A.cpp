#include<bits/stdc++.h>
using namespace std;

class Bank{
  private:
  string customer_name;
  string account_number;
  string account_type;
  int balance_money;
  
  public:
  Bank():balance_money(0){}
  
  void customerDetails(string acc_name,string acc_num){
      customer_name=acc_name;
      account_number=acc_num;
  }
   void accountType(string s){
       account_type=s;
   }
   int balance(){
       return balance_money;
   }
   void deposit(int m){
    balance_money+=m;
    cout<<balance_money<<"\n";
   }
   void withdraw(int k){
       if(balance_money>=k){
           balance_money-=k;
           cout<<balance_money<<"\n";
       }
       else
       cout<<"Doesn't have enough money\n";
   }
   
   void display(){
       cout<<"Customer's name: "<<customer_name<<"\n";
        cout<<"Customer's account_NO: "<<account_number<<"\n";
        cout<<"Customer's account type: "<<account_type<<"\n";
         cout<<"Customer's balance: "<<balance_money<<"\n";
   }
   
};

int main(){
    Bank bank;
    bank.customerDetails("Maliha","12132555");
    bank.accountType("current");
    bank.deposit(5000000);
     bank.withdraw(2500000);
    bank.display();
    return 0;
}
