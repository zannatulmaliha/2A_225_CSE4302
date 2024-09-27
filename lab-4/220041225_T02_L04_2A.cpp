#include<bits/stdc++.h>
using namespace std;

class BankAccount{
  private:
  string accountnumber;
  string acc_holder_name;
  string acc_type;
  float current_balance;
  float minimum;
  float interest;
  
  static int totalaccount_created;
  static int totalaccount_present;
  
  public:
  BankAccount():minimum(5){
      totalaccount_created++;
      totalaccount_present++;
    }
  BankAccount(string acc_num,string holder_name,string type,float balance):accountnumber(acc_num),acc_holder_name(holder_name),acc_type(type),minimum(0),current_balance(5){
      
       totalaccount_created++;
      totalaccount_present++;
  }
  
  void showBalance(){
      cout<<"Balance is: "<<current_balance<<"\n";
  }
  void deposit(float x){
      current_balance+=x;
  }
  void withdraw(float x){
      if((current_balance-x)<minimum){
          cout<<"Can't withdraw\n";
      }
      else
      current_balance-=x;
  }
  void giveInterst(){
      float inte=0.03*current_balance;
      inte=0.9*inte;
      current_balance+=inte;
  }
  ~BankAccount(){
      cout<<"Account of " <<acc_holder_name<<" with acc. no: "<<accountnumber<<" is destroyed with balance "<<current_balance<<"\n";
       totalaccount_present--;
  }
  int get(){
      return totalaccount_present;
  }
   int gettt(){
      return totalaccount_created;
  }
};

int  BankAccount::totalaccount_created=0;
int   BankAccount::totalaccount_present=0;

void display_stat(BankAccount p){
     cout<<"total account present is "<<p.get()<<"\n";
     cout<<"total account created is" <<p.gettt()<<"\n";
}

int main(){
    BankAccount B("544dsdsf","maliha","current",521.54);
    BankAccount c,d,e;
    display_stat(B);
    
    return 0;
}
