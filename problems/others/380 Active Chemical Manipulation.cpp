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
#define DUBUG false
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << endl;}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 1000 + 1
#define maxw 5
#define INF 0x3f3f3f3f

void mainFunction()
{
	int node[maxn][maxn];
	int N;
	int i, j, k;
	while(cin >> N && !cin.eof()){
		memset(node, 0, sizeof node);
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				cin >> node[i][j];
			}

		for (k = 0; k < N; k++)
			for (i = 0; i < N; i++)
				for (j = 0; j < N; j++) {
					node[i][j] = min(node[i][j], node[i][k] + node[k][j]);
				}
		
		for (i = 0; i < N; i++) {
			sort(node[i], node[i] + N);
			if (N % 2 == 1) {
				cout << (double) node[i][N/2] << endl;
			}else {
				cout << (double) (node[i][N/2] + node[i][N/2-1])/2 << endl;
			}
		}
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