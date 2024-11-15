#include<bits/stdc++.h>
using namespace std;

class SmartDevice{
    protected:
    int deviceID;
    string brandName;
    double powerRating;
    public:
    SmartDevice(int id,string name,double rating):deviceID(id), brandName(name), powerRating(rating){}
    double get_powerRating(){
        return powerRating;
    }
    int get_deviceID(){
         return deviceID;
    }
    string get_brandName(){
        return brandName;
    }
    virtual void diagnose()=0;
    
    void display(){
        cout<<"Device id: "<<deviceID<<"\n";
        cout<<"Name: "<<brandName<<"\n";
        cout<<"Power Rating: "<<powerRating<<"\n";
    }
    
    virtual ~SmartDevice(){
        
    }
};

class ThermostatDevice: virtual public SmartDevice{
    private:
    double temperatureRange;
    string mode;
    public:
    ThermostatDevice(int id,string name,double rating,double temp,string mo): SmartDevice(id,name,rating),temperatureRange(temp),mode(mo){
    }
    double calculatePowerConsumption(double hours){
        return (powerRating)*hours;
    }
    
    void display(){
         SmartDevice::display();
       cout<<"Temperature Range: "<<temperatureRange<<"\n";
       cout<<"mode: "<<mode<<"\n";
    }
    void diagnose(){
         cout<<"Thermostat Device\n";
    }
    
};

class SecurityCameraDevice: virtual public SmartDevice{
    private:
    int resolution;
    int recordingHours;
    public:
    SecurityCameraDevice(int id,string name,double rating,int res,int rec):SmartDevice(id,name,rating),resolution(res),recordingHours(rec){}
    
    double calculateDataUsage(double days)const{
        return powerRating*days;
    }
    
     void diagnose(){
        cout<<"Security camera\n";
    }
    void display(){
      
        cout<<"resolution: "<<resolution<<"\n";
        cout<<"recording hour: "<<recordingHours<<"\n";
    }
};

class SmartThermostat:public ThermostatDevice{
    private:
    bool remoteControlEnabled;
       public:
    SmartThermostat(int id,string name,double rating,double temp,string mo,bool remote):SmartDevice(id,name,rating),ThermostatDevice(id,name,rating,temp,mo),remoteControlEnabled(remote){}
    
    double calculatePowerConsumption(double seconds){
        cout<<"The power is: ";
        return seconds*powerRating;
    } 
     
    void diagnose(){
        cout<<"Smartthermostat\n";
    }
};

class HybridThermostat:public ThermostatDevice,public SecurityCameraDevice{
    private:
    int energySavingEfficiency;
    public:
    HybridThermostat(int id,string name,double rating,double temp,string mo,int res,int rec,int energy):SmartDevice(id,name,rating),ThermostatDevice(id,name,rating,temp,mo),SecurityCameraDevice(id,name,rating,res,rec),energySavingEfficiency(energy){}
    
    
    double calculatePowerConsumption(double hour){
        cout<<"The power is: ";
        return (hour*powerRating*energySavingEfficiency)/100;
    }
    double calculateDataUsage(double hour){
        return SecurityCameraDevice::calculateDataUsage(hour)*hour*2;
      }
    
      void diagnose(){
        cout<<" HybridThermostat\n";
    }
    void display(){
          ThermostatDevice::display();
        SecurityCameraDevice::display();
        cout<<"Energy efficiency: "<<energySavingEfficiency<<"\n";
    }
};

void sort_devices_by_power(SmartDevice** devices, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(devices[i]->get_powerRating()<devices[j]->get_powerRating()){
                swap(devices[i],devices[j]);
            }
        }
    }
    cout<<"Sorted: \n";
     for(int i=0;i<n;i++){
        cout<<"DeviceId: "<<devices[i]->get_deviceID()<<"\n";
         cout<<"BrandName: "<<devices[i]->get_brandName()<<"\n";
        cout<<"powerRating: "<<devices[i]->get_powerRating()<<"\n";
    }
    
}

int main(){
    vector<SmartDevice*>device;
   SmartDevice* Thermos=new ThermostatDevice(123,"Bob",5.0,15.2,"On");
   SmartDevice* cake=new SecurityCameraDevice(55,"cam",4.5,1080,150);
   SmartDevice* pic=new SmartThermostat(85,"larry",3.8,89.2,"off",false);
   
   device.push_back(Thermos);
    device.push_back(cake);
     device.push_back(pic);
   int n=device.size();
   
   sort_devices_by_power(device.data(),n);
   
   HybridThermostat Hyb(95,"garry",3.5,87.6,"on",false,180,58);
      cout<<"\nHybrid\n";
    Hyb.display();
    
    return 0;
}
