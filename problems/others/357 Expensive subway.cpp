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

int now;
int V;
int src;

typedef pair<int, int> iPair; 
list< pair<int, int> > *adj; 

void addEdge(int u, int v, int w) { 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
}

int primMST()  {
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) 
    {
        int u = pq.top().second; 
        pq.pop(); 
  
        inMST[u] = true;
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If v is not in MST and weight of (u,v) is smaller 
            // than current key of v 
            if (inMST[v] == false && dist[v] > weight) 
            { 
                // Updating key of v 
                dist[v] = weight; 
                pq.push(make_pair(dist[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
  
    // Print edges of MST using parent array
	int sum = 0;
    for (int i = 0; i < V; ++i) {
		if (i != src) {
			if (dist[i] == INF) {
				sum = dist[i];
				break;
			}
			// printf("%d - %d    %d\n", parent[i], i, dist[i]);
			sum += dist[i];
		}
	}
        
	return sum;
}

void mainFunction()
{
	int e;
	int w;
	string s, s2;
	int from;
	int i, j, k;
	while(cin >> V >> e && V){
		adj = new list<iPair> [V];
		map<string, int> m;
		for (int i = 0; i < V; i++) {
			cin >> s;
			m[s] = i;
		}
		for (int i = 0; i < e; i++) {
			cin >> s >> s2 >> w;
			int x = m.find(s)->second;
			int y = m.find(s2)->second;
			addEdge(x, y, w);
		}
		
		cin >> s;
		src = m.find(s)->second;
		int ans = primMST();
		if (ans != INF)
			cout << ans << "\n";
		else
			cout << "Impossible\n";
		// if (sum < INF)
		// 	cout << sum << "\n";
		// else
		// 	cout << "Impossible\n";
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