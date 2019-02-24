#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int weight(char &c) {
    if (c == '-' || c == '+') {
        return 1;
    }else if (c == '*' || c == '/') {
        return 2;
    }else {
        return 0;
    }
}

void mainFunction() {
    int N;
    cin >> N;
    cin.ignore();
    cin.ignore();
    
    while (N--) {
        string line;
        stack<char> s;
        char ans[51];
        int cnt = 0;
        
        while (true) {
            getline(cin, line);
            
            if (line.length() == 0 || !cin) {
                break;
            }
            
            char c = line[0];
            
            if (isdigit(c)) {
                ans[cnt++] = c;
            }else if (c == ')') {
                while (s.top() != '(') {
                    ans[cnt++] = s.top();
                    s.pop();
                }
                s.pop();
            }else if (c == '(') {
                s.push(c);
            }else {
                // operators
                if (s.empty()) {
                    s.push(c);
                }else {
                    while (!s.empty() && weight(s.top()) >= weight(c)) {
                        ans[cnt++] = s.top();
                        s.pop();
                    }
                    s.push(c);
                }
            }
        }

        while (!s.empty()) {
            ans[cnt++] = s.top();
            s.pop();
        }
        ans[cnt] = '\0';
        if (N == 0) {
            cout << ans << endl;
        }else {
            cout << ans << endl << endl;
        }
        
    }
}

int main() {
    mainFunction();
    return 0;
}
