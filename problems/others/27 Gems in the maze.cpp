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
int r[300];
int a, b, c, n;

int count(int cur) {
    int next = (a * cur * cur + b * cur + c) % n;
    if (r[cur] == 0) {
        return 0;
    }
    r[cur] = 0;
    return 1 + count(next);
}

void mainFunction() {
    int N;
    cin >> N;

    while(N--) {
        cin.ignore();
        
        cin >> a >> b >> c >> n;
        int i;
        
        
        i = 0;
        int result = 0;
        while (i < n) {
            for (int j = 0; j < n; j++)
                r[j] = 1;
            
            result = max(result, count(i));
            i++;
        }
        cout << result << endl;
    }
}

int main() {
    mainFunction();
    return 0;
}