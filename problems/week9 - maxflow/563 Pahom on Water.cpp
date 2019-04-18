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

#define maxn 1005
#define maxw 60000 * 2 + 5000 * 2 + 100
#define INF 0x3f3f3f3f

#define INTT long long
struct Edge {
	int v;     // edge (u->v)
	INTT c;  // edge cacity (w)
	int nxt;  // the next edge connected by node u.
};
int edges;
Edge edge[maxw];
int d[maxn];
int f[maxw], h[maxw];

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

// dfs, find vertexs that haven't flowout
int cnt;
int visited[maxn];
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
    int n, T;
    cin >> T;
    while(T--) {
        init();
        int st, ed;
		int x[maxn], y[maxn], r[maxn];
		double fq[maxn];
        cin >> n;
        for(int i = 1; i <= n; ++i) {
			cin >> fq[i] >> x[i] >> y[i] >> r[i];
            if (fq[i] == 789.0)
				ed = i;
            else if(fq[i] == 400.0)
				st = i;
            for(int j = 1; j < i; ++j) {
                if((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) < (r[i] + r[j]) * (r[i] + r[j])) {
                    if(fq[i] < fq[j]) addEdge(i, j, 1);
                    if(fq[i] > fq[j]) addEdge(j, i, 1);
                }
            }
        }
        if(maxFlow(st, ed) <= 1)
			cout << "Game is NOT VALID\n";
        else
			cout << "Game is VALID\n";
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
	// cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}