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
#define maxn 1001
#define maxw 5

void mainFunction()
{
	int n;
	int i, j;
	int times[maxn];
	int cur_year;
	int year[maxn];
	char sign[maxn];
	char dp[maxn];
	while(scanf("%d\n", &n) && n != 0){
		int mm, dd, HH, MM;
        for (int i = 0; i < n; i++) {
            scanf("%d:%d:%d:%d %*s %s", &mm, &dd, &HH, &MM, &sign[i]);
            times[i] = ((mm * 31 + dd) * 24 + HH) * 60 + MM;
			// cout << times[i] << " " << remain[i] << endl;
        }
		memset(dp, 0, sizeof 0);
		year[0] = 0;
		for (i = 1; i < n; i++) {
			if (times[i] > times[i - 1]) {
				year[i] = year[i - 1];
			}else {
				year[i] = year[i - 1] + 1;
			}
		}

		for (i = 0; i < n; i++) {
			cur_year = year[i];
			for (j = i + 1; j < n && year[j] == cur_year; j++) {

			}
			
		}
		
		int count = 0;
		for (i = 0; i < n; i++) {
			if (!deleted[i])
				count++;
		}
		cout << count << endl;
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