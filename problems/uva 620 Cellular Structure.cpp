/*** System Library ***/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib> // random
#include<ctime>
#include<climits> // all useful constants
#include<functional> // for hash
#include<algorithm>
#include<sstream>

/*** Data Structure ***/
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<deque> // double ended queue
#include<list> // priority queue
using namespace std;

bool isValid(string s, int start, int end) {
    if (start == end && s[start] == 'A') {
        return true;
    }else if (end - start == 1 && s[start] == 'A' && s[end] == 'B') {
        return true;
    }else {
        if (s[end - 1] == 'A' && s[end] == 'B') {
            if (isValid(s, start, end - 2)) {
                return true;
            }
        }
        if (s[start] == 'B' && s[end] == 'A') {
            if (isValid(s, start + 1, end - 1)) {
                return true;
            }
        }
    }
    return false;
}

void mainFunction() {
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        if (s.size() % 2 == 0) {
            cout << "MUTANT" << endl;
            continue;
        }
        if (s.compare("A") == 0) {
            cout << "SIMPLE" << endl;
            continue;
        }else {
            if (s[s.size() - 2] == 'A' && s[s.size() - 1] == 'B') {
                if (isValid(s, 0, s.size() - 3)) {
                    cout << "FULLY-GROWN" << endl;
                    continue;
                }
            }else if (s[0] == 'B' && s[s.size() - 1] == 'A') {
                if (isValid(s, 1, s.size() - 2)) {
                    cout << "MUTAGENIC" << endl;
                    continue;
                }
            }
        }
        cout << "MUTANT" << endl;
    }
}

void testCaseGenerator() {
    int d[24];
    for (int i = 1; i < 25; i++) {
        d[i - 1] = i;
    }
    for (int i = 0; i < 100; i++) {
        // random_shuffle(begin(d), end(d));
        cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << int(rand() % 24 + 1) << endl;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // testCaseGenerator();
    mainFunction();
    return 0;
}