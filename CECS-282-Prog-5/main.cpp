// Rowland Sanders
// CECS 282-04
// Prog 45- STL
// 12/2/2020
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.

#include <vector>
#include <iostream>
#include <cmath>
#include <iostream>
#include <vector>
#include <chrono>
#include <bits/stdc++.h>
#include <map> 

using namespace std;

class BigInt {
public:
    explicit operator long();
    explicit operator string();
    explicit BigInt(const string& s);
    void print() const;

    BigInt(int b);
    BigInt();
    BigInt(const BigInt& b);

    BigInt& operator=(int b);
    bool operator==(const BigInt& b);
    friend ostream& operator<<(ostream &os, const BigInt &b);

    BigInt operator++(int);
    BigInt operator-(int b);
    BigInt operator+(BigInt b);

    bool operator<(const BigInt& b);
    bool operator<=(const BigInt& b);
    bool operator>(const BigInt& b);
    

private:
    friend bool operator<(const BigInt a, const BigInt b);
    void curr();
    vector<char> vec;
    
};

static map<int, BigInt> mainMap;
BigInt goldRabbits(BigInt);
int goldRabbits(int);
void pause() {cout << "\nPress Enter to continue..."; getchar();}

int main()
{
    BigInt B1("123456789123456789123456789123456789");
    BigInt B2(B1);

    BigInt MAX(INT_MAX);

    cout << "B1: "<<B1<<"\nB2: "<<B2<<"\nMAX: "<< MAX <<endl;
    pause();

    cout << "\nB1: ";
    B1.print();
    cout << endl;

    pause();

	for(BigInt i=0; i<=3000; i++){
		cout << "\ngoldRabbits("<< i <<") = " << goldRabbits(i);
	}
    pause();

    cout<< "\nThis is the value of goldRabbits(3000)\n\n";
    BigInt goldRabbitsMax =  goldRabbits(BigInt(3000));
    goldRabbitsMax.print();

    pause();

    int n = 500;
    try{

        cout << "The value of goldRabbits(" << n << ") is:"<<goldRabbits(n)<<endl;
    }
    catch(string error)
    {
        cout << error << endl;
    }

    pause();
}

BigInt goldRabbits(BigInt n)
{

    if (n == 0) { 
        mainMap[0] = 1;
        return 1;
    }
    if(n == 1) {
        mainMap[1] = 1;
        return 1;
    }
    else {
        BigInt start; 
        BigInt second;
        if (mainMap.count((long(n) - 1))) 
        {
            start = mainMap.find(long(n)-1) -> second;
        }
        else 
        {
            start = goldRabbits(n - 1);
            mainMap[long(n) - 1] = start;
        }


        if (mainMap.count(long(n) - 2)) {
            second = mainMap.find(long(n)-2)->second;
        }
        else {
            second = goldRabbits(n - 2);
            mainMap[long(n - 2)] = second;
        }
        BigInt temp = start + second;

        return temp;
    }
}

int goldRabbits(int n)
{
    if (n==0)					
      return 1;
    if (n==1)
      return 1;
    else {
        int temp1 = goldRabbits(n - 1);
        int temp2 = goldRabbits(n - 2);

        int temp3 = temp1 + temp2;
        if (temp3 < temp1 || temp3 < temp2) {
            throw " Overflow Error – goldRabbits overflowed using " + to_string(n+1);
        }
        return temp3;
    }
}

BigInt::BigInt(int b) {
    vec = vector<char>();
    if(b == 0) {
        vec.push_back(0);
    }
    else {
        for (int i = b; i > 0; i = (i/10)) {
          int temp = i % 10;
          vec.push_back(temp);
        }
    }
}

void BigInt::print() const {
    cout << string(BigInt(*this)) << endl;
}

BigInt::BigInt(const string& s) {
    for(int i = s.size() - 1; i >= 0;) 
    {
        vec.push_back(s[i] - '0');
        i--;
    }
}

BigInt &BigInt::operator=(int b) {
    return *this = BigInt(b);
}

