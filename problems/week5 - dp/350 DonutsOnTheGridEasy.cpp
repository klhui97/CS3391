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

#define maxn 55
#define maxw 1000
#define INF 0x3f3f3f3f

char grid[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

void mainFunction()
{
	int t;
	int i, j, k, r, c;
	cin >> t;
	for(int c = 1; c <= t; c++){
		int row;
		cin >> row;

		for(i = 0; i < row; i++) {
			cin >> grid[i];
		}
			
		int col = strlen(grid[0]);
		memset(dp, 0, sizeof dp);

		for(int r = 3; r <= row ; r++)
			for (int c = 3; c <= col; c++)
				for(i=0; i+r<row+1;i++)
					for(j=0; j + c < col + 1;j++){
						bool found = true;
						int x = i + r - 1;
						int y = j + c - 1;

						for(k=0; k<c; k++)
							if(grid[i][j+k]!='0'||grid[x][j+k]!='0'){
								found = false;
								break;
							}
						if(found)
							for(k=0; k < r; k++)
								if( grid[i+k][j] !='0' || grid[i+k][y] != '0'){
									found = false;
									break;
								}

						dp[i][j][x][y] = found;
						dp[i][j][x][y] = max(dp[i][j][x][y], dp[i+1][j+1][x-1][y-1] + found);
						dp[i][j][x][y] = max(dp[i][j][x][y], dp[i][j][x-1][y]);
						dp[i][j][x][y] = max(dp[i][j][x][y], dp[i+1][j][x][y]);
						dp[i][j][x][y] = max(dp[i][j][x][y], dp[i][j+1][x][y]);
						dp[i][j][x][y] = max(dp[i][j][x][y], dp[i][j][x][y-1]);
					}
		cout << "Case #" << c << ": " << dp[0][0][row-1][col-1] << "\n";
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
	mainFunction();
	return 0;
}

/****
 * 
 * 
 * 
 * 

5
bertgod god stressed desserts dog
5
no zaphod just very improbable
2
ot to0.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
00000000.0..00
0.00000
0.....0
0000000 * 
 * 
 * sd
 * dsd
 * ***/
