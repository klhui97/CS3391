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

int cnt(int a) {
	if (a < 10)
		return 0;
	int sum = 0;
	while (a > 0)
	{
		int d = a % 10;
		sum += (d * d);
		a /= 10;
	}
	return sum;
}
void mainFunction()
{
	int t;
	cin >> t;
	int n;
	int on;
	for (int c = 1; c <= t; c++) {
		cin >> n;
		bool good = false;
		on = n;
		if (n == 1) {
			good = true;
			n = 0;
		}
		while (n != 0)
		{
			n = cnt(n);
			if (on == n) {
				good = false;
				break;
			}
			if (n == 1) {
				good = true;
				break;
			}
		}
		if (good) {
			cout << "Case #" << c << ": " << on << " is a Happy number.\n";
		}else {
			cout << "Case #" << c << ": " << on << " is an Unhappy number.\n";
		}
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
	mainFunction();
	return 0;
}