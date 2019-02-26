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
int r[500000];

void mainFunction() {
    int n;
    r[1] = 1;
    for (int i = 2; i <= 500000; i++) {
        if (i % 2) {
            r[i] = (r[i / 2 + 1] - 1) * 2;
        }else {
            r[i] = r[i / 2] * 2;
        }
    }

    while(cin >> n && n) {
        cout << r[n] << endl;
    }
}

int main() {
    mainFunction();
    return 0;
}