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

#define maxn 1005
#define maxw 60000 * 2 + 5000 * 2 + 100
#define INF 0x3f3f3f3f

void mainFunction()
{
	int n;
	int cur_year;
	int dp[maxn];
	int year[maxn];
    int times[maxn];
    char mark[maxn];
    while (scanf("%d", &n) == 1 && n) {
        int mm, dd, HH, MM;
        for (int i = 0; i < n; i++) {
            scanf("%d:%d:%d:%d %*s %s", &mm, &dd, &HH, &MM, &mark[i]);
            times[i] = ((mm * 31 + dd) * 24 + HH) * 60 + MM;
        }

        for (int i = 1; i < n; i++) {
            if (times[i] > times[i-1])
                year[i] = year[i-1];
            else
                year[i] = year[i-1] + 1;
            cur_year = year[i];
        }
        int last = -1, first = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (last == -1 && year[i] == cur_year)
                dp[i] = 1;
            else
                dp[i] = n - i;
            if (last == -1 && (mark[i] == '+' || year[i] != cur_year))
                last = i;
            if (mark[i] == '+')
                first = i;
        }
        for (int i = last; i >= first; i--) {
            for (int j = i + 1; j < n; j++) {
                if (year[i] == year[j])
                    dp[i] = min(dp[i], dp[j] + 1);
                else if (times[i] >= times[j] && year[j] - year[i] == 1)
                    dp[i] = min(dp[i], dp[j] + 1);
                else
                    break;
                if (mark[j] == '+')
					break;
            }
        }
        printf("%d\n", dp[first]);
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
	// cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}