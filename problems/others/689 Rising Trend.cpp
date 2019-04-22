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

#define maxn 1000005
#define maxw 1000
#define INF 0x3f3f3f3f

int dp[maxn], a[maxn];

int b_search(int n, int target)
{
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(target >= dp[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
 
int solve(int *a, int n)
{
    int len = 1;
    dp[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        int pos = b_search(len, a[i]);
        dp[pos] = a[i];
        len = max(len, pos + 1);
    }
    return len;
}

void mainFunction()
{
	int n;

	while(cin >> n && cin){
		for(int i = 0; i < n; i++)
			cin >> a[i];
		cout << solve(a, n) << "\n";
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