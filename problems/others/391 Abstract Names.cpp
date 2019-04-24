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

bool isv(char a) {
    char v[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
        if (a == v[i])
            return true;
    }
    return false;
}

void mainFunction()
{
    string l;
    string r;
    bool fail = false;
	int t;
    cin >> t;
    // getchar();
    while(t--){
        cin >> l;
        cin >> r;
        string s1, s2;
        for (int i = 0; i < l.length(); i++) {
            if (!isv(l[i])) {
                s1.append(1, l[i]);
            }
        }
        for (int i = 0; i < r.length(); i++) {
            if (!isv(r[i])) {
                s2.append(1, r[i]);
            }
        }
        // _(s1);
        // $(s2);
        if (s1 != s2)
            cout << "No\n";
        else
            cout << "Yes\n";
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