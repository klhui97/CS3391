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

#define maxn 1000
#define maxw 1000
#define INF 0x3f3f3f3f
#define maxs 18000
void mainFunction()
{
	while(true) {
        int A[105], n = 0, time[105];
        memset(time, 0, sizeof time);
        while(cin >> A[n] && A[n]) {
            n++;
        }
        if(A[0] == 0)
            break;

        int s = INF, i;

        for(i = 0; i < n; i++)
            s = min(s, A[i]);
        
        for(; s <= maxs; s++) {
            bool done = true;
            for(i = 0; i < n; i++) {
                while(time[i] + A[i] - 5 <= s) {
                    time[i] += 2 * A[i];
                }
                if(!(time[i] <= s && s < time[i] + A[i] - 5)) {
                    s = time[i] - 1;
                    done = false;
                    break;
                }
            }
            if(done)
                break;
        }
        if(s > 18000)
            printf("Signals fail to synchronise in 5 hours\n");
        else
            printf("%02d:%02d:%02d\n", s/3600, s%3600/60, s%60);
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
	mainFunction();
	return 0;
}