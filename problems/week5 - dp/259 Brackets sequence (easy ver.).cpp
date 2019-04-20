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


bool isBalance(char a, char b){
	return (a=='(' && b ==')') || (a=='[' && b ==']');
}

void mainFunction()
{
	int dp[500][500];
	int t;
	cin >> t;
	string s;
	bool firstLine = true;
	getline(cin, s);
	while(t--){
		getline(cin, s);
		getline(cin, s);
		memset(dp,0,sizeof(dp));
		int len = s.length();
		
		if(!firstLine)
			cout << "\n"; 
		else
			firstLine = false;

		if(len==0){
			cout << "0\n"; 
			continue;
		}

		
		for(int i = 0; i < len; i++)
			dp[i][i]=1;

		for(int i = 1; i < len; i++)
			for(int k = 0; i + k < len; k++){
				int j = i + k;
				if(isBalance(s[k],s[j]))
					dp[k][j]=dp[k+1][j-1];
				else
					dp[k][j]= INF;

				for(int l=k; l<j; l++)
					dp[k][j] = min(dp[k][j], dp[k][l] + dp[l+1][j]);
			}
		cout << len+dp[0][len-1] << "\n";
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