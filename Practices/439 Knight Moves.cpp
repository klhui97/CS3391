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
	if (xs == xe && ys == ye) {
		return 0;
	}
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
	char from[5], to[5];
	while(cin>>from>>to){
		int ans = 0;
		
		xs = from[0] - 'a';
		ys = from[1] - '0' - 1;
		xe = to[0] - 'a';
		ye = to[1] - '0' - 1;
		// _(xs);
		// _(ys);
		// _(xe);
		// _(ye);

		int dis = bfs();
		printf("To get from %s to %s takes %d knight moves.\n", from, to, dis);
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