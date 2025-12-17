#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include "networkDevice.hpp"

class Server : public NetworkDevice {
    public:
        Server();
        Server(int);
        ~Server();

        int getCpuCores() const;
        void setCpuCores(int);

        void printInfo(ostream &os) override;
    private:
        int cpuCores;
};

#include "server.tpp"

#endif