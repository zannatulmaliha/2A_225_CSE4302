#include<bits/stdc++.h>
using namespace std;

class SellerActions{
  public:
    virtual void serveIceCream() = 0;
    virtual void promoteDeal() = 0;
    virtual void specialOffer() = 0;
    virtual void displayStats() = 0;
  
    virtual ~SellerActions() = default;
};

class BaseSeller : public SellerActions {
  protected:
    string name;
    int stock;
    int sales;
    bool specialOfferReady;
  
  public:
    BaseSeller(string n, int s) : name(n), stock(s), sales(0), specialOfferReady(false) {}

    void serveIceCream() override {
        if(stock > 0) {
            stock -= 1;
            int salesIncrease = rand() % 23 + 8;
            sales += salesIncrease;

            if(sales % 3 == 0) {
                specialOfferReady = true;
                cout << name << " is ready to use a special offer!" << endl;
            }
        } else {
            cout << name << " is out of stock!" << endl;
        }
    }

    void promoteDeal() override {
        cout << name << " promotes a special deal! Sales will increase for the next 2 turns." << endl;
    }
  
    virtual void specialOffer() override = 0;

    void displayStats() override {
        cout << name << " Stats - Stock: " << stock << ", Sales: " << sales
             << ", Special Offer Ready: " << (specialOfferReady ? "Yes" : "No") << endl;
    }

    bool isSpecialOfferReady() const {
        return specialOfferReady;
    }
    
    void resetSpecialOffer() {
        specialOfferReady = false;
    }

    int getSales() const {
        return sales;
    }

    int getStock() const {
        return stock;
    }

    void addStock(int amount) {
        stock += amount;
    }
};

class ConeMaster : public BaseSeller {
  public:
    ConeMaster() : BaseSeller("Cone Master", 20) {}

    void specialOffer() override {
        if(specialOfferReady) {
            cout << name << " serves three cones in one turn!" << endl;
            for(int i = 0; i < 3; i++) {
                serveIceCream();
            }
            resetSpecialOffer();
        } else {
            cout << name << "'s special offer is not ready yet!" << endl;
        }
    }

    void ConeStackChallenge(int scoopsStacked) {
        int successRate = 100 - (scoopsStacked * 10);
        int random = rand() % 100;
        if(random < successRate) {
            cout << name << " successfully served a " << scoopsStacked << "-scoop cone!" << endl;
            serveIceCream();
        } else {
            cout << name << "'s cone toppled! Stock wasted." << endl;
            stock--;
        }
    }
};

class SundaeWizard : public BaseSeller {
  public:
    SundaeWizard() : BaseSeller("Sundae Wizard", 15) {}

    void specialOffer() override {
        if(specialOfferReady) {
            cout << name << " doubles the sales for one turn!" << endl;
            int doubledSales = sales * 2;
            cout << name << " earned " << doubledSales << " in sales!" << endl;
            resetSpecialOffer();
        } else {
            cout << name << "'s special offer is not ready yet!" << endl;
        }
    }

    void LayeredSundaeBonus(int layers) {
        int bonusSales = layers * (rand() % 23 + 8);
        sales += bonusSales;
        stock--;
        cout << name << " served a layered sundae! Bonus Sales: " << bonusSales << ", Total Sales: " << sales << endl;
    }
};

class IceCreamTruckDriver : public BaseSeller {
  public:
    IceCreamTruckDriver() : BaseSeller("Ice Cream Truck Driver", 30) {}

    void specialOffer() override {
        if(specialOfferReady) {
            cout << name << " restocks 10 units of ice cream!" << endl;
            addStock(10);
            resetSpecialOffer();
        } else {
            cout << name << "'s special offer is not ready yet!" << endl;
        }
    }
};

class CustomerRush {
  private:
    int patience;
    int salesGoal;

  public:
    CustomerRush() : patience(200), salesGoal(300) {}

    void decreasePatience() {
        int decrease = rand() % 31 + 20; 
        patience -= decrease;
        if (patience < 0) patience = 0;
        cout << "Customer patience decreased by " << decrease << ". Current patience: " << patience << endl;
    }

    bool isSatisfied(int totalSales) const {
        return totalSales >= salesGoal;
    }

    bool isOutOfPatience() const {
        return patience <= 0;
    }
};

class SimulationEngine {
  private:
    ConeMaster coneMaster;
    SundaeWizard sundaeWizard;
    IceCreamTruckDriver truckDriver;
    CustomerRush customerRush;

  public:
    SimulationEngine() {}

    void startGame() {
        cout << "Game begins! Sellers vs. Customer Rush" << endl;
        int totalSales = 0;

        for (int turn = 1; turn <= 10; ++turn) {
            cout << "Turn " << turn << ":" << endl;

            coneMaster.serveIceCream();
            sundaeWizard.serveIceCream();
            truckDriver.serveIceCream();

            totalSales = coneMaster.getSales() + sundaeWizard.getSales() + truckDriver.getSales();
            cout << "Collective totalSales: " << totalSales << endl;

            if (customerRush.isSatisfied(totalSales)) {
                cout << "Customer Rush satisfied! Sellers win!" << endl;
                return;
            }

            customerRush.decreasePatience();

            if (customerRush.isOutOfPatience()) {
                cout << "Customer patience ran out! Sellers lose!" << endl;
                return;
            }
        }

        cout << "Sellers couldn't meet the sales goal in time. Sellers lose!" << endl;
    }
};

int main() {
    srand(time(0));  
    SimulationEngine game;
    game.startGame();
    return 0;
}
