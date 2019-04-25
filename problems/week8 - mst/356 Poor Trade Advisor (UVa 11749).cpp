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
#define DUBUG true
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 501
#define maxw 5
#define INF 0x3f3f3f3f
typedef  pair<int, int> iPair;
int V, E;

struct edge {
    int v, u, w;

    edge(int v, int u, int w) :v(v), u(u), w(w) {};

    bool operator < (const edge n2) const {
        return w > n2.w;
    }
};

priority_queue<edge> pq;

void addEdge(int u, int v, int w)
{
    pq.push(edge(u, v, w));
}

struct DisjointSets
{
    int *parent, *rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        reset();
    }

    void reset() {
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

int kruskalMST()
{
    DisjointSets ds(V);
	int v, u, w;
    int mx;
	for (int i = 0; i < E; i++) {
		cin >> v >> u >> w;
        if (i == 0) {
            mx = w;
            ds.merge(v, u);
        }else if (w < mx) {
            continue;
        }else if (w > mx) {
            ds.reset();
            mx = w;
            ds.merge(v, u);
        }else {
            int set_u = ds.find(u);
            int set_v = ds.find(v);

            if (set_u != set_v)
            {
                ds.merge(set_u, set_v);
            }
        }
	}
    mx = 0;
	int sum[V+1];
	memset(sum, 0, sizeof sum);

	for (int i = 1; i <= V; i++) {
		int x = ds.find(i);
		sum[x]++;
        mx = max(mx, sum[x]);
	}
    return mx;
}

void mainFunction()
{
	while(cin >> V >> E && V && E){
		int result = kruskalMST();
		cout << result << "\n";
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