#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

char str[200];
string data[200 * 5000];

void mainFunction() {
    bool prevIsChar;
    int index =- 1;
    
    while(gets(str)) {
        prevIsChar = false;
        for(int i = 0; str[i] != '\0'; i++) { // [handle lower case]
            
            if (str[i] >= 97 && str[i] <= 122) {
                if (prevIsChar) {
                    data[index] = data[index] + str[i];
                }else {
                    index++;
                    data[index] = str[i];
                    prevIsChar = true;
                }
            }else if (str[i] >= 65 && str[i] <= 90) { // [handle lower case]
                str[i] = str[i] + 32;
                if(prevIsChar) {
                    data[index] = data[index] + str[i];
                }else {
                    index++;
                    data[index] = str[i];
                    prevIsChar = true;
                }
            }else {
                prevIsChar = false;
            }
        }
    }
    
    sort(data, data + index + 1);
    cout << data[0] << endl;
    
    for (int i = 1; i <= index; i++) {
        if (data[i] != data[i-1]) {
            cout << data[i] << endl;
        }
    }
}

int main() {
    mainFunction();
    return 0;
}
