#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

#include <string>
using namespace std;

class Card {
    public:
        Card();
        Card(string _cardName);

        virtual void displayInfo() const = 0;

    private:
        string cardName;

};

#endif