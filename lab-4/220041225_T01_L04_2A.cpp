#include<bits/stdc++.h>
using namespace std;

class Product{
  private:
  string name;
  int quantity;
  float price;
  string id;
  int maxquantity;
  
  static int total_inventory;
  public:
 
  Product(string product_name,string product_id,int product_quantity,float product_price,int maxxquantity):name(product_name),quantity(product_quantity),price(product_price),id(product_id),maxquantity(maxxquantity){
      
      total_inventory++;
  }
  
  
  void addToInventory(int addedQuantity){
   if((quantity+addedQuantity)<=maxquantity){
       quantity+=addedQuantity;
   }
   else{
       quantity=maxquantity;
   }
  }
  
  bool isAvailable(int quantity){
      return quantity>0;
  }
  
  void purchase(int purchasedQuantity){
      if(isAvailable(quantity)){
      quantity-=purchasedQuantity;
      quantity=max(quantity,0);
      }
  }
  void updatePrice(int discountPercent){
      price=price*0.95;
  }
  
  float displayInventoryValue(){
      return (price*quantity);
  }
  void displayDetails(){
      cout<<"Product name: "<<name<<"\n";
      cout<<"Product id: "<<id<<"\n";
      cout<<"Product price: "<<price<<"\n";
      cout<<"Product quantity: "<<quantity<<"\n";
      if(isAvailable(quantity))
      cout<<"The product is available\n";
      else
      cout<<"Not available\n";
  }
   static int displayTotalInventoryValue(){
      return total_inventory;
  }
  
};
int Product::total_inventory=0;
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
