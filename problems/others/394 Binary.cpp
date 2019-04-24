/*** System Library ***/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib> // random
#include <ctime>
#include <climits>	// all useful constants
#include <functional> // for hash
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <regex>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*** Data Structure ***/
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <deque> // double ended queue
#include <list>  // priority queue
#include <map>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define DUBUG true
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 1000
#define maxw 1000
#define INF 0x3f3f3f3f

int dp[17];
bool used[17];

void mainFunction()
{
    for (int i = 0; i <= 16; i++) {
        dp[i] = pow(2, i);
    }
    int maxx;
    int n;
    while(cin >> n && cin) {
        memset(used, false, sizeof used);
        maxx = 0;
        for (int i = 16; i >= 0; i--) {
            if (n >= dp[i]) {
                n -= dp[i];
                used[i] = true;
                maxx = max(maxx, i);
            }
        }
        for (int i = maxx; i >= 0; i--) {
            // $(dp[i]);
            if (used[i])
                cout << "1";
            else
                cout << "0";
        }
        cout << "\n";
    }
}

int main()
{
	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mainFunction();
	return 0;
}