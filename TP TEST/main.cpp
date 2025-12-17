#include "networkInfrastructure.hpp"
#include "server.hpp"
#include "router.hpp"
#include "switch.hpp"

#include <iostream>

int main() {
    NetworkInfrastructure network("ENSISA Network");
    Server* server1 = new Server(16);
    server1->setHostname("server1");
    server1->setIpAddress("10.5.3.1");
    server1->setIsCritical(false);
    server1->setLocation("Strasbourg");
    server1->setPowerConsumption(150);
    server1->setVendor("OVH");
    server1->setOsVersion("1.4.2");
    server1->setYear(2005);
    network.addDevice(server1);

    Router* router1 = new Router(8);
    router1->setHostname("router1");
    network.addDevice(router1);

    Switch* switch1 = new Switch(24);
    switch1->setHostname("switch1");
    network.addDevice(switch1);

    NetworkDevice* foundDevice = network.searchDeviceByHostname("server1");
    if (foundDevice) {
        std::cout << std::endl << "----------DEVICE FOUND-----------" << std::endl;
        foundDevice->printInfo(cout);
    }

    vector<NetworkDevice*> devices = network.listDevices();
    for (auto it = devices.begin(); it != devices.end(); ++it) {
        std::cout << std::endl << "----------DEVICE -----------" << std::endl;
        (*it)->printInfo(std::cout);
    }
 
    return 0;
}