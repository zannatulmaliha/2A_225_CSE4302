#include<bits/stdc++.h>
using namespace std;

#define pi 3.1416

class Shape{
   public:
   virtual void  whoAmI()const =0;

};

class  TwoDimensionalShape:public Shape{
    public:
    virtual float area()const =0;
    virtual float perimeter()const =0;
};

class ThreeDimensionalShape:public Shape{
   public:
   virtual float surfaceArea()const =0;
    virtual float volume()const =0;
};

class square:public TwoDimensionalShape{
    private:
    float x;
    public:
    square(float x):x(x){}
    void whoAmI()const{
        cout<<"Square:\n";
    }
    float area()const{
        return x*x;
    }
    float perimeter()const{
        return 4*x;
    }
};

class circle:public TwoDimensionalShape{
      private:
      float rad;
      public:
      circle(float rad):rad(rad){};
      void whoAmI()const{
        cout<<"Circle:\n";
    }
    float area()const{
        return pi*rad*rad;
    }
    float perimeter()const{
        return 2*pi*rad;
    }
};

class cube:public ThreeDimensionalShape{
       private:
       float side;
       public:
       cube(float side):side(side){}
       void whoAmI()const{
        cout<<"cube:\n";
       }
       float surfaceArea()const{
           return 6*side*side;
       }
       float volume()const{
           return side*side*side;
       }
};

class sphere:public ThreeDimensionalShape{
       private:
       float rad;
       public:
       sphere(float rad):rad(rad){}
       void whoAmI()const{
        cout<<"sphere:\n";
       }

       float surfaceArea()const{
        return 4*pi*rad*rad;
       }
       float volume()const{
            return 4*pi*rad*rad*rad;
       }
};

int main(){
    square s(5);
    s.whoAmI();
    cout<<"Area= "<< s.area()<<" "<<"perimeter= "<< s.perimeter()<<"\n";
    circle c(4);
    c.whoAmI();
    cout<<"Area= "<< c.area()<<" "<<"perimeter= "<< c.perimeter()<<"\n";

     cube x(4);
    x.whoAmI();
    cout<<"surfaceArea= "<< x.surfaceArea()<<" "<<"volume= "<< x.volume()<<"\n";

    sphere y(6);
    y.whoAmI();
    cout<<"surfaceArea= "<< y.surfaceArea()<<" "<<"volume= "<< y.volume()<<"\n";

    return 0;
}
