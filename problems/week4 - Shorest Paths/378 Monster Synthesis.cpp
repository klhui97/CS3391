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
int level[maxn];
int limit;
typedef pair<int, int> iPair;
struct node {
    int id;
    int distance;

    node(int id, int distance) :id(id), distance(distance) {};

    bool operator < (const node n2) const {
        return distance > n2.distance;
    }
};
class Graph
{
    int V;
    list< pair<int, int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int shortestPath(int s, int low, int up);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
	// printf("%d --> %d weight: %d Level: %d\n", u, v, w, level[u]);
    // adj[v].push_back(make_pair(u, w));
}
int Graph::shortestPath(int src, int low, int up)
{
	// _(low);
	// $(up);
    priority_queue<node> pq;
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    int dist[V + 1];
    memset(dist, INF, sizeof dist);
	bool found = false;
    pq.push(node(src, 0));
    dist[src] = 0;

    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().id;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
			if (level[u] >= low && level[u] <= up && level[v] >= low && level[v] <= up) {
				if (dist[v] > dist[u] + weight)
				{
					if (v == 1) {
						found = true;
					}
					// Updating distance of v
					dist[v] = dist[u] + weight;
					pq.push(node(v, dist[v]));
				}
			}
            
        }
    }
	if (found)
    	return dist[1];
	else
		return INF;
}

void mainFunction()
{
	int N;
    int i, j, k;
    int P, L, X;
    int T, V;
	int ans;
	int cost[maxn];
	
    
	while(scanf("%d %d\n", &limit, &N) == 2) {
        Graph g(N + 1);
        for (i = 1; i <= N; i++) {
            scanf("%d %d %d\n", &P, &L, &X);
			if (i == 1)
				ans = P;
            cost[i] = P;
            level[i] = L;
            for (j = 0; j < X; j++) {
                scanf("%d %d\n", &T, &V);
				g.addEdge(T, i, V);
            }
        }
		for (int i = 2; i <= N; i++) {
			int upper = level[1] + limit;
			int lower = level[1] - limit;
			for (int low = lower; low + limit <= upper; low++) {
				ans = min(ans, cost[i] + g.shortestPath(i, low, low + limit));
			}
		}
		cout << ans << "\n";
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