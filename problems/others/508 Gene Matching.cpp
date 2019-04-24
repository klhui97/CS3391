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

#define maxn 1000010
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

int *buildSuffixArray(char *txt, int n)
{
    struct suffix suffixes[n];

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i] - 'A';
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'A'): -1;
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
    int *suffixArr = new int[n]; 
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
    return  suffixArr;
}

// mode 1: return the least index of suffArr of matched prefix
// mode 2: return the largest index of suffArr of matched prefix
// other mode: return if pattern is found
// return -1 if not found
int search(char *pat, char *txt, int *suffArr, int n, int mode) 
{ 
    int m = strlen(pat);
    int ans = -1;
    int l = 0, r = n-1;
    while (l <= r) 
    {
        int mid = l + (r - l)/2; 
        int res = strncmp(pat, txt+suffArr[mid], m);
        if (res == 0) {
            // cout << "Pattern found at index " << suffArr[mid] << "\n"; 
            if (mode == 1) {
                ans = mid;
                r = mid - 1;
            }else if (mode == 2) {
                ans = mid;
                l = mid + 1;
            }else {
                return mid;
            }
        }else if (res < 0) {
            r = mid - 1;
        }else {
            l = mid + 1; 
        }
    }
    return ans;
}

int *kasai(char *txt, int *suffixArr, int n)
{
    int *lcp = new int[n]; 
    vector<int> invSuff(n, 0);

    for (int i=0; i < n; i++)
        invSuff[suffixArr[i]] = i;

    int k = 0;

    for (int i=0; i<n; i++)
    {
        if (invSuff[i] == n-1)
        {
            k = 0;
            continue;
        }
        int j = suffixArr[invSuff[i]+1];

        while (i+k<n && j+k<n && txt[i+k]==txt[j+k])
            k++;

        lcp[invSuff[i]] = k;
        if (k>0)
            k--;
    }
    return lcp;
}

void printArr(vector<int>arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mainFunction()
{
    int t, nt;
    cin >> t;
	char str[maxn];
    char pat[maxn];
    for (int c = 1; c <= t; c++) {
        cin >> str;
        cin >> nt;
        cout << "Case #" << c << "\n";
        int n = strlen(str); 
        int *suffixArr = buildSuffixArray(str, n);
        
        while(nt--){
            cin >> pat;
            int low = search(pat, str, suffixArr, n, 1);
            if (low != -1) {
                int high = search(pat, str, suffixArr, n, 2);
                cout << high - low + 1 << "\n";
            }else {
                cout << "0\n";
            }
        }
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