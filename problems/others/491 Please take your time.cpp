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

#define maxn 2005
#define maxw 5
#define INF 0x3f3f3f3f
typedef pair<int, int> iPair;

int trap[maxn];
struct node {
	int id;
	int distance;
	int gas;

	node(int id, int distance, int gas) :id(id), distance(distance), gas(gas) {};

	bool operator < (const node n2) const {
		return distance < n2.distance;
	}
};
class Graph
{
    int V;
    list< pair<int, int> > *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s, int des);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
}
void Graph::shortestPath(int src, int des)
{
    priority_queue<node> pq;
    int dist[V + 1];
    memset(dist, INF, sizeof dist);

    pq.push(node(src, 0, trap[src]));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().id;
		int gas = pq.top().gas;
        pq.pop();

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
			int nextCost;
			int ngas;
			if (weight >= gas)  {
				nextCost = gas + weight;
				ngas = 0;
			}else {
				nextCost = weight*2;
				ngas = gas - weight;
			}

            if (dist[v] > dist[u] + nextCost)
            {
                dist[v] = dist[u] + nextCost;
				int newR = ngas + trap[v];
                pq.push(node(v, dist[v], newR));
            }
        }
    }
	if(dist[des]>=INF){
		puts("Impossible!");
	}
	else{
		printf("%i\n",dist[des]);
	}
}
void mainFunction()
{
	int n, r, t;
	int v, u, w;
	while(scanf("%d %d %d", &n, &r, &t) == 3){
		Graph g(3000);
		while(r--){
			scanf("%d %d %d", &v, &u, &w);
			g.addEdge(v, u, w);
		}
		memset(trap, 0, sizeof trap);
		while(t--){
			scanf("%d %d", &v, &w);
			trap[v] = w;
		}
		g.shortestPath(1, n);
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