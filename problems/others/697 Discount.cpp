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

#define maxn 100
#define maxw 1000
#define INF 0x3f3f3f3f

void mainFunction()
{
	int n;
	int total;
	int discount[100];
	int x, y;
	while(cin >> n && cin){
		total = 0;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			total += x;
			discount[i] = x - y;
		}
		
		sort(discount, discount + n);
		if (total >= 100) {
			int j;
			if (n % 2 == 0)
				j = n / 2;
			else
				j = n / 2 + 1;
			for (; j < n; j++)
				total -= discount[j];
		}
		
		cout << total << "\n";
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
	mainFunction();
	return 0;
}