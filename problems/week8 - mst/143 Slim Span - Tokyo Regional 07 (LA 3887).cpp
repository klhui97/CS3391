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
#define ull unsigned long long
#define DUBUG true
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 10
#define maxw 5
#define INF 0x3f3f3f3f

typedef  pair<int, int> iPair;
int V, E; 
vector< pair<int, iPair> > edges; 

void addEdge(int u, int v, int w) 
{ 
	edges.push_back(make_pair(w, make_pair(u, v))); 
}
 
struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    // Constructor. 
    DisjointSets(int n) 
    { 
        // Allocate memory 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 

        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 

    int find(int u) 
    {
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 

    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 

int kruskalMST() 
{ 
    int mst_wt = 0;
	int cnt = 0;
	int max = 0;
    DisjointSets ds(V);

    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first; 
        int v = it->second.second; 
  
        int set_u = ds.find(u); 
        int set_v = ds.find(v); 

        if (set_u != set_v) 
        {
            // cout << u << " - " << v << " cost: " << it->first << "\n"; 
            mst_wt += it->first; 
			max = it->first;
            ds.merge(set_u, set_v);
			cnt++;
			if (cnt == V - 1)
				break;
        }
    } 
	// cout << "Weight of MST is " << mst_wt << "\n";
	// Clear after finished
	// edges.clear();
	if (cnt == V - 1)
		return max;
	else
    	return -1; 
}

void mainFunction()
{
    int v, u, w;
	int ans;
	int mi, mx;
	while(cin >> V >> E && V) {
		edges.clear();
		for (int i = 0; i < E; i++) {
			cin >> v >> u >> w;
			addEdge(v, u, w); 
		}
		sort(edges.begin(), edges.end());
		mi = edges.begin()->first;
		mx = kruskalMST();
		if (mx != -1) {
			ans = mx - mi;
			for (int i = 1; i < E && E - i >= V - 1; i++) {
				// _(E - i);
				// $(V - 1);
				edges.erase(edges.begin());

				mi = edges.begin()->first;
				mx = kruskalMST();
				if (mx != -1) {
					ans = min(ans, mx - mi);
				}
			}
		}else {
			ans = -1;
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
	cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}