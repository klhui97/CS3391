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
#define ull unsigned long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define DUBUG true
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 101
#define maxw 5
#define INF 0x3f3f3f3f

int res[maxn][maxn], maxflow, f, s, t;
vector<vi> adj;
vi p;

int n;

void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

void EdmondKarps() {
	maxflow = 0;
	while (1) {
		f = 0;
		bitset<maxn> visited;
		visited.set(s);
		queue<int> q;
		q.push(s);
		p.assign(maxn, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) adj[u].size(); i++) {
				int v = adj[u][i];
				if (res[u][v] > 0 && !visited.test(v)) {
					visited.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0)
			break;
		maxflow += f;
	}
}

void mainFunction()
{
    int c, cnt = 1;
    int u, v, w;
	while (cin >> n && n) {
		memset(res, 0, sizeof res);
		adj.assign(n, vi());

		cin >> s >> t >> c;
		s--;
		t--;

		for (int i = 0; i < c; i++) {
			cin >> u >> v >> w;
			u--;
			v--;
			res[u][v] += w;
            adj[u].push_back(v);
			res[v][u] += w;
			adj[v].push_back(u);
		}

		EdmondKarps();

		cout << "Network " << cnt++;
        cout << "\nThe bandwidth is " << maxflow << ".\n\n";
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