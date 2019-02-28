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

#define maxn 101
#define maxw 5
#define INF 0x3f3f3f3f

void mainFunction()
{
	int nodes[maxn][maxn];
	int n, m;
	int i, j, k;
	while(cin >> n >> m){
		memset(nodes, -1, sizeof nodes);

		while(m--){
			cin >> i >> j >> k;
			nodes[i][j] = k;
			nodes[j][i] = k;
		}
		
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++) {
					if (nodes[i][k] != -1 && nodes[k][j] != -1) {
						if (nodes[i][j] == -1)
							nodes[i][j] = nodes[i][k] + nodes[k][j];
						else
							nodes[i][j] = min(nodes[i][j], nodes[i][k] + nodes[k][j]);
					}
				}

		int minInx;
		int minDis;
		for (i = 1; i <= n; i++) {
			int dis = 0;
			for (j = 1; j <= n; j++) {
				if (i != j) {
					dis += nodes[i][j];
				}
			}
			if (i == 1) {
				minInx = 1;
				minDis = dis;
			}else if (dis < minDis) {
				minInx = i;
				minDis = dis;
			}
		}
		cout << minInx << endl;
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