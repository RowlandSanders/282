

#ifndef upDate_h
#define upDate_h

#include <iostream>
using namespace std;

class upDate {
    
private:
  static int count;
  int *dyPtr;
    
public:
    upDate();

    upDate(int userm,int userd,int usery);
    upDate(const upDate &m);
    upDate(int j);
    ~upDate();
    void setDate(int D, int M, int Y);
  
    string getMonthName();

    int getMonth();
    int getDay();
    int getYear();

    void increaseDate(int add);
    void decreaseDate(int sub);

    int daysBetween(upDate user);

    static int GetDateCount();

    int julian();

    void Julian2Greg(int JD, int &month, int &day, int &year);
    
    upDate operator+(int n);
    upDate operator-(int n);
    upDate operator =(upDate T);

    bool operator==(upDate D);
    bool operator<(upDate D);
    bool operator>(upDate D);

    int operator -(upDate D);

    friend upDate operator +(int n, upDate D);
    friend upDate operator -(int n, upDate D);
    
    friend ostream &operator <<(ostream &out, upDate D);
    
    upDate operator ++(int d);
    upDate operator ++();
    upDate operator --(int d);
    upDate operator --();
 
};

#endif 




