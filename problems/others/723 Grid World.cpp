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

int n;
char graph[maxn][maxn];
int exist;
int t, k, w;

struct node {
    int v;
    int distance;

    node(int v, int distance) :v(v), distance(distance) {};

    bool operator < (const node n2) const {
        return distance > n2.distance;
    }
};

int V;
list<int> *adj;

void addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int bfs(int s, bool findW) {

    bool visited[V];
    memset(visited, false, sizeof visited);

    list<node> queue;

    visited[s] = true;
    queue.push_back(node(s, 0));

    while(!queue.empty())
    {
        int v = queue.front().v;
        int d = queue.front().distance;
        queue.pop_front();
        
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            int u = *i;
            if (!visited[u])
            {
                visited[u] = true;
                if (findW && u == w) {
                    return d + 1;
                }else if (!findW && u == exist) {
                    return d + 1;
                }
                queue.push_back(node(u, d + 1));
            }
        }
    }
    return 0;
}

void mainFunction()
{
    char s[105];
    scanf("%d\n", &t);

    while(t--){
        k = w = -1;
        scanf("%d\n", &n);
        V = n * n;
        adj = new list<int>[V];

        for (int i = 0; i < n; i++) {
            gets(s);
            for (int j = 0; j < n; j++) {
                graph[i][j] = s[j];
                if (s[j] == 'K') {
                    k = i * n + j;
                }else if (s[j] == 'W') {
                    w = i * n + j;
                }else if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                    if (s[j] == '.') {
                        exist = i * n + j;
                    }
                }
                if (i >= 1 && j >= 1) {
                    if (graph[i][j] != '#') {
                        // up
                        if (graph[i - 1][j] != '#') {
                            addEdge(i * n + j, (i - 1)*n + j);
                        }

                        // left
                        if (graph[i][j - 1] != '#') {
                            addEdge(i * n + j, i*n + j - 1);
                        }
                    }
                }
            }
        }
        int ans = bfs(k, true);
        ans += bfs(w, false);
        printf("%d\n", ans);
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