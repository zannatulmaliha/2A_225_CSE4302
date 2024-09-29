#include<bits/stdc++.h>
using namespace std;

class BankAccount{
  private:
  string accountnumber;
  string acc_holder_name;
  string acc_type;
  double current_balance;
  const double minimum;
  double interest;
  
  static int totalaccount_created;
  static int totalaccount_present;
  static double totaltax_collected;
  
  public:

  BankAccount(string acc_num,string holder_name,string type,double balance,double mini):accountnumber(acc_num),acc_holder_name(holder_name),acc_type(type),minimum(mini),current_balance(balance){
      if(current_balance<minimum){
          current_balance=minimum;
          cout << "Initial balance too low. Reset to minimum balance: " << minimum << "\n";
      }
       totalaccount_created++;
      totalaccount_present++;
  }
  
   ~BankAccount(){
      cout<<"Account of " <<acc_holder_name<<" with acc. no: "<<accountnumber<<" is destroyed with balance "<<current_balance<<"\n";
       totalaccount_present--;
  }
  
  
  void showBalance()const{
      cout<<"Balance is: "<<current_balance<<"\n";
  }
  void deposit(double x){
      if(x>0)
      current_balance+=x;
      else
      cout<<"give a valid value\n";
  }
  void withdraw(double x){
      if((current_balance-x)<minimum){
          cout<<"Can't withdraw\n";
      }
      else
      current_balance-=x;
  }
  void giveInterest(double inter=3.0){
      double interest=(inter*current_balance)/100;
      double source=0.1*interest;
      interest-=source;
      current_balance+=interest;
      totaltax_collected+=source;
  }
     double getCurrentBalance() const {
        return current_balance;
    }
 
  static int total_acc(){
      return totalaccount_present;
  }
  static int total_cre(){
      return totalaccount_created;
  }
  static double total_tax(){
      return totaltax_collected;
  }
  
};

int  BankAccount::totalaccount_created=0;
int  BankAccount::totalaccount_present=0;
double BankAccount::totaltax_collected=0.0;

void display_stat(){
     cout<<"total account present is "<<BankAccount::total_acc()<<"\n";
     cout<<"total account created is " <<BankAccount::total_cre()<<"\n";
      cout<<"total source tax is " <<BankAccount::total_tax()<<"\n";
}

BankAccount Larger(const BankAccount A, const BankAccount B){
    return (A.getCurrentBalance()>B.getCurrentBalance()?A:B);
}

int main(){
     BankAccount B("544dsdsf", "Maliha", "current", 521.54, 15.2);
    BankAccount E("123", "Iha", "current", 1000.0, 7.2);
    BankAccount D("4554", "Rashid", "savings", 454.54,45.3);
    BankAccount C("578", "cat", "current", 475.3, 56.3);


    B.giveInterest();
    E.giveInterest();
    D.giveInterest(3);
    C.giveInterest(2);

   
    display_stat();

   
    BankAccount larger_acc = Larger(B, E);
    cout << "Account with larger balance is: " << larger_acc.getCurrentBalance() << "\n";

   
    
    return 0;
}
