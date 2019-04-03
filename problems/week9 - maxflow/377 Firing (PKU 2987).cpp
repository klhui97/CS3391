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

#define maxn 60000 * 2 + 5000 * 2 + 100
#define maxw 10
#define INF 0x3f3f3f3f

int cnt;
#define INTT long long
struct Edge {
	int v;     // edge (u->v)
	INTT c;  // edge cacity (w)
	int nxt;  // the next edge connected by node u.
};
int edges;
Edge edge[maxn];
int d[maxn], visited[maxn];
int f[maxn], h[maxn];

void addEdge(int u, int v, INTT c) {
	edge[edges].nxt = h[u];
	edge[edges].v = v;
	edge[edges].c = c;
	h[u] = edges;
	edges++;
}
void init() {
	edges = 0;
	memset(h, -1, sizeof(h));
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
	cnt = 0;
	INTT ans = 0;
	while (bfs(s, t))
		ans += dinic(s, t, INF);
	return ans;
}

// dfs 
void dfs(int u) {
	cnt++;
	visited[u] = 1;
	int v;
	for (int e = h[u]; e != -1; e = edge[e].nxt) {
		v = edge[e].v;
		if (edge[e].c - f[e]>0 && !visited[v]) {
			dfs(v);
		}
	}
}

void mainFunction()
{
	int sum, ans;
	int n, m;
	while (cin >> n >> m && cin) {                                                            
		
		int i, j, a, b, c;
		sum = 0;
		ans = 0;
		memset(f, 0, sizeof(f));
		memset(visited, 0, sizeof(visited));

		init();
		int start = 2 * n, end = 2 * n + 1;
		for (i = 0; i < n; i++) {
			cin >> c;
			if (c > 0) {
				addEdge(i, start, 0);
				addEdge(start, i, c);
				sum += c;
			}else if(c < 0){
				addEdge(i, end, -c);
				addEdge(end, i, 0);
			}
			
		}
		for (i = 0; i < m; i++) {
			cin >> a >> b;
			addEdge(a - 1, b - 1, INF);
			addEdge(b - 1, a - 1, 0);
		}
		INTT flow = maxFlow(start, end);
		ans = sum - flow;
		dfs(start);
		cout << cnt - 1 << " " << ans << "\n";
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
		cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << int(rand() % 24 + 1) << "\n";
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