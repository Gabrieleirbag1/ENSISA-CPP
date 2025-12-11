#include "headers/energyCard.h"

EnergyCard::EnergyCard() : Card() {}

EnergyCard::EnergyCard(string _cardName = "Energy") : Card(_cardName) {}

string EnergyCard::getEnergyType() const {
    return energyType;
}

void EnergyCard::setEnergyType(string _energyType) {
    energyType = _energyType;
}