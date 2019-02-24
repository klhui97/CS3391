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

void mainFunction() {
    int t, n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    while(t--) {
        cin >> n;
        if (n <= 2) {
            cout << 0 << endl;
        }else {
            cout << n - 2 << endl;
        }
    }
    
}

int main() {
    // freopen("in.txt", "r", stdin);
    mainFunction();
    return 0;
}