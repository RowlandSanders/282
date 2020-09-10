#include "Card.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
    

    Card::Card(){
        
    }
    Card::Card(char r,char s) {
        suit=s;
        rank=r;
    }
    void Card::setCard(char r,char s){
        suit=s;
        rank=r;
        
    }
    int Card:: getValue(){
        if (rank=='A'){
            return 1;
        } else {
            if (rank>='2' && rank<='9') {
                return rank-48;
                
            } else {
                if (rank=='J'||rank=='Q'||rank=='K'||rank=='T') {
                    
                    return 10;
                } else {
                    
                    return 0;
                }
            }
        }
    }
    void Card:: showCard(){
        if (rank=='T'){
            cout<<"10"<<suit;
            
        } else {
          cout<<rank<<suit;
        }
    }