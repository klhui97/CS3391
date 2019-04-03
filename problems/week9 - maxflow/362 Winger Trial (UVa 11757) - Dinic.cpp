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

#define maxn 1000000
#define maxw 5
#define INF 0x3f3f3f3f

#define INTT int
struct Edge {
	int v;     // edge (u->v)
	INTT c;  // edge cacity (w)
	int nxt;  // the next edge connected by node u.
};
int edges;
Edge edge[maxn];
int d[maxn];
int f[maxn], h[maxn];

void addEdge(int u, int v, INTT c) {
	edge[edges].nxt = h[u];
	edge[edges].v = v;
	edge[edges].c = c;
	h[u] = edges;
	edges++;
	edge[edges].nxt = h[v];
	edge[edges].v = u;
	edge[edges].c = 0;
	h[v] = edges;
	edges++;
}

void init() {
	edges = 0;
	memset(h, -1, sizeof(h));
	memset(f, 0, sizeof(f));
}

bool bfs(int S, int T) {
	int u, v;
	memset(d, -1, sizeof(d));
	queue<int> Q;
	while (!Q.empty())
		Q.pop();
	Q.push(S);
	d[S] = 0;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int e = h[u]; e != -1; e = edge[e].nxt) {
			v = edge[e].v;

			if ((d[v] == -1) && edge[e].c > f[e]) {
				d[v] = d[u] + 1;
				Q.push(v);
			}
		}
	}
	return d[T] >= 0;
}

INTT dinic(int u, int T, INTT sum) {
	if (u == T) 
		return sum;
	int v, tp = sum;
	for (int e = h[u]; e != -1 && sum; e = edge[e].nxt) {
		v = edge[e].v;
		if (d[v] == d[u] + 1 && edge[e].c>f[e]) {
			ll toflow = dinic(v, T, min(sum, edge[e].c - f[e]));
			f[e] += toflow;
			f[e ^ 1] -= toflow;
			sum -= toflow;
		}
	}
	return tp - sum;
}

INTT maxFlow(int s, int t) {
	INTT ans = 0;
	while (bfs(s, t))
		ans += dinic(s, t, INF);
	return ans;
}

void mainFunction()
{
	int cnt = 1;
	int L, W, N, d, x, y;
	int s, t;
	int corX[maxn];
	int corY[maxn];
	while(cin >> L >> W >> N >> d && L){
		memset(corX, 0, sizeof corX);
		memset(corY, 0, sizeof corY);
		init();
		int n = N * 2 + 2;
		s = 0;
		t = n - 1;

		for (int i = 1; i <= N; i++) {
			cin >> corX[i] >> corY[i];
			addEdge(i, i + N, 1);
			if (corY[i] - d <= 0)
				addEdge(s, i, 1);
			if (corY[i] + d >= W)
				addEdge(i + N, t, 1);
			for (int j = 1; j < i; j++) {
				if ((corX[i] - corX[j]) * (corX[i] - corX[j]) + (corY[i] - corY[j]) * (corY[i] - corY[j]) <= 4 * d * d) {
					addEdge(i + N, j, 1);
					addEdge(j + N, i, 1);
				}
			}
		}
		cout << "Case " << cnt++ << ": " << maxFlow(s, t) << "\n";
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