#include "networkDevice.hpp"

NetworkDevice::NetworkDevice() {}
NetworkDevice::NetworkDevice(
    string _hostname, string _ipAddres, string _location, string _vendor, string _osVersion, int _year, double _powerConsumption, bool _iscritical) 
    : hostname(_hostname), ipAddress(_ipAddres), location(_location), vendor(_vendor), osVersion(_osVersion), year(_year), powerCosumption(_powerConsumption), isCritical(_iscritical) 
{}

NetworkDevice::NetworkDevice(const NetworkDevice &networkDeviceCopy) {}

NetworkDevice::~NetworkDevice() {}


string NetworkDevice::getHostname() const {
    return hostname;
}

string NetworkDevice::getIpAddress() const {
    return ipAddress;
}

string NetworkDevice::getLocation() const {
    return location;
}

string NetworkDevice::getVendor() const {
    return vendor;
}

string NetworkDevice::getOsVersion() const {
    return osVersion;
}

int NetworkDevice::getYear() const {
    return year;
}

double NetworkDevice::getPowerConsumption() const {
    return powerCosumption;
}

bool NetworkDevice::getIsCritical() const {
    return isCritical;
}

void NetworkDevice::setHostname(string _hostname) {
    hostname = _hostname;
}

void NetworkDevice::setIpAddress(string _ipAddress) {
    ipAddress = _ipAddress;
}

void NetworkDevice::setLocation(string _location) {
    location = _location;
}

void NetworkDevice::setVendor(string _vendor) {
    vendor = _vendor;
}

void NetworkDevice::setOsVersion(string _osVersion) {
    osVersion = _osVersion;
}

void NetworkDevice::setYear(int _year) {
    year = _year;
}

void NetworkDevice::setPowerConsumption(double _powerConsumption) {
    powerCosumption = _powerConsumption;
}

void NetworkDevice::setIsCritical(bool _isCritical) {
    isCritical = _isCritical;
}

void NetworkDevice::ping() {
    // simule un ping
    cout << "Pinging " << ipAddress << "..." << endl;
    cout << "Reply from " << ipAddress << ": bytes=32 time<1ms TTL=64" << endl;
}

void NetworkDevice::printInfo(ostream &os) {
    os << "Network device of unknow type:" << endl;
    os << "Hostname :" << hostname << endl;
    os << "IP address :" << ipAddress << endl;
    os << "Location :" << location << endl;
    os << "Vendor :" << vendor << endl;
    os << "OS version :" << osVersion << endl;
    os << "Installed in :" << year << endl;
    if (isCritical) {
        os << "This device is critical" << endl;
    } else {
        os << "This device is not critical" << endl;
    }
    os << "Power consumption :" << powerCosumption << endl;
}



