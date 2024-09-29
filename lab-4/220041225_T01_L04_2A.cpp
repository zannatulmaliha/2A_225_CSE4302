#include<bits/stdc++.h>
using namespace std;

class Product{
   private:
   string name;
   string unique_id;
   double price;
   int quantity;
   const int max_amount;
    
    static int inventory;
    
    public:
    Product(string namee,string id,double pri,int initial,int maxx):name(namee),unique_id(id),price(pri),quantity(initial),max_amount(maxx){
        inventory++;
    }
    
    void addToInventory(int addedQuantity){
        quantity+=addedQuantity;
        inventory+=displayInventoryValue();
    }
    bool isAvailable() const{
        return quantity>0;
    }
    
    void purchase(int purchasedQuantity){
        if(isAvailable()){
            quantity-=purchasedQuantity;
            quantity=max(0,quantity);
             inventory -= displayInventoryValue();
        }
    }
    
    void updatePrice(int discountPercent){
        price=price*(1-(discountPercent/100));
    }
    
    double displayInventoryValue(){
        return (price*quantity);
    }
    void displayDetails(){
        cout<<"Name: "<<name<<"\n";
        cout<<"Unique id: "<<unique_id<<"\n";
         cout<<"price: "<<price<<"\n";
          cout<<"quantity: "<<quantity<<"\n"; 
          if(isAvailable())
          cout<<"Available\n";
          else
          cout<<"Unavailable\n";
    }
    static int displayTotalInventoryValue(){
       return inventory; 
    }
};
int Product::inventory=0;
int main(){
    Product p("pizza","#0123",420.5,1,5);
    p.addToInventory(1);
    p.updatePrice(5);
    p.displayInventoryValue();  
    p.displayDetails();
    
   Product q("burger","#0553d",500.45,2,6);
   Product w("sandwich","#0d3",477.1,4,7);
    
    cout<<q.displayTotalInventoryValue();
    
    
    return 0;
}
