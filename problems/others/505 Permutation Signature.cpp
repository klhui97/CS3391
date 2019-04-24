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

int V;
char str[51];
int dp[60];

void swap(int *a, int l, int r) {
    int tmp = a[l];
    a[l] = a[r];
    a[r] = tmp;
}

void mainFunction()
{
    int t = 1;
    int n;
    while(cin >> str && cin) {
        cout << "Case #" << t++ << ": ";
        V = strlen(str);
        
        for (int i = 0; i <= V; i++) {
            dp[i] = i + 1;
        }
        for (int i = 0; i <= V; i++) {
            for (int j = i; j > 0 && str[j - 1] == 'D'; j--) {
				swap(dp, j - 1, j);
			}
        }
        for (int i = 0; i <= V; i++) {
            cout << dp[i];
			if (i < V)
				cout << " ";
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