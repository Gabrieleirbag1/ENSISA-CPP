#include "headers/player.h"
#include <iostream>

Player::Player() {}
Player::Player(string _playerName) : playerName(_playerName) {}
Player::Player(string _playerName, vector<Card*> _benchCards, vector<PokemonCard*> _actionCards) :
    playerName(_playerName), benchCards(_benchCards), actionCards(_actionCards) {}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < benchCards.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemonCard) {
            actionCards.push_back(pokemonCard);
            cout << playerName << " is activating a Pokemon Card: " << pokemonCard->getCardName() << endl;
        }
    }
}

void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    if (benchIndex >= 0 && benchIndex < benchCards.size() && actionIndex >= 0 && actionIndex < actionCards.size()) {
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
        if (energyCard) {
            PokemonCard* pokemonCard = actionCards[actionIndex];
            pokemonCard->setCurrentEnergyCost(pokemonCard->getCurrentEnergyCost() + 1);
            cout << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType() 
                 << " to the Pokemon " << pokemonCard->getCardName() 
                 << " | Current Energy Storage: " << pokemonCard->getCurrentEnergyCost() << endl;
        }
    }
}

void Player::displayBench() const {
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (size_t i = 0; i < benchCards.size(); i++) {
        cout << "Card " << i << ": ";
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction() const {
    cout << "Action cards for Player " << playerName << ":" << endl;
    for (size_t i = 0; i < actionCards.size(); i++) {
        cout << "Card " << i << ": ";
        actionCards[i]->displayInfo();
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex) {
    if (attackerIndex >= 0 && attackerIndex < actionCards.size() && 
        targetIndex >= 0 && targetIndex < opponent.actionCards.size()) {
        
        PokemonCard* attacker = actionCards[attackerIndex];
        PokemonCard* target = opponent.actionCards[targetIndex];
        
        vector<tuple<int, int, string, int>> attacks = attacker->getAttacks();
        if (attackIndex >= 0 && attackIndex < attacks.size()) {
            int damage = get<1>(attacks[attackIndex]);
            int energyCost = get<0>(attacks[attackIndex]);
            string attackDesc = get<2>(attacks[attackIndex]);
            
            if (attacker->getCurrentEnergyCost() >= energyCost) {
                target->setHP(target->getHP() - damage);
                cout << playerName << "'s " << attacker->getCardName() << " attacks " 
                     << opponent.playerName << "'s " << target->getCardName() 
                     << " with " << attackDesc << " for " << damage << " damage!" << endl;
                cout << target->getCardName() << " now has " << target->getHP() << " HP remaining." << endl;
            } else {
                cout << "Not enough energy to attack! Need " << energyCost 
                     << " but have " << attacker->getCurrentEnergyCost() << endl;
            }
        }
    }
}

void Player::useTrainer(int index) {
    if (index >= 0 && index < benchCards.size()) {
        TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[index]);
        if (trainerCard) {
            cout << playerName << " is using the Trainer Card: " << trainerCard->getCardName() << endl;
            cout << "Effect: " << trainerCard->getTrainerEffect() << endl;
            
            // Heal all action pokemon
            for (PokemonCard* pokemon : actionCards) {
                pokemon->setHP(pokemon->getMaxHP());
                cout << pokemon->getCardName() << " has been healed to full HP: " << pokemon->getHP() << endl;
            }
        }
    }
}
