#include "pokemonCard.h"

PokemonCard::PokemonCard() : Card() {}

PokemonCard::PokemonCard(string cardName) : Card(cardName) {}

string PokemonCard::getPokemonType() const
{
    return pokemonType;
}
string PokemonCard::getFamilyName() const
{
    return familyName;
}
int PokemonCard::getEvolutionLevel() const
{
    return evolutionLevel;
}
int PokemonCard::getMaxHP() const
{
    return maxHP;
}
int PokemonCard::getHP() const
{
    return hp;
}
vector<tuple<int, int, string, int>> PokemonCard::getAttacks() const
{
    return attacks;
}
int PokemonCard::getEnergyCost() const
{
    return energyCost;
}
int PokemonCard::getCurrentEnergyCost() const
{
    return currentEnergyCost;
}

string PokemonCard::getAttackDescription() const 
{
    return attackDescription;
}

int PokemonCard::getAttackDamage() const 
{
    return attackDamage;
}

void PokemonCard::setPokemonType(string _pokemonType)
{
    pokemonType = _pokemonType;
}

void PokemonCard::setFamilyName(string _familyName)
{
    familyName = _familyName;
}

void PokemonCard::setEvolutionLevel(int _evolutionLevel)
{
    evolutionLevel = _evolutionLevel;
}

void PokemonCard::setMaxHP(int _maxHP)
{
    maxHP = _maxHP;
}

void PokemonCard::setHP(int _hp)
{
    hp = _hp;
}

void PokemonCard::setAttacks(vector<tuple<int, int, string, int>> _attacks)
{
    attacks = _attacks;
}

void PokemonCard::setEnergyCost(int _energyCost)
{
    energyCost = _energyCost;
}

void PokemonCard::setCurrentEnergyCost(int _currentEnergyCost)
{
    currentEnergyCost = _currentEnergyCost;
}

void PokemonCard::setAttackDescription(string _attackDescription)
{
    attackDescription = _attackDescription;
}

void PokemonCard::setAttackDamage(int _attackDamage)
{
    attackDamage = _attackDamage;
}