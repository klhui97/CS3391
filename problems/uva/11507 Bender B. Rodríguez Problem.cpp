#include <iostream>
#include <string>

using namespace std;

string temp, name, bestName;

int main() {
    int n;
    
    while (~scanf("%d", &n) && n) {
        string lastDirection = "+x";
        string input;
        while (--n > 0) {
            cin >> input;
            
            if (input.compare("No") == 0) {
                continue;
            }
            
            if (lastDirection[1] == 'z') {
                // case last direction = z
                if (input[1] == 'z') {
                    if (input[0] == '+') {
                        if (lastDirection[0] == '-'){
                            lastDirection[0] = '+';
                        }else {
                            lastDirection[0] = '-';
                        }
                    }
                    lastDirection[1] = 'x';
                }
            }else if (lastDirection[1] == 'y') {
                // case last direction = y
                if (input[1] != 'z' && input.compare("+x") != 0) {
                    if (input.compare("-y") != 0) {
                        if (lastDirection[0] == '-'){
                            lastDirection[0] = '+';
                        }else {
                            lastDirection[0] = '-';
                        }
                    }
                    lastDirection[1] = 'x';
                }
            }else if (lastDirection[1] == 'x') {
                // case last direction = x
                if (input[1] != 'z') {
                    // x or y
                    if (input.compare("-y") == 0) {
                        if (lastDirection[0] == '-'){
                            lastDirection[0] = '+';
                        }else {
                            lastDirection[0] = '-';
                        }
                    }
                    lastDirection[1] = 'y';
                }else {
                    // z
                    if (input[0] == '-') {
                        if (lastDirection[0] == '-'){
                            lastDirection[0] = '+';
                        }else {
                            lastDirection[0] = '-';
                        }
                    }
                    lastDirection[1] = 'z';
                }
            }
        }
        cout << lastDirection << endl;
    }
    return 0;
}
