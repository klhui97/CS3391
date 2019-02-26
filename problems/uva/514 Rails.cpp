#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int order[1001];
    int n;
    int i = 0;
    
    while (scanf("%d", &n) && n) {
        int first;
        while (scanf("%d", &first) && first) {
            stack<int> s;
            order[0] = first;
            for (i = 1; i < n; i++) {
                scanf("%d", &order[i]);
            }
            
            int tNum = 1;
            bool isOk = true;
            i = 0;
            while (i < n && tNum <= n && isOk) {
                if (order[i] == tNum) {
                    i++;
                    tNum++;
                }else if (!s.empty() && s.top() == order[i]) {
                    s.pop();
                    i++;
                }else if (tNum > order[i]) {
                    isOk = false;
                }else {
                    s.push(tNum);
                    tNum++;
                }
            }
            
            while (i < n && isOk && !s.empty()) {
                if (order[i++] == s.top()) {
                    s.pop();
                }else {
                    isOk = false;
                }
            }
            
            if (isOk) {
                cout << "Yes" << endl;
            }else {
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
    
    
    return 0;
}
