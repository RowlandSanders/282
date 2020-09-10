#include <iostream>
using namespace std;
#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>


class Card{
private:
    char suit;
    
    char rank;
    
public:
    Card();
    
    Card(char r,char s);
    
    void setCard(char r,char s);
    
    int getValue();
    
    void showCard();
    
};


#endif