#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SmartDevice{
    protected:
    int deviceID;
    string brandName;
    double powerRating;
    
    public:
    SmartDevice(int did, string brand, double power): deviceID(did), brandName(brand), powerRating(power){}
    
    virtual void diagnose() const =0;
    
    double getPowerRating() const{
        return powerRating;
    }
    
    int getDeviceID() const{
        return deviceID;
    }
    string getBrandName() const{
        return brandName;
    }
};

class ThermostatDevice:  virtual public SmartDevice{
    protected:
    double temperatureRange;
    string mode;
    
    public:
    ThermostatDevice(int did, string brand, double power, double temp, string mode) : SmartDevice(did, brand, power), temperatureRange(temp), mode(mode){}
    
    double calculatePowerConsumption(double hours) const{
        return hours*powerRating;
    }
    
    void diagnose() const{
        cout<<"Thermostat - diagnosed"<<endl;
    }
    
};

class SecurityCameraDevice:  virtual public SmartDevice{
    protected:
    string resolution;
    double recordingHours;
    
    public:
    SecurityCameraDevice(int did, string brand, double power,string res,double rec): SmartDevice(did, brand, power), resolution(res), recordingHours(rec){}
    
    virtual double calculateDataUsage(double days) const{
        return days*powerRating;
    }
    
    void diagnose() const{
        cout<<"SecurityCameraDevice - diagnosed"<<endl;
    }
};

class SmartThermostat: public ThermostatDevice{
    private:
    bool remoteControlEnabled;
    
    public:
    SmartThermostat(int did, string brand, double power, double temp, string mode, bool remote):SmartDevice(did, brand, power), ThermostatDevice(did, brand,power, temp,mode), remoteControlEnabled(remote) {}
    
    void diagnose() const{
        cout<<"SmartThermostat - diagnosed"<<endl;
    }
    
    double calculatePowerConsumption(double hours) const{
        return hours*powerRating*5.0;
    }
};

class HybridThermostat: public ThermostatDevice, public SecurityCameraDevice{
    private:
    double energySavingEfficiency;
    
    public:
    HybridThermostat(int did, string brand, double power, double temp, string mode,string res,double rec, double efficiency)
        : SmartDevice(did, brand, power), ThermostatDevice(did, brand, power,temp, mode),SecurityCameraDevice(did, brand, power, res, rec), energySavingEfficiency(efficiency) {}
    
    double calculatePowerConsumption(double hours) const{
        return hours*energySavingEfficiency;
    }
    
    double calculateDataUsage(double days) const{
         return SecurityCameraDevice::calculateDataUsage(days) + (days*2);
    }
      void diagnose() const {
        cout << "Hybrid Thermostat Diagnosis:\n" <<"Brand Name: "<<brandName<< "\nID: " << deviceID <<"\nPower Rating: "<<powerRating<< "\nMode: " << mode
             << "\nTemperature Range: " << temperatureRange
             << "\nResolution: " << resolution<< "\nEnergy Saving Efficiency: " << energySavingEfficiency << endl;
    }
};

void sort_devices_by_power(SmartDevice** devices, int n) {
    sort(devices, devices+n, [](SmartDevice* a, SmartDevice* b){
        return a->getPowerRating() > b->getPowerRating();
    });
}

int main() {
    vector<SmartDevice*> devices;
    
    ThermostatDevice* thermostat = new ThermostatDevice(1, "thermos", 1500.45, 18, "cooling");
    SecurityCameraDevice* camera = new SecurityCameraDevice(2, "cam", 100.674, "1080p", 12);
    SmartThermostat* smartThermostat = new SmartThermostat(3, "smarthermos", 1500.48, 30, "heating", true);
    HybridThermostat* hybridThermostat = new HybridThermostat(4, "hybrid", 1200.64566,25, "cooling", "4K", 24, 20);
    
    devices.push_back(thermostat);
    devices.push_back(camera);
    devices.push_back(smartThermostat);
    
    cout <<"Unsorted:"<<endl;
    for (auto* device : devices){
        cout << "Device ID: " << device->getDeviceID() << ", Brand: " << device->getBrandName()
             << ", Power Rating: " << device->getPowerRating() << "W\n";
    }
    
    sort_devices_by_power(devices.data(), devices.size());
    
     cout <<"\nSorted: "<<endl;
    for (auto* device : devices) {
        cout << "Device ID: " << device->getDeviceID() << ", Brand: " << device->getBrandName()
             << ", Power Rating: " << device->getPowerRating() << "W\n";
    }
    
    cout<<endl;
    hybridThermostat->diagnose();
    
    

    
    return 0;
}
