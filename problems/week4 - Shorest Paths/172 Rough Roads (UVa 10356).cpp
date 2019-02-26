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
#define maxn 550
#define maxw 550
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair; 

class Graph 
{ 
    int V;
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int from, int to, int w) 
{ 
    adj[from].push_back(make_pair(to, w)); 
    adj[to].push_back(make_pair(from, w)); 
} 

void Graph::shortestPath(int src) 
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

            if ((v <= V / 2 && u > V / 2) || (u <= V / 2 && v > V / 2)) {
                // cout << u << " " << v << endl;
                if (dist[v] > dist[u] + weight) 
                {
                    dist[v] = dist[u] + weight; 
                    pq.push(make_pair(dist[v], v)); 
                }
            }
                
        } 
    } 

    if (dist[max(0, V / 2 - 1)] == INF) {
        printf("?\n");
    }else {
        printf("%d\n", dist[max(0, V / 2 - 1)]); 
    }
} 

void mainFunction()
{
    int t = 1;
    int n, e;
    int start, end, w;
    int i, j, k;
    int nodes[maxn][maxn][2];
    while(scanf("%d %d\n", &n, &e) == 2){
        Graph g(n * 2);
        for( int i = 0; i < e; i++ ){
            scanf("%d %d %d\n", &start, &end, &w);
            g.addEdge(start, end + n, w);
            g.addEdge(start + n, end, w);
        }

        printf("Set #%d\n", t++);
        g.shortestPath(0);
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