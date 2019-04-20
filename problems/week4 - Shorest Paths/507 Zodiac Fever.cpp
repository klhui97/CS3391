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

#define maxn 1500
#define maxw 5
#define INF 0x3f3f3f3f

char action[maxn];
int n[maxn];
int s, e, oring, tring;

int solve(char c, int cur, int n) {
	int newRPos = cur;
	if(c=='+') newRPos += n%12;
	else if(c=='-') newRPos -= n%12;
	else if(c=='=') newRPos = n;
	else if(c=='*') newRPos = cur*n;
	if (newRPos <= 0) newRPos += 12;
	if (newRPos > 12) newRPos %= 12;
	return newRPos;
}

typedef pair<int, int> iPair; 
struct node {
    int id;
    int distance;
	int status;

    node(int id, int distance, int status) :id(id), distance(distance), status(status) {};

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
    void shortestPath(int s); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 

void Graph::shortestPath(int src) 
{
	int dist[V + 1][13];
	bool visited[V + 1][13];
	memset(dist, INF, sizeof dist);
	priority_queue<node> pq;
	memset(visited, false, sizeof visited);
	dist[src][oring] = 0;

	if (!(s == e && oring == tring))
		pq.push(node(s,0,oring));

	while(!pq.empty()){
		int u = pq.top().id; 
		int status = pq.top().status;
		int d = pq.top().distance;
        pq.pop();
		
		if(visited[u][status]) continue;
		visited[u][status] = true;

		list< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
			int v = (*i).first; 
            int weight = (*i).second;

			int newRPos = solve(action[v], status, n[v]);
			dist[v][newRPos] = min(dist[v][newRPos], dist[u][status] + weight);

			pq.push(node(v, d + weight, newRPos));
				
		}
	}
	if(dist[e][tring]>=INF)
		puts("Pray!");
	else
		printf("%i\n",dist[e][tring]);
}

void mainFunction()
{
	int nr, nc, nt;
	int x, y, z;
	char c;
	while(~scanf("%i%i%i%i%i%i%i",&nr, &nc, &nt, &s, &oring, &e, &tring)){
		Graph g(maxn);
		while(nc--){
			scanf("%i%i%i",&x,&y,&z);
			g.addEdge(x, y, z);
		}
		memset(action,'0',sizeof(action));
		while(nt--){
			scanf("%i %c %i",&x,&c,&z);
			action[x] = c;
			n[x] = z;
		}
		g.shortestPath(s);
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