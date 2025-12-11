#include "headers/trainerCard.h"

TrainerCard::TrainerCard() : Card() {}

TrainerCard::TrainerCard(string _cardName) : Card(_cardName) {}

string TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

void TrainerCard::setTrainerEffect(string _trainerEffect) {
    trainerEffect = _trainerEffect;
}