bool BigInt::operator<(const BigInt &b) {
    if(b.vec.size() < vec.size()) 
    {
        return false;
    }
    else if(b.vec.size() > vec.size()) 
    {
        return true;
    }
    else {
        for(int i = vec.size() - 1; i >= 0; i--) 
        {
            if(vec.at(i) < b.vec.at(i)) 
            {
                return true;
            }
            else if(vec.at(i) > b.vec.at(i)) 
            {
                return false;
            }
        }
        return false;
    }
}

BigInt BigInt::operator++(int){
    return *this = *this + 1;
}

bool BigInt::operator==(const BigInt& b) {
    return vec == b.vec;
}

BigInt BigInt::operator-(int b) {
    BigInt balance(*this);
    balance.vec.at(0) -= b;
    balance.curr();
    return balance;
}


BigInt BigInt::operator+(BigInt b) {
    BigInt balance(*this);
    for(int i = 0; i < b.vec.size(); i++) 
    {
        balance.vec.at(i) += b.vec.at(i);
    }
    balance.curr();
    return balance;
}

bool BigInt::operator<=(const BigInt &b) {
    if(b.vec.size() < vec.size()) 
    {
        return false;
    }
    else if(b.vec.size() > vec.size()) 
    {
        return true;
    }
    else if(b.vec.size() == vec.size())
    {
        for(int i = vec.size() - 1; i >= 0; i--) 
        {
            if(vec.at(i) < b.vec.at(i)) 
            {
                return true;
            }
            else if(vec.at(i) > b.vec.at(i)) 
            {
                return false;
            }
        }
        return true;
    }
    else 
    {
        return false;
    }
}

bool BigInt::operator>(const BigInt &b) {
    if(b.vec.size() > vec.size()) 
    {
        return false;
    }
    else if(b.vec.size() < vec.size()) 
    {
        return true;
    }
    else {
        for(int i = vec.size(); i > 0; i--) 
        {
            if(vec.at(i) > b.vec.at(i)) 
            {
                return true;
            }
            else if(vec.at(i) < b.vec.at(i)) 
            {
                return false;
            }
        }
        return false;
    }
}


void BigInt::curr() {
    bool alternate = false;
    bool start = true;

    while(alternate || start) 
    {

        alternate = false;
        start = false;
        
        for(int i = 0; i < vec.size(); i++) 
        {
            if(vec.at(i) < 0) 
            {
                int diff = 0;
                while(vec.at(i)< 0) 
                {
                    vec.at(i) += 10;
                    diff++;
                }
                while(vec.size() <= i + 1) 
                {
                    vec.push_back(0);
                }
                vec.at(i + 1) -= diff;
            }

            else if(vec.at(i) > 9) 
            {
                while(vec.size() <= (i + 1)) 
                {
                    vec.push_back(0);
                }
                alternate = true;
                vec.at(i + 1) += (vec.at(i) / 10);
                vec.at(i) = (vec.at(i) % 10);

                
            }
        }
    }
}

bool operator<(const BigInt a, const BigInt b) {
    if(b.vec.size() < a.vec.size()) {
        return false;
    }
    else if(b.vec.size() > a.vec.size()) {
        return true;
    }
    else {
        for(int i = a.vec.size(); i > 0; i--) {
            if(a.vec.at(i) < b.vec.at(i)) {
                return true;
            }
            else if(a.vec.at(i) > b.vec.at(i)) {
                return false;
            }
        }
        return false;
    }
}

BigInt::BigInt(const BigInt &b) {
    vec = vector<char>(b.vec);
}

BigInt::operator long() {
    long balance = 0;
    for(int i = 0; i < vec.size(); i++) {
        balance += vec.at(i) * pow(10, i);
    }
    return balance;
}

BigInt::operator string() {
    string balance;
    for(auto i = vec.rbegin(); i < vec.rend(); i++) {
        balance += to_string(*i);
    }
    return balance;
}

ostream &operator<<(ostream &os, const BigInt &temp) {
    BigInt b(temp);
    if(string(b).length() > 12) {
        os << string(b).at(0) << "." << string(b).substr(1, 12) << "e" << string(b).length();
    }
    else {
        os << string(b);
    }
    return os;
}

BigInt::BigInt() {
    vec = vector<char>();
    vec.push_back(0);
}

