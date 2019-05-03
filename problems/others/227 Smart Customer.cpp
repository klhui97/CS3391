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

void mainFunction()
{
	double dp[105];
	double p;
	int n, x;
	int c = 1;
	string s;
	while(cin >> p >> n && cin){
		for (int i = 0; i <= 100; i++) {
			dp[i] = i * p;
		}
		for (int i = 1; i <= n; i++) {
			cin >> x >> p;
			dp[x] = min(dp[x], p);
		}
		getchar();
		getline(cin, s);
		for (int i = 0; i <= 100; i++) {
			for(int j = i; j >= 2 && j >= i/2; j--) {
				dp[i] = min(dp[i], dp[j-1] + dp[i-(j-1)]);
			}
		}
		cout << "Case " << c++ << ":\n";
		
		stringstream ss(s);
		while(ss >> n) {
			cout << "Buy " << n << " for $";
			cout << fixed << setprecision(2) << dp[n] << "\n";
		}
	}
	
}

int main()
{
	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	mainFunction();
	return 0;
}