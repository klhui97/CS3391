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

#define maxn 10
#define maxw 5
#define INF 0x3f3f3f3f

void mainFunction()
{
	ull s, e;
	ull sum[64];
	bool used[64];
	for (int i = 0; i < 64; i++) {
		sum[i] = pow(2, i);
		// $(sum[i]);
	}
	while(scanf("%lld %lld", &s, &e) == 2){
		memset(used, false, sizeof used);
		ull x = 0;
		for (int i = 63; i >= 0; i--) {
			if (x + sum[i] <= s) {
				x += sum[i];
				used[i] = true;
				// $(sum[i]);
			}
		}
		ull result = s;
		for (int i = 0; i < 64 & result < e; i++) {
			if (used[i] == false) {
				result += sum[i];
				// $(result);
				used[i] = true;
			}
		}
		// $(x);
		// $(s);
		// $(e);
		cout << result << "\n";
	}
	
}

void testCaseGenerator()
{
	int d[24];
	for (int i = 1; i < 25; i++)
	{
		d[i - 1] = i;
	}
	for (int i = 0; i < 100; i++)
	{
		// random_shuffle(begin(d), end(d));
		cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << int(rand() % 24 + 1) << "\n";
	}
}

int main()
{
	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}