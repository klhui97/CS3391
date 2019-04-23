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
	char s[23];
	bool done;
	while(gets(s)){
		int len = strlen(s);
		int i = 0;
		done = false;
		while(!done && i < len) {
			if (s[i] != '1') {
				done = true;
			}else {
				i++;
				if (i < len && s[i] != '4') {
					continue;
				}else {
					i++;
					if (i < len && s[i] != '4') {
						continue;
					}
					i++;
				}
			}
		}


		if (!done)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
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