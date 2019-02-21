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