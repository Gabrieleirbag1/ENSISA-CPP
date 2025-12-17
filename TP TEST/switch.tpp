#include "switch.hpp"

Switch::Switch() {}

Switch::Switch(int _portCount) : portCount(_portCount) {}

Switch::~Switch() {}

int Switch::getCpuCores() const {
    return portCount;
}

void Switch::setCpuCores(int _portCount) {
    portCount = _portCount;
}

void Switch::printInfo(ostream &os) {    os << "Network device of unknow type:" << endl;
    os << "Hostname :" << getHostname() << endl;
    os << "IP address :" << getIpAddress() << endl;
    os << "Location :" << getLocation() << endl;
    os << "Vendor :" << getVendor() << endl;
    os << "OS version :" << getOsVersion() << endl;
    os << "Installed in :" << getYear() << endl;
    if (getIsCritical()) {
        os << "This device is critical" << endl;
    } else {
        os << "This device is not critical" << endl;
    }
    os << "Power consumption :" << getPowerConsumption() << endl;

    os << "CPU Cores :" << portCount; // add this
}