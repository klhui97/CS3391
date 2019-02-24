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

/*** Data Structure ***/
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <deque> // double ended queue
#include <list>  // priority queue
#include <map>
using namespace std;
#define maxn 1001
#define maxw 31

void mainFunction()
{
	int t, object_num, person_num, sum, tmp;
	int i, j;
	int p[maxn], w[maxn];
	int dp[maxw];

	cin >> t;
	while (t--)
	{
		cin >> object_num;
		for (i = 0; i < object_num; i++)
		{
			cin >> p[i] >> w[i];
		}
		
		// dp
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < object_num; i++)
		{
			for (int j = 30; j >= w[i]; j--)
				dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
		}

		// Read person
		sum = 0;
		cin >> person_num;
		while (person_num--)
		{
			cin >> tmp;
			sum += dp[tmp];
		}
		cout << sum << endl;
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
	cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}