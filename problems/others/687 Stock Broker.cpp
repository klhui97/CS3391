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

#define maxn 10005
#define maxw 1000
#define INF 0x3f3f3f3f

void mainFunction()
{
	int a[maxn];
	int n;
	int ans;
	int low;
	while(cin >> n && cin){
		ans = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		low = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] >= low) {
				ans = max(ans, a[i] - low);
			}else {
				low = a[i];
			}
		}

		if (ans != -1) {
			cout << ans << "\n";
		}
		else
			cout << "QUIT\n";
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