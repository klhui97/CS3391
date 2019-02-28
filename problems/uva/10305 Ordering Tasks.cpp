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
#define DUBUG true
#define $(x)                                         \
	{                                                \
		if (DUBUG)                                   \
			cout << #x << " = " << x << " " << endl; \
	}
#define _(x)                                 \
	{                                        \
		if (DUBUG)                           \
			cout << #x << " = " << x << " "; \
	}

#define maxn 1299709 + 1
#define maxw 5
#define INF 0x3f3f3f3f

using namespace std;

class Graph 
{ 
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort(); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);
} 

void Graph::topologicalSortUtil(int v, bool visited[],  
                                stack<int> &Stack) 
{ 
    visited[v] = true; 

    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
 
    Stack.push(v); 
} 

void Graph::topologicalSort() 
{ 
    stack<int> Stack; 
    bool *visited = new bool[V]; 
    for (int i = 1; i < V; i++) 
        visited[i] = false; 

    for (int i = 1; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 

    while (Stack.empty() == false) 
    { 
        cout << Stack.top(); 
        Stack.pop(); 
		if (Stack.empty() == false) {
			cout << " ";
		}
    }
	cout << endl;
} 

void mainFunction()
{
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topologicalSort();
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