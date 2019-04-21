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

#define maxn 12
#define maxw 1000
#define INF 0x3f3f3f3f

void mainFunction()
{
    int n;
    int hire, sala, fire;
    int workers[maxn];
    int dp[12][maxw + 5];
    int maxworkers = 0;

	while(cin >> n && n){
        cin >> hire >> sala >> fire;
        memset(dp, INF, sizeof dp);
        for (int i = 0; i < n; i++) {
            cin >> workers[i];
            maxworkers = max(maxworkers, workers[i]);
        }
            
        for (int i = workers[0]; i <= maxworkers; i++) {
            dp[0][i] = (hire + sala) * i;
        }

        for (int i = 1; i < n; i++) {
            for (int j = workers[i]; j <= maxworkers; j++) {
                for (int k = workers[i - 1]; k <= maxworkers; k++) {
                    if (k <= j) { // hire more
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + hire * (j - k) + j * sala);
                    }else { // fire
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + fire * (k - j) + j * sala);
                    }
                }
            }
        }

        int ans = INF;
        for (int i =  max(0, n - 2); i <= maxworkers; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        cout << ans << "\n";
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