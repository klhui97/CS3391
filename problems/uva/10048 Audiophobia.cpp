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

int dfs(int s, int t)
{
    int visited[V];
    memset(visited, INF, sizeof visited);

    stack<node> stack;
    stack.push(node(s, 0));

	int ans = INF;
    list<node>::iterator i;

    while (!stack.empty())
    {
        int v = stack.top().v;
        int d = stack.top().distance;
        stack.pop();
		if (v == t) {
			ans = min(ans, d);
		}

        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            int u = (*i).v;
			int dd = (*i).distance;
			// cout << "From " << v << " to " << u << " max: " << max(d, dd) << "\n";
            if (max(d, dd) < visited[u]) {
                visited[u] = max(d, dd);
                stack.push(node(u, max(d, dd)));
            }
        }
    }
	// cout << "\n";
	return ans;
}
void mainFunction()
{
	int c, s, q;
	int v, u, w;
	int cnt = 1;
	while(cin >> c >> s >> q && c){
		V = c + 1;
		adj = new list<node>[V];
		for (int i = 0; i < s; i++) {
			cin >> v >> u >> w;
			addEdge(v, u, w);
		}
		if (cnt != 1)
			cout << "\n";
		cout << "Case #" << cnt++ << "\n";
		for (int i = 0; i < q; i++) {
			cin >> v >> u;
			int ans = dfs(v, u);
			if (ans != INF)
				cout << ans << "\n";
			else
				cout << "no path\n";
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