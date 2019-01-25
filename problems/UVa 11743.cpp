#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>

using namespace std;

void mainFunction()
{
    int N;
    cin >> N;
    cin.ignore();

    while(N--){
        char line[20];
        int x = 0;
        int y = 0;
        char *ptr;

        cin.getline(line, 20);
        ptr = strtok(line, " ");
        
        while(ptr){
            int x1 = (ptr[0] - 48) * 2;
            int x2 = (ptr[2] - 48) * 2;
            if (x1 > 9) {
                x1 = 1 + (x1 % 10);
            }
            if (x2 > 9) {
                x2 = 1 + (x2 % 10);
            }
            x = x + x1 + x2;
            y = y + ptr[1] + ptr[3] - 96;
            ptr = strtok(NULL, " ");
        }

        if ((x + y) % 10 == 0) {
            cout << "Valid" << endl;
        }else {
            cout << "Invalid" << endl;
        }
    }
    
}

int main()
{
    mainFunction();
    return 0;
}