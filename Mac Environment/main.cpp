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
#define N 25
void mainFunction() {
    
    int result[N];
    int c1, c2, c3, c4, t;
    while (cin >> c1 >> c2 >> c3 >> c4 >> t) {
        if (t < c1 && t < c2 && t < c3 && t < c4) {
            cout << -1 << endl;
            continue;
        }
        
    }
    
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mainFunction();
    return 0;
}