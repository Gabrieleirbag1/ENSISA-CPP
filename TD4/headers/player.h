#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "card.h"
#include "pokemonCard.h"
#include "energyCard.h"

using namespace std;

class Player {
    public:
        Player();
        Player(string);
        Player(string, vector<Card*>, vector<PokemonCard*>);

        void addCardToBench(Card*);

    private:
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;
};

#endif