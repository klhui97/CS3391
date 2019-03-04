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
using namespace std;
#define DUBUG true
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << endl;}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 10
#define maxw 5
#define INF 0x3f3f3f3f
int target;
int dp[21];
int x;

bool search(int completed, int sum, int start, bool used[]) {

	if (completed == 3)
		return true;
	
	if (sum == target)
		return search(completed + 1, 0, 0, used);

	for (int i = start; i < x; i++) {
		if (used[i] == false && dp[i] + sum <= target) {
			used[i] = true;
			if (search(completed, dp[i] + sum, i + 1, used))
				return true;
			used[i] = false;
		}
	}
	return false;
}

bool compare(int a, int b) {
	return a > b;
}

void mainFunction()
{
	int t;
	int i;
	int sum;
	bool used[21];
	cin >> t;
	for (i = 1; i <= t; i++) {
		sum = 0;
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> dp[j];
			sum += dp[j];
		}
		sort(dp, dp + x, compare);
		// $(dp[0]);
		cout << "Case #" << i << ": ";
		if (sum % 4 == 0) {
			target = sum / 4;
			memset(used, false, sizeof used);
			if (search(0, 0, 0, used)) {
				cout << "yes" << endl;
				continue;
			}
		}
		cout << "no" << endl;
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
		cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << int(rand() % 24 + 1) << endl;
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