// #include <bits/stdc++.h> // all

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

ll gcde(ll a, ll b)
{
    // Base Case
    if (a == 0)
    {
        return b;
    }

    ll gcd = gcde(b%a, a);

    return gcd;
}

ll toi(char *a) {
	int len = strlen(a);
	ll s = 0;
	for (int i = 0; i < len; i++) {
		s <<= 1;
		s += a[i] - '0';
	}
	return s;
}

void mainFunction()
{
	char a[35];
	int t;
	cin >> t;
	int c = 1;
	getchar();
	while (t--)
	{
		gets(a);
		ll x = toi(a);
		// $(x);
		gets(a);
		ll y = toi(a);
		cout << "Pair #" << c++ << ": ";
		ll gcd = gcde(x, y) == 1;
		if (gcd != 1) {
			cout << "All you need is love!\n";
		}else {
			cout << "Love is not all you need!\n";
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