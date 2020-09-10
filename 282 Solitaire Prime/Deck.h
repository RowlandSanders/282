#ifndef Deck_h
#define Deck_h
#include "Card.h"
#include <iostream>
using namespace std;


#include <stdio.h>


class Deck {
private:
    Card storage[52];
    
    int curr;
    
public:
    Deck();
    
    void refreshDeck();
    
    Card deal();
    
    void shuffle();
    
    int cardsLeft();
    
    void showDeck();
    
};

#endif