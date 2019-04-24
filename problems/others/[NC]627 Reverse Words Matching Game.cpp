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

struct suffix
{
    int index;
    int rank[2];
};

int cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
        (a.rank[0] < b.rank[0] ?1: 0);
}

vector<int> buildSuffixArray(string txt, int n)
{
    struct suffix suffixes[n];

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'a';
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1;
    }

    sort(suffixes, suffixes+n, cmp);
    int ind[n];

    for (int k = 4; k < 2*n; k = k*2)
    {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++)
        {
            if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i-1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k/2;
            suffixes[i].rank[1] = (nextindex < n)?
                                suffixes[ind[nextindex]].rank[0]: -1;
        }
        sort(suffixes, suffixes+n, cmp);
    }
    vector<int>suffixArr;
    for (int i = 0; i < n; i++)
        suffixArr.push_back(suffixes[i].index);
    return  suffixArr;
}

void printArr(vector<int>arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mainFunction()
{
	string a[53];
	string str;
	vector<string> dp[53];
	int n;
	char temp;
	int t;

	while(cin >> t && cin){
		for (int i = 1; i <= 52; i++) {
			dp[i].clear();
		}
		// cout << "New\n";
		for (int i = 0; i < t; i++) {
			cin >> str;
			n = str.size();
			a[i] = str;
			dp[n].push_back(str);
			if (n % 2 == 0) {
				for (int l = 2; l <= n; l += 2) {
					string nstring = str;
					for (int j = 0; j < l / 2; j++) {
						temp = nstring[j];
						nstring[j] = nstring[l - j - 1];
						nstring[l - j - 1] = temp;
					}
					// $(nstring);
					dp[n].push_back(nstring);
				}
			}
		}
		int ans = 0;
		int cnt;
		for (int i = 0; i < t; i++) {
			n = a[i].size();
			cnt = 0;
			vector<string>::iterator it;
			for (it = dp[n].begin(); it != dp[n].end(); it++) {
				if (a[i].compare(*it) == 0) {
					cnt++;
					if (cnt > 1)
						break;
				}
			}
			if (cnt < 2)
				ans++;
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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	mainFunction();
	return 0;
}