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

#define maxn 105
#define maxw 5
#define INF 0x3f3f3f3f

int res[maxn][maxn], maxflow, f, ss, tt;
vector<vi> adj;
vi p;

int n;

void augment(int v, int minEdge) {
    if (v == ss) {
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
        visited.set(ss);
        queue<int> q;
        q.push(ss);
        p.assign(maxn, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == tt)
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
        augment(tt, INF);
        if (f == 0)
            break;
        maxflow += f;
    }
}

void addEdge(int v, int u, int w) {
    res[v][u] += w;
    adj[v].push_back(u);
}

void init(int n) {
	memset(res, 0, sizeof res);
	adj.assign(n, vi());
}

void mainFunction()
{
	int c;
	int cnt = 1;
    int u, v, w;
	while (cin >> n && n) {
		cin >> ss >> tt >> c;
		ss--;
		tt--;
		init(n);

		for (int i = 0; i < c; i++) {
			cin >> v >> u >> w;
			v--;
			u--;
			addEdge(v, u, w);
			addEdge(u, v, w);
		}

		EdmondKarps();
		cout << "Network " << cnt++;
        cout << "\nThe bandwidth is " << maxflow << ".\n\n";
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