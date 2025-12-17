#include "server.hpp"

Server::Server() {}

Server::Server(int _cpuCores) : cpuCores(_cpuCores) {}

Server::~Server() {}

int Server::getCpuCores() const {
    return cpuCores;
}

void Server::setCpuCores(int _cpuCores) {
    cpuCores = _cpuCores;
}

void Server::printInfo(ostream &os) {    os << "Network device of unknow type:" << endl;
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

    os << "CPU Cores :" << cpuCores;
}