// Rowland Sanders
// CECS 282-04
// Prog 4 - Operator Overloading
// 11/04/2020
// I certify that this program is my own original work. I did not copy any part of this program from  any other source. I further certify that I typed each and every line of code in this program.

#include "upDate.h"
#include <string.h>
#include <iostream>

using namespace std;

int upDate::julian()
{
    int m; 
    int d; 
    int y;

    m = dyPtr[0];
    d = dyPtr[1];
    y = dyPtr[2];
    
    return (d - 32075 + 1461 * (y + 4800 + (m - 14) / 12) / 4 + 367 *(m - 2 - (m - 14) / 12 * 12) / 12 - 3 * ((y + 4900 + (m-14) / 12) /100) / 4);
}


void upDate::Julian2Greg(int JD, int &month, int &day, int &year)
{
    int l = JD + 68569;
    int n = 4 * l / 146097;

    l = l - (146097 * n + 3) / 4;

    int i = 4000 * (l + 1) / 1461001;

    l = l - 1461 * i / 4 + 31;

    int j = 80 * l / 2447;
    int k = l - 2447 * j / 80;

    l = j / 11;
    j = j + 2 - 12 * l;
    i = 100 * (n-49) + i + l;
    
    year = i;
    month = j;
    day = k;
}

upDate::upDate(){

    dyPtr = new int[3];

    dyPtr[0] = 5;
    dyPtr[1] = 11;
    dyPtr[2] = 1959;

    count  = count + 1;
}

upDate::upDate(int userm,int userd,int usery) {
    count++;
    dyPtr=new int[3];
    dyPtr[0]=userm;
    dyPtr[1]=userd;
    dyPtr[2]=usery;
    if ((dyPtr[0] > 12) || (dyPtr[1] > 31)) 
    {
        dyPtr[0]=5;
        dyPtr[1]=11;
        dyPtr[2]=1959;

    } else {

        dyPtr[0]=userm;
        dyPtr[1]=userd;
        dyPtr[2]=usery;

    }
    
    
}


upDate::upDate(const upDate &m) { 
    dyPtr=new int[3];

    dyPtr[0]=m.dyPtr[0];
    dyPtr[1]=m.dyPtr[1];
    dyPtr[2]=m.dyPtr[2];

    count++;
}


upDate::~upDate() {
  count = count - 1;
  delete []dyPtr;
}

void upDate::increaseDate(int add) {
    int juliandatetoincrease=julian();

    juliandatetoincrease = (juliandatetoincrease + add);

    Julian2Greg(juliandatetoincrease, dyPtr[0], dyPtr[1], dyPtr[2]);
}


void upDate::decreaseDate(int sub) {
    int juliandatetodecrease = julian();

    juliandatetodecrease = (juliandatetodecrease - sub);

    Julian2Greg(juliandatetodecrease,dyPtr[0], dyPtr[1], dyPtr[2]);
}

int upDate::daysBetween(upDate user) {

    int myjuliandate = julian();

    int userjuliandate = user.julian();

    return (myjuliandate - userjuliandate);
    
}

int upDate::getMonth()
{
    return dyPtr[0];
}

int upDate::getDay()
{
    return dyPtr[1];
}

int upDate::getYear()
{
    return dyPtr[2];
}

void upDate::setDate(int day, int month, int year) 
{
    dyPtr[1] = day;
    dyPtr[0] = month;
    dyPtr[2] = year;
}

string upDate::getMonthName() 
{
    string mNames = "a";
    
    if (dyPtr[0]==1) {
        mNames="January";
    } else {
        if(dyPtr[0]==2) {
            mNames="February";
        } else {
            if (dyPtr[0]==3) {
                mNames="March";
            } else {
                if (dyPtr[0]==4) {
                    mNames="April";
                } else {
                    if (dyPtr[0]==5) {
                        mNames="May";
                    } else {
                        if (dyPtr[0]==6) {
                            mNames="June";
                        } else {
                            if (dyPtr[0]==7) {
                                mNames="July";
                            } else {
                                if (dyPtr[0]==8) {
                                    mNames="August";
                                } else {
                                    if (dyPtr[0]==9) {
                                        mNames="September";
                                    } else {
                                        if (dyPtr[0]==10) {
                                            mNames="October";
                                        } else {
                                            if (dyPtr[0]==11) {
                                                mNames="November";
                                            } else {
                                                if (dyPtr[0]==12) {
                                                    mNames="December";
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return mNames;
}


int upDate::count = 0;

int upDate::GetDateCount()
{
    return count;
}

//the necessary class methods (functions) to support the following:

upDate upDate::operator + (int x) 
{
    upDate temp(*this);
    temp.increaseDate(x);
    return temp;
}


upDate upDate::operator=(upDate d) 
{
    dyPtr[0] = d.dyPtr[0];
    dyPtr[1] = d.dyPtr[1];
    dyPtr[2] = d.dyPtr[2];
    return (*this);
}

upDate upDate::operator - (int x) 
{
    upDate temp(*this);

    temp.decreaseDate(x);

    return temp;
}

upDate operator +(int x, upDate D)
{
    return D + x;
}

int upDate::operator -(upDate D)
{
    return daysBetween(D);
}

upDate operator -(int x, upDate D)
{
    return D - x;
}

ostream &operator <<(ostream &out, upDate D)
{
    out << D.getMonth() << "/" << D.getDay() << "/" << D.getYear();
    return out;
}


upDate upDate::operator --()
{
    decreaseDate(1);
    return (*this);
}

upDate upDate::operator ++()
{
    increaseDate(1);
    return (*this);
}

upDate upDate::operator ++(int temp)
{
    increaseDate(1);
    return (*this);
}

upDate upDate::operator --(int temp)
{
    decreaseDate(1);
    return (*this);
}

// Comparison Operators
bool upDate::operator == (upDate T)
{
    if(julian() == T.julian())
        return true;
    
    return false;
}

bool upDate::operator <(upDate T)
{
    if(julian() < T.julian())
        return true;
    
    return false;
}

bool upDate::operator > (upDate T)
{
  if(julian() > T.julian()){
  return true;
  } else {
    return false;
  }

  
}


