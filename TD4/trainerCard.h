#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include "card.h"

class TrainerCard : public Card
{
public:
    TrainerCard();
    TrainerCard(string _cardName);

    string getTrainerEffect() const;
    void setTrainerEffect(string);

private:
    string trainerEffect;
};

#endif