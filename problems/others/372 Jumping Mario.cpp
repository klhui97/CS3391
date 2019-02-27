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
#define $(x) {cout << #x << " = " << x << " " << endl;}

#define maxn 2000 + 1
#define maxw 5
#define INF 0x3f3f3f3f

void mainFunction()
{
	int t, w, prev;
	int now;
	int high, low;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		high = 0;
		low = 0;
		cin >> w >> prev;
		while(--w){
			cin >> now;
			if (now < prev)
				low++;
			else if (now > prev)
				high++;
			prev = now;
		}
		printf("Case %d: %d %d\n", i, high, low);
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