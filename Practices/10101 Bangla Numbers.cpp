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

string solve(ull x) {
	string ans = "";
	if (x < 100 && x)
		return to_string(x);
	if (x / 10000000 > 0) {
		ans = solve(x / 10000000) + " kuti";
		x -= x / 10000000 * 10000000;
		if (x)
			ans += " ";
	}
	if (x / 100000 > 0) {
		ans += to_string(x / 100000) + " lakh";
		x -= x / 100000 * 100000;
		if (x)
			ans += " ";
	}
	if (x / 1000 > 0) {
		ans += to_string(x / 1000) + " hajar";
		x -= x / 1000 * 1000;
		if (x)
			ans += " ";
	}
	if (x / 100 > 0) {
		ans += to_string(x / 100) + " shata";
		x -= x / 100 * 100;
		if (x) {
			ans += " " + to_string(x);
			x = 0;
		}
	}
	if (x > 0) {
		ans += to_string(x);
	}
	return ans;
}

void mainFunction()
{
	ull x;
	int cnt = 1;
	while (cin >> x && cin)
	{
		printf( "%4d. ", cnt++);
		if (x != 0)
			cout << solve(x) << "\n";
		else
			cout << "0\n";
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