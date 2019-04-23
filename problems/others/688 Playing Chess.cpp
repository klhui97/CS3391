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

#define maxn 8
#define maxw 1000
#define INF 0x3f3f3f3f

char graph[8][8];
int xs, ys, xe, ye;

struct node {
    int x, y;
    int distance;

    node(int x, int y, int distance) :x(x), y(y), distance(distance) {};
};

int bfs()
{
	bool visited[8][8];
    memset(visited, false, sizeof visited);
	int steps[8][8];
	int movex[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int movey[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    memset(steps, INF, sizeof steps);

    list<node> queue;
    queue.push_back(node(xs, ys, 0));
	steps[xs][ys] = 0;
	visited[xs][ys] = true;

	int ans = INF;
    list<int>::iterator i;

    while (!queue.empty())
    {
        int x = queue.front().x;
		int y = queue.front().y;
        int d = queue.front().distance;
        queue.pop_front();
		if (x == xe && y == ye) {
			ans = min(ans, d);
		}

		for (int k = 0; k < 8; k++) {
			int newx = x + movex[k];
			int newy = y + movey[k];
			if (newx >= 0 && newx < 8 && newy >= 0 && newy < 8 && graph[newx][newy] != '*') {
				if (newx == xe && newy == ye) {
					return d + 1;
				}
				 if (!visited[newx][newy]) {
					visited[newx][newy] = true;
					queue.push_back(node(newx, newy, d + 1));
				}
			}
		}
    }
	return ans;
}

void mainFunction()
{
	int t;
	scanf("%d\n", &t);
	char input[15];
	for (int c = 1; c <= t; c++) {
		xs = ys = xe = ye = -1;
		for (int i = 0; i < 8; i++) {
			gets(input);
			assert(strlen(input) == 8);
			for (int j = 0; j < 8; j++) {
				graph[i][j] = input[j];
				if (input[j] == '#')
					xs = i, ys = j;
				else if (input[j] == '@')
					xe = i, ye = j;
			}
		}

		int dis = bfs();
		if (dis != INF)
			printf("Case %d: %d\n", c, dis);
		else
			printf("Case %d: IMPOSSIBLE\n", c);

		gets(input);
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