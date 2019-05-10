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

int V;
list<int> *adj;

struct node {
    int v;
    int distance;

    node(int v, int distance) :v(v), distance(distance) {};
};

void addEdge(int v, int w)
{
    adj[v].push_back(w);
	adj[w].push_back(v);
}

bool bfs(int s) {

	int color[V];
    bool visited[V];
    memset(visited, false, sizeof visited);
    memset(color, 0, sizeof color);

    list<node> queue;
    queue.push_back(node(s, 0));

    visited[s] = true;
	color[s] = 1;

    list<int>::iterator i;

    while(!queue.empty())
    {
        int v = queue.front().v;
        queue.pop_front();

        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            int u = *i;
			if (color[u]) {
				// _(color[v]);
				// $(color[u]);
				if (color[v] * -1 != color[u])
					return false;
			}else {
				color[u] = -1 * color[v];
			}
            if (!visited[u]) {
                visited[u] = true;
                queue.push_back(node(u, 0));
            }
        }
    }
	return true;
}

void mainFunction()
{
	int t;
	int v, w;
	while (cin >> V && V)
	{
		cin >> t;
		adj = new list<int>[V];
		for (int i = 0; i < t; i++) {
			cin >> v >> w;
			addEdge(v, w);
		}
		if (bfs(0)) {
			cout << "BICOLORABLE.\n";
		}else {
			cout << "NOT BICOLORABLE.\n";
		}
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