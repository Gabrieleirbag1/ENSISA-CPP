#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <vector>
#include <tuple>
#include "card.h"

class PokemonCard : public Card
{
public:
    PokemonCard();
    PokemonCard(string _cardName);
    PokemonCard(string, string, string, int, int, int, vector<tuple<int, int, string, int>>, int, int, string, int);

    string getPokemonType() const;
    string getFamilyName() const;
    int getEvolutionLevel() const;
    int getMaxHP() const;
    int getHP() const;
    vector<tuple<int, int, string, int>> getAttacks() const;
    int getEnergyCost() const;
    int getCurrentEnergyCost() const;
    string getAttackDescription() const;
    int getAttackDamage() const;

    void setPokemonType(string);
    void setFamilyName(string);
    void setEvolutionLevel(int);
    void setMaxHP(int);
    void setHP(int);
    void setAttacks(vector<tuple<int, int, string, int>>);
    void setEnergyCost(int);
    void setCurrentEnergyCost(int);
    void setAttackDescription(string);
    void setAttackDamage(int);

    virtual void displayInfo() const override;

private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, int, string, int>> attacks;
    int energyCost;
    int currentEnergyCost;
    string attackDescription;
    int attackDamage;
};

#endif