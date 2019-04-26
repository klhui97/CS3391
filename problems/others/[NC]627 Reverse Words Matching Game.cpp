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

void mainFunction()
{
	string a[53];
	bool paired[53];
	int t;

	while(cin >> t && cin){
		for (int i = 0; i < t; i++) {
			cin >> a[i];
		}
		memset(paired, false, sizeof paired);
		for (int i = 0; i < t; i++){
			if (paired[i])
				continue;
			for (int j = 0; j < t; j++) {
				if (i == j)
					continue;
				string s1 = a[i];
				string s2 = a[j];
				// _(a[i]);
				// $(a[j]);
				int alen = s1.length();
				int blen = s2.length();
				if (alen != blen)
					continue;
				
				if (blen % 2 == 1) {
					if (s1[blen - 1] != s2[blen -1])
						continue;
					blen--;
					alen--;
				}
				
				for (int k = 0; k < alen; k += 2) {
					bool found = false;
					
					for (int l = 0; l < blen; l += 2) {
						if ((s1[k] == s2[l] && s1[k + 1] == s2[l + 1]) || (s1[k] == s2[l + 1] && s1[k + 1] == s2[l])) {
							s2[l] = s2[blen - 2];
							s2[l + 1] = s2[blen - 1];
							blen -= 2;
							found = true;
							break;
						}
					}
					if (!found) {
						break;
					}
				}
				if (blen == 0) {
					paired[i] = paired[j] = true;
				}
					
			}
		}
		int cnt = 0;
		for (int i = 0; i < t; i++) {
			if (!paired[i])
				cnt++;
		}
		cout << cnt << "\n";
		
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