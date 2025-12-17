#ifndef NETWORK_DEVICE_H
#define NETWORK_DEVICE_H

#include <iostream>
#include <string>

using namespace std;

class NetworkDevice {
    public:
        NetworkDevice();
        NetworkDevice(string, string, string, string, string, int, double, bool);
        NetworkDevice(const NetworkDevice& networkDeviceCopy);

        ~NetworkDevice();

        string getHostname() const;
        string getIpAddress() const;
        string getLocation() const;
        string getVendor() const;
        string getOsVersion() const;
        int getYear() const;
        double getPowerConsumption() const;
        bool getIsCritical() const;

        void setHostname(string);
        void setIpAddress(string);
        void setLocation(string);
        void setVendor(string);
        void setOsVersion(string);
        void setYear(int);
        void setPowerConsumption(double);
        void setIsCritical(bool);

        void ping();
        virtual void printInfo(ostream &os);
    private:
        string hostname;
        string ipAddress;
        string location;
        string vendor;
        string osVersion;
        int year;
        double powerCosumption;
        bool isCritical;
};

#include "networkDevice.tpp"

#endif