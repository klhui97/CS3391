#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <iomanip>

using namespace std;

bool balance(int &w) {
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    
    if (wl != 0 && wr !=0) {
        w = wl + wr;
        return wl * dl == wr * dr;
    }else if (wl == 0 && wr == 0) {
        int weightL;
        int weightR;
        bool bL = balance(weightL);
        bool bR = balance(weightR);
        if (bL && bR) {
            w = weightL + weightR;
            return weightL * dl == weightR * dr;
        }else {
            return false;
        }
    }else if (wl == 0) {
        int weightL;
        if (balance(weightL)) {
            w = weightL + wr;
            return weightL * dl == wr * dr;
        }else {
            return false;
        }
    }else { // wr == 0
        int weightR;
        if (balance(weightR)) {
            w = weightR + wl;
            return weightR * dr == wl * dl;
        }else {
            return false;
        }
    }
}

void mainFunction() {
    int N;
    cin >> N;

    while(N--) {
        cin.ignore();
        int weight = 0;
        if (balance(weight)) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
        if (N)
            cout << endl;
    }
}

int main() {
    mainFunction();
    return 0;
}