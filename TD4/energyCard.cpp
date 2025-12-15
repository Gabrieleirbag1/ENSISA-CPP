#include "headers/energyCard.h"
#include <iostream>

EnergyCard::EnergyCard() : Card() {}

EnergyCard::EnergyCard(string _energyType) : Card(_energyType), energyType(_energyType) {}

string EnergyCard::getEnergyType() const {
    return energyType;
}

void EnergyCard::setEnergyType(string _energyType) {
    energyType = _energyType;
}

void EnergyCard::displayInfo() const {
    cout << "Energy Card - Name: " << getCardName() << ", Type: " << energyType << endl;
}