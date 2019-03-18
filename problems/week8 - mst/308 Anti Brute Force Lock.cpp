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

#define maxn 501
#define maxw 5
#define INF 0x3f3f3f3f

int V;

int minKey(int key[], bool mstSet[])  {
	int min = INT_MAX, min_index; 
	
	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 
	
	return min_index; 
}

int primMST(int graph[maxn][maxn])  {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 

    key[0] = 0;      
    parent[0] = -1;

    for (int count = 0; count < V-1; count++) 
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true; 
        for (int v = 0; v < V; v++)  
        	if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
            parent[v] = u, key[v] = graph[u][v]; 
    }

    int w = 0;
	printf("Edge \tWeight\n"); 
	for (int i = 1; i < V; i++) {
		w += graph[i][parent[i]];
		printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
	}
	return w;
}

int weight(int from, int to) {
	int d1;
	int d2;
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		d1 = from % 10;
		d2 = to % 10;
		// _(d1);
		// $(d2);
		int dif = abs(d1 - d2);
		cnt += min(dif, 10 - dif);
		from /= 10;
		to /= 10;
	}
	return cnt;
}

void mainFunction()
{
	int t;
	int v, u, w;
	int lock[501];
	int Graph[maxn][maxn];
	cin >> t;
	while(t--){
		cin >> V;
		for (int i = 0; i < V; i++) {
			cin >> lock[i];
			for (int j = 0; j < i; j++) {
				int x = weight(lock[i], lock[j]);
				Graph[i][j] = Graph[j][i] = x;
			}
		}
		
		int mst = primMST(Graph);
		int mi = weight(lock[0], 0);
		for (int j =  1; j < V; j++) {
			mi = min(mi, weight(lock[j], 0));
		}
		cout << mst + mi << "\n";
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
	cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}