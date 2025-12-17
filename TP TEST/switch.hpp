#ifndef SWITCH_H
#define SWITCH_H

#include <iostream>
#include "networkDevice.hpp"

class Switch : public NetworkDevice {
    public:
        Switch();
        Switch(int);
        ~Switch();

        int getCpuCores() const;
        void setCpuCores(int);

        void printInfo(ostream &os) override;
    private:
        int portCount;
};

#include "switch.tpp"

#endif