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

#define maxn 1000
#define maxw 1000
#define INF 0x3f3f3f3f
struct node {
    int v;
    int distance;

    node(int v, int distance) :v(v), distance(distance) {};
};

int V;
list<node> *adj;

void addEdge(int v, int u, int w)
{
    adj[v].push_back(node(u, w));
	adj[u].push_back(node(v, w));
}

int bfs(int s, int t) {

    int dist[V];
    memset(dist, 0, sizeof dist);

    list<node> queue;
    queue.push_back(node(s, INF));
    dist[s] = INF;

    list<node>::iterator i;

    while(!queue.empty())
    {
        int v = queue.front().v;
        int d =  queue.front().distance;
        queue.pop_front();

        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            int u = (*i).v;
			int dd = (*i).distance;
			
            if (min(d, dd) > dist[u]) {
                dist[u] = min(d, dd);
                queue.push_back(node(u, min(d, dd)));
            }
        }
    }
	return dist[t];
}

void mainFunction()
{
	int n, r;
	int c = 1;
	int v, u, w;
	int graph[105][105];
	while (cin >> n >> r && n)
	{
		int N = n + 1;
		int i, j, k;
		memset(graph, 0, sizeof graph);
		for (int i = 0; i < r; i++) {
			cin >> v >> u >> w;
			graph[v][u] = graph[u][v] = w;
		}
		cin >> v >> u >> w;

		for(k = 1; k < N; k++) {
			for(i = 1; i < N; i++) {
				for(j = 1; j < N; j++) {
                    graph[i][j] = max(graph[i][j], min(graph[i][k], graph[k][j]));
				}
			}
        }
		int ans = graph[v][u];
        if(w %(ans - 1) == 0)    {
            ans = w/(ans - 1);
        }
        else
            ans = w/(ans - 1) + 1;
		cout << "Scenario #" << c++ << "\n";
		cout << "Minimum Number of Trips = " << ans << "\n\n";
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