#include "headers/player.h"

Player::Player() {}
Player::Player(string _playerName) : playerName(_playerName) {}
Player::Player(string _playerName, vector<Card*> _benchCards, vector<PokemonCard*> _actionCards) :
    playerName(_playerName), benchCards(_benchCards), actionCards(_actionCards) {}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}