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
using namespace std;
#define maxn 101
#define maxw 5
#define INF 0x3f3f3f3f
	int level[maxn];
typedef pair<int, int> iPair; 
class Graph 
{ 
    int V;
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V);
    void addEdge(int u, int v, int w);
    int shortestPath(int s, int cost); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int from, int to, int w) 
{ 
    adj[from].push_back(make_pair(to, w));
    // printf("%d --> %d weight: %d Level: %d\n", from, to, w, level[from]);
    // adj[to].push_back(make_pair(from, w)); 
} 

int Graph::shortestPath(int src, int cost)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(cost, src));
    dist[src] = cost;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[1];
}

void mainFunction()
{
    int M, N;
    int i, j, k;
    int P, L, X;
    int T, V;
    int cost[maxn];
    
    int from[maxn*maxn];
    int to[maxn*maxn];
    int w[maxn*maxn];
	
    int e;
    
	while(scanf("%d %d\n", &M, &N) == 2) {
        // printf("There are %d monters with limit %d\n", N, M);
        
        e = 0;
        for (i = 1; i <= N; i++) {
            scanf("%d %d %d\n", &P, &L, &X);
            // printf("Monster%d. Level: %d. Cost: %d\n", i, L, P);
            cost[i] = P;
            level[i] = L;
            for (j = 0; j < X; j++) {
                scanf("%d %d\n", &T, &V);
                // printf("T: %d V: %d\n", T, V);
                from[e] = T;
                to[e] = i;
                w[e] = V;
                e++;
            }
        }

        int f, t, now;
        int minSp = cost[1];
		int upperLimit = level[1] + M;
		int lowerLimit = level[1] - M;

        for (k = 2; k <= N; k++) {
            Graph g(N + 1);
			// cout << "Start New graph -------- From: " << k << " Cost: " << cost[k] << " Upper Limit: " << upperLimit << " Lower Limit: " << lowerLimit << endl;
			int src_level = level[k];

            for (i = 0; i < e; i++) {
                f = level[from[i]];
                t = level[to[i]];
                
				if (f >= level[1] && t >= level[1] && f <= upperLimit && t <= upperLimit)
					g.addEdge(from[i], to[i], w[i]);
                
            }
			int new_dis = g.shortestPath(k, cost[k]);
			// cout << "End New graph --------" << " Cost: " << cost[k] << " New total cost: " << new_dis << endl;
            minSp = min(minSp, new_dis);
        }

		for (k = 2; k <= N; k++) {
            Graph g(N + 1);
			// cout << "Start New graph -------- From: " << k << " Cost: " << cost[k] << "Upper Limit: " << upperLimit << " Lower Limit: " << lowerLimit << endl;

            for (i = 0; i < e; i++) {
                f = level[from[i]];
                t = level[to[i]];
                
				if (f >= lowerLimit && t >= lowerLimit && f <= level[1] && t <= level[1])
					g.addEdge(from[i], to[i], w[i]);
                
            }
			int new_dis = g.shortestPath(k, cost[k]);
			// cout << "End New graph --------" << " Cost: " << cost[k] << " New total cost: " << new_dis << endl;
            minSp = min(minSp, new_dis);
        }
        printf("%d\n", minSp);
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
		cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << int(rand() % 24 + 1) << endl;
	}
}

int main()
{
	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}