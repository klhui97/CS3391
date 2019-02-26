#include <iostream>
#include <string.h>

using namespace std;

const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";

int getIndex(char value) {
    
    int intValue = int(value);
    
    if (intValue <= 57) {
        return intValue - 48 + 25;
    }else {
        return intValue - 65;
    }
    
    return 0;
}

int main() {
    char s[20];
    
    while(scanf("%s", s) == 1) {
        unsigned long len = strlen(s);
        
        unsigned long start = 0;
        unsigned long end = len - 1;
        int state = 2;
        
        while (start < (len + 1 / 2)) {
            
            if (state == 2) {
                if (s[start] != s[end] || rev[getIndex(s[start])] != s[end]) {
                    state--;
                }
                
                start++;
                end--;
                continue;
            }
            
            if (state == 1) {
                if (s[start] != s[end]) {
                    state--;
                }
                
                start++;
                end--;
                continue;
            }
            
            if (state == 0) {
                if (rev[getIndex(s[start])] != s[end]) {
                    state--;
                }
                
                start++;
                end--;
                continue;
            }
            
            break;
        }
        
        cout << s << " -- ";
        if (state == 2) {
            cout << "is a mirrored palindrome.";
        }else if (state == 1) {
            cout << "is a regular palindrome.";
        }else if (state == 0) {
            cout << "is a mirrored string.";
        }else {
            cout << "is not a palindrome.";
        }
        
        cout << endl << endl;
    }
    return 0;
}
