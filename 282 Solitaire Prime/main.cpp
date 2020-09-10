#include "Card.h"
#include "Deck.h"
#include <iostream>
using namespace std;

//Rowland Sanders
//CECS 282-04
//Prog1 - SolitairePrime
//09/09/2020
//I certify that this program is my own original work. I did not copy any part of this program from            
//any other source. I further certify that I typed each and every line of code in this program

int menu(){
    
    cout << "Welcome to Solitaire Prime!\n 1) New Deck\n 2) Display Deck\n 3) Shuffle Deck\n 4) Play Solitaire Prime\n 5) Exit\n";
    int userchoice;
    cin>>userchoice;
    return userchoice;
}


    bool isPrime(int num) {
        if (num == 1||num == 0) {
            return false;
        }
        for (int i = 2;i<num-1;i++) {
            if (num%i == 0) {
                return false;
                
            }
        }
        return true;
    }

int main(int argc, const char * argv[]) { //argc means "argument count". It signifies how many arguments are being passed into the executable. argv means "argument values". It is a pointer to an array of characters. Or to think about it in another way, it is an array of C strings (since C strings are just arrays of characters).
    
    Deck deck;
    int userchoice = 0;
    
    while (userchoice != 5) {
        userchoice = menu();
        
    if (userchoice == 1) {
        deck.refreshDeck();
        deck.showDeck();
    }
    
    else if
        (userchoice == 2){
        deck.showDeck(); }
        
    else if
             (userchoice == 3){
                deck.shuffle();
                 deck.showDeck();}
        
    else if
                    (userchoice == 4) {
                        cout<<"Playing Solitaire Prime!!!\n";
                        
                        int total = 0;
                        int primecount = 0;
                        int finish = 0;
                        
                        int i = 0;
                        while (i<52) {
                            Card play = deck.deal();
                            play.showCard();

                            cout<<" ";
                            int value=play.getValue();
                            total = total + value;
                            
                            bool prime = isPrime(total);
                            
                            if (prime == true) {
                                cout<<"Prime:"<<total<<endl;
                                total=0;
                                primecount++;
                                int cardsleft = deck.cardsLeft();
                                if (cardsleft == 0) {
                                    cout<<"Winner in "<<primecount<<" piles!\n"<<endl;
                                    finish++;
                                }
                            }
                            i++;
                        }
                        if (finish == 0){
                            cout<<"Loser\n"<<endl;
                        }
                        
                    } else if
                        (userchoice == 5) {
                            cout<<"Closing Program";
                    }
                }
    return 0;
    
}