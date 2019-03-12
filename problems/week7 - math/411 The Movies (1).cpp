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
#define DUBUG false
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 10
#define maxw 5
#define INF 0x3f3f3f3f

ull row[47];
ull seat[47];

void mainFunction()
{
	int t, c;
	ull n, m;
	int i;
	
	cin >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n >> m >> c;
		set< pair<ull,ull> > s;
		for(i = 0; i < c; i++)
		{
			cin >> row[i];
		}
		for(i = 0; i < c; i++)
		{
			cin >> seat[i];
			s.insert(make_pair(row[i], seat[i]));
		}
		ull avaliable = n * (m - 1);
		ull prev = -1;
		ull row = -1;
		for(set< pair<ull,ull> >::iterator it = s.begin(); it != s.end(); it++) {
			if (it->first != row) {
				row = it->first;
				prev = -1;
			}

			if (it->second == 1) {
				if (m != 1) {
					avaliable--;
				}
			}else if (it->second == m) {
				$(prev);
				if (prev != it->second - 1) {
					avaliable--;
				}
			}else {
				avaliable--;
				if (prev != it->second - 1) {
					avaliable--;
				}
			}
			prev = it->second;
			
		}

		cout << "Case #" << j << ": " << avaliable << "\n";
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