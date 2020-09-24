
#include <iostream>
using namespace std;

#ifndef myDate_h
#define myDate_h
class myDate {

private:

    int M;
    int D;
    int Y;
    
public:
    
    myDate();
    myDate(int userm,int userd,int usery);
    
    void display ();
    void increaseDate(int n);
    void decreaseDate(int d);
    
    int daysBetween(myDate user);
    
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    
    string dayName();

    
};

#endif /* myDate_h */
