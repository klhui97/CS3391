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

#define maxn 150 + 1
#define maxw 5
#define INF 0x3f3f3f3f

int t;
int r;
int x, y;
struct state{
	int x, y, r, step;
};
queue<state> q;
bool visited[maxn][maxn][1001];

void fillX(state tmp) {
	if (tmp.x != x && tmp.r >= 0) {
		int need = x - tmp.x;
		if (tmp.r >= need) {
			tmp.r -= need;
			tmp.x = x;
		}else {
			tmp.x += tmp.r;
			tmp.r = 0;
		}
		tmp.step++;
		q.push(tmp);
	} 
}

void fillY(state tmp) {
	if (tmp.y != y && tmp.y >= 0) {
		int need = y - tmp.y;
		if (tmp.r >= need) {
			tmp.r -= need;
			tmp.y = y;
		}else {
			tmp.y += tmp.r;
			tmp.r = 0;
		}
		tmp.step++;
		q.push(tmp);
	} 
}

void emptyX(state tmp) {
	if (tmp.x) {
		tmp.x = 0;
		tmp.step++;
		q.push(tmp);
	}
}

void emptyY(state tmp) {
	if (tmp.y) {
		tmp.y = 0;
		tmp.step++;
		q.push(tmp);
	}
}

void xToY(state tmp) {
	if (tmp.x) {
		int need = y - tmp.y;
		if (tmp.x >= need) {
			tmp.x -= need;
			tmp.y = y;
		}else {
			tmp.y += tmp.x;
			tmp.x = 0;
		}
		tmp.step++;
		q.push(tmp);
	}
}


void yToX(state tmp) {
	if (tmp.y) {
		int need = x - tmp.x;
		if (tmp.y >= need) {
			tmp.y -= need;
			tmp.x = x;
		}else {
			tmp.x += tmp.y;
			tmp.y = 0;
		}
		tmp.step++;
		q.push(tmp);
	}
}

void mainFunction()
{
	state front;
	while(scanf("%d %d %d %d", &x, &y, &t, &r) == 4){
		int step = -1;
		while(!q.empty()){
			q.pop();
		}
		memset(visited, false, sizeof visited);
		q.push((state){0, 0, r, 0});
		while(!q.empty()){
			front = q.front();
			q.pop();
			// $(front.x);
			// $(front.y);
			// $(front.r);
			if (visited[front.x][front.y][front.r])
				continue;
			else
				visited[front.x][front.y][front.r] = true;

			if (front.x == t || front.y == t) {
				step = front.step;
				break;
			}

			fillX(front);
			fillY(front);
			emptyX(front);
			emptyY(front);
			xToY(front);
			yToX(front);
		}
		cout << step << endl;
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