// #include <bits/stdc++.h> // all

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

int wa[maxn], wb[maxn], wv[maxn], Ws[maxn];
int sa[maxn], Rank[maxn], height[maxn];
char str[maxn];

int cmp(int *r, int a, int b, int l) {
	return r[a] == r[b] && r[a + l] == r[b + l];
}

bool contain(string S, int *sa, string T) {
      int a = 0, b = S.length();
      while (b - a > 1)
      {
            int c = (a + b) / 2;
            if (S.compare(sa[c], T.length(), T) < 0)    a = c;
            else b = c;
      }
      return S.compare(sa[b], T.length(), T) == 0;
}

void get_SA(const string r, int sa[], int n, int m) {
      int i, j, p, *x = wa, *y = wb, *t;
      for (i = 0; i < m; i++) Ws[i] = 0;
      for (i = 0; i < n; i++) Ws[x[i] = r[i]]++;
      for (i = 1; i < m; i++) Ws[i] += Ws[i - 1];
      for (i = n - 1; i >= 0; i--) sa[--Ws[x[i]]] = i;
    //   cout<<"SA"<<endl;;
    //   for(int i=0;i<n+1;i++)cout<<sa[i]<<' ';
      for (j = 1, p = 1; p < n; j *= 2, m = p)
      {
            for (p = 0, i = n - j; i < n; i++) y[p++] = i;
            for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
            for (i = 0; i < n; i++) wv[i] = x[y[i]];
            for (i = 0; i < m; i++) Ws[i] = 0;
            for (i = 0; i < n; i++) Ws[wv[i]]++;
            for (i = 1; i < m; i++) Ws[i] += Ws[i - 1];
            for (i = n - 1; i >= 0; i--) sa[--Ws[wv[i]]] = y[i];
            for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
                  x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
      }
      return;
}
void mainFunction()
{
	string str;
	int l;
	while(cin >> str >> l){
	 	int len = str.size();
		get_SA(str, sa, len + 1, 130);
		for (int i = 0; i < len; i++) {
			if (len - sa[i] >= l) {
				cout << str.substr(sa[i], l) << "\n";
				break;
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