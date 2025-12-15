#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "card.h"
#include "pokemonCard.h"
#include "energyCard.h"
#include "trainerCard.h"

using namespace std;

class Player {
    public:
        Player();
        Player(string);
        Player(string, vector<Card*>, vector<PokemonCard*>);

        void addCardToBench(Card*);
        void activatePokemonCard(int);
        void attachEnergyCard(int, int);
        void displayBench() const;
        void displayAction() const;
        void attack(int, int, Player&, int);
        void useTrainer(int);

    private:
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;
};

#endif