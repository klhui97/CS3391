#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>

using namespace std;
int scroe[1000];

void mainFunction() {
    int N;
    cin >> N;

    while(N--){
        int students;
        cin >> students;
        int i = 0;
        int total = 0;
        while(i < students){
            cin >> scroe[i];
            total += scroe[i];
            i++;
        }
        int pass = 0;
        double avg = total / students;

        i = 0;
        while(i < students){
            if (scroe[i] > avg) {
                pass++;
            }
            i++;
        }
        cout << fixed << setprecision(3) << pass * 1.0 / students * 1.0 * 100 << "%" << endl;
    }
    
}

int main() {
    mainFunction();
    return 0;
}
