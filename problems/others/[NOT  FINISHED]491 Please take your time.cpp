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
#define $(x) {cout << #x << " = " << x << " " << endl;}

#define maxn 2000 + 1
#define maxw 5
#define INF 0x3f3f3f3f

int trap[maxn];
typedef pair<int, int> iPair; 
class Graph 
{ 
    int V;
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V);
    void addEdge(int u, int v, int w);
    int shortestPath(int s); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int from, int to, int w) 
{ 
    adj[from].push_back(make_pair(to, w));
    // printf("%d --> %d weight: %d\n", from, to, w);
    adj[to].push_back(make_pair(from, w));
	// printf("%d --> %d weight: %d\n", to, from, w);
} 

int Graph::shortestPath(int src)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;

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
				// cout << "Old distance from " << src << " to " << v << " is " << dist[v] << endl;
				// cout << "Found a shorter way to go " << v << " - go from " << u << " with distance " << dist[u] + weight << endl;
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

	// Initialize min value 
   int min = INT_MAX, min_index; 
   
   	// Print shortest distances stored in dist[] 
    // printf("Vertex   Distance from Source\n"); 
    // for (int i = 0; i < V; ++i) 
    //     printf("%d \t\t %d\n", i, dist[i]);
		 
    return dist[1];
}

void mainFunction()
{
	int n, r, t;
	int i, j ,k;
	int v, w, u;
	
	while(cin >> n >> r >> t) {
		Graph g(n + 1);
		for (i = 0; i < r; i++) {
			cin >> v >> u >> w;
			g.addEdge(v, u, w);
		}
		memset(trap, 0, sizeof trap);
		for (i = 0; i < t; i++) {
			cin >> v >> w;
			trap[v] = w;
		}
		int length = g.shortestPath(n);
		if (length == INF) {
			cout << "Impossible!" << endl;
		}else {
			cout << length << endl;
		}
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
	ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}