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

int V;
int src;

typedef pair<int, double> iPair;
list<iPair> *adj;

void addEdge(int u, int v, double w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

double primMST()  {
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    vector<double> dist(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            double weight = (*i).second;

            if (inMST[v] == false && dist[v] > weight)
            {
                dist[v] = weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

    double sum = 0;
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
	double x[105];
	double y[105];
	int t;
	int n;
	cin >> t;
	while(t--){
		cin >> n;
		V = n;
		adj = new list<iPair> [V];
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
			for (int j = 0; j < i; j++) {
				int d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
				addEdge(i, j, sqrt(d));
			}
		}
		cout << fixed << setprecision(2) << primMST() << "\n";
		if (t != 0)
			cout << "\n";
	}
	
	src = 3;
	V = 9;
	adj = new list<iPair> [V];
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