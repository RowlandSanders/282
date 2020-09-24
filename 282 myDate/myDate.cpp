

//Rowland Sanders
//Prog2 - CECS 282-04
//myDate
//09/23/2020
// I certify that this program is my own original work. I did not copy any part of this program from
//any other source. I further certify that I typed each and every line of code in this program


#include "myDate.h"
#include <iostream>
using namespace std;

int Greg2Julian(int month,int day,int year) 
{
    
    int julianNum = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month - 14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
    return julianNum; //formula as given
}
void Julian2Greg(int JD,int &month, int &day, int &year) {
    
    int l = (JD + 68569);
    int n = (4 * l / 146097);
    
    l = l - (146097 * n + 3) / 4; 
    
    int i = 4000 * (l + 1) / 1461001;
    
    l = (l - 1461 * i / 4 + 31);
    
    int j = (80 * l / 2447);
    int k = (l -2447 * j / 80);
    
    l = (j / 11);
    j = (j + 2 - 12 * l);
    i = 100 * (n - 49)+ i + l;
    
    year = i;
    month = j;
    day = k;
    
}

myDate::myDate()
{
    
    int M = 5;
    int D = 11;
    int Y = 1959;
    
}

myDate::myDate(int betweenm,int betweend,int betweeny) 
{
    M = betweenm;
    D = betweend;
    Y = betweeny;
    
    if (M > 12 || D > 31) {
        
        M = 9;
        D = 23;
        Y = 2020;
    }
    
}


void myDate::decreaseDate(int d) {
    
    int juliandatetodecrease = Greg2Julian(M, D, Y);
    
    juliandatetodecrease = juliandatetodecrease - d;
    
    Julian2Greg(juliandatetodecrease, M, D, Y);
}

void myDate::increaseDate(int n) 
{
    int juliandatetoincrease = Greg2Julian(M, D, Y);
    
    juliandatetoincrease = juliandatetoincrease + n;
    
    Julian2Greg(juliandatetoincrease, M, D, Y);
}

int myDate::getMonth() {
    return M;
}
int myDate::getDay(){
    return D;
}

int myDate::getYear() {
    return Y;
}


int myDate::daysBetween(myDate x) {
    
    int JD = Greg2Julian(M, D, Y);
    
    int umonth = x.M;
    int uyear = x.Y;
    int uday = x.D;
    
    int ujuliandate = Greg2Julian(umonth, uday, uyear);
    int change = ujuliandate - JD;
    return change;
}

int myDate::dayOfYear()
{
    int leap = 0; //default for non leap years
    
    if (((Y % 4 == 0) && (Y % 100!= 0)) || (Y % 400 == 0)) {
        leap = 1; // is leap year  
        
    } else {
        leap = 0; // is not a leap year
    }
    
    
    switch (M) { //have to make cases for each month, thats why the days are different
        case 1: return D;
            break;
            
        case 2: return 31 + D;
            break;
            
        case 3: if (leap == 1) {
            return 31+29 + D;
            
        } else {
            return 31+28 + D;
            
        }
            break;
            
        case 4: if (leap == 1) {
            return 31+29+31 + D;
            
        } else {
            return 31+28+31 + D;
            
        }
            
            break;
            
        case 5: if (leap == 1) {
            return 31+29+31+30 + D;
            
        } else {
            return 31+29+31+30 + D;
            
        }
            break;
        case 6: if (leap == 1) {
            return 31+29+31+30+31 + D;
            
        } else {
            return 31+28+31+30+31 + D;
            
        }
            break;
            
        case 7: if (leap == 1) {
            return 31+29+31+30+31+30 + D;
            
        } else {
            return 31+28+31+30+31+30 + D;
            
        }
            break;
            
        case 8: if (leap == 1) {
            return  31+29+31+30+31+30+31 + D;
            
        } else {
            return 31+28+31+30+31+30+31 + D;
            
        }
            break;
            
        case 9: if (leap == 1) {
            return 31+29+31+30+31+30+31+31 + D;
            
        } else {
            return 31+28+31+30+31+30+31+31 + D;
            
        }
            break;
            
        case 10: if (leap == 1) {
            return 31+29+31+30+31+30+31+31+30 + D;
            
        } else {
            return 31+28+31+30+31+30+31+31+30 + D;
            
        }
            break;
            
        case 11: if (leap == 1) {
            return 31+29+31+30+31+30+31+31+30+31;
            
        } else {
            return 31+28+31+30+31+30+31+31+30+31;
            
        }
            break;
            
        case 12:
            if (leap == 1) {
                return 31+29+31+30+31+30+31+31+30+31+30 + D;
                
            } else {
                return 31+28+31+30+31+30+31+31+30+31+30 + D;
                
            }
            break;
            
        default: cout<<"    "; //will also be blank if its not within the 12
            
    }
    
    return 0;
}

void myDate::display () 
{
    switch (M) {
            
        case 1: cout<<"January "<<D<<" "<<Y;
            break;
            
        case 2: cout<<"February "<<D<<" "<<Y;
            break;
            
        case 3: cout<<"March "<<D<<" "<<Y;
            break;
            
        case 4: cout<<"April "<<D<<" "<<Y;
            break;
            
        case 5: cout<<"May "<<D<<" "<<Y;
            break;
            
        case 6: cout<<"June "<<D<<" "<<Y;
            break;
            
        case 7: cout<<"July "<<D<<" "<<Y;
            break;
            
        case 8: cout<<"August "<<D<<" "<<Y;
            break;
            
        case 9: cout<<"September "<<D<<" "<<Y;
            break;
            
        case 10: cout<<"October "<<D<<" "<<Y;
            break;
            
        case 11: cout<<"November "<<D<<" "<<Y;
            break;
            
        case 12: cout<<"December "<<D<<" "<<Y;
            break;
            
        default: cout<<"    "; //default if not inbound
            
    }
}

string myDate::dayName()
{
    int julianforday = Greg2Julian(M, D, Y);
    int curr = julianforday % 7;
    string day;
    
    if (curr == 1) {
        day = "Tuesday ";
        
    } else {
        if (curr == 2){
            day = "Wednesday ";
            
        } else {
            if (curr == 3) {
                day = "Thursday ";
                
            } else {
                if (curr == 4) {
                    day = "Friday ";
                    
                } else {
                    if (curr == 5) {
                        day = "Saturday ";
                        
                    } else {
                        if (curr == 6 ) {
                            day = "Sunday ";
                            
                        } else {
                            if (curr == 0) {
                                day = "Monday ";
                                
                            }
                        }
                    }
                }
            }
        }
    }
    
    return day;
}

