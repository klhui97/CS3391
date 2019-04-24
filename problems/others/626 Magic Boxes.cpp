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

int a[25];
int dp[1001000] = { 0 };

void mainFunction()
{
	int n, m;
	while(cin >> n >> m && cin){
		int cnt = 0;
		for (int i = 0; pow(m, i) <= n; i++) {
			a[i] = pow(m, i);
			cnt++;
		}
		memset(dp, 0, sizeof dp);
		dp[0] = 1;
		for (int i = 0; i < cnt; ++i)
		{
			for (int j = a[i]; j <= n; ++j) {
				dp[j] += dp[j - a[i]];
				dp[j] %= 1000000007;
			}
		}
		cout << dp[n] << endl;
		memset(dp, 0, sizeof(dp));
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