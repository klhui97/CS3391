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
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << endl;}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 1000000
#define maxw 5
#define INF 0x3f3f3f3f

void mainFunction()
{
	int x, y;
	int turn;
	int clear = 0;
	while(cin >> x >> y){
		// clear round
		turn = 0;
		clear = min(x / 2, y / 24);
		x = x - clear * 2;
		y = y - clear * 24;
		while(true) {
			if (!turn) {
				if (x >= 2 && y >= 2) {
					x -= 2;
					y -= 2;
				}else if (x >= 1 && y >= 12) {
					x -= 1;
					y -= 12;
				}else if (y >= 22) {
					y -= 22;
				}else {
					break;
				}
			}else {
				if (y >= 22) {
					y -= 22;
				}else if (x >= 1 && y >= 12) {
					y -= 12;
					x -= 1;
				}else if (x >= 2 && y >= 2) {
					x -= 2;
					y -= 2;
				}else {
					break;
				}
			}
			turn = !turn;
		}

		if (turn == 0) {
			cout << "Kengood" << endl;
		}else {
			cout << "Bert" << endl;
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