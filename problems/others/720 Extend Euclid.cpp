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

#define maxn 1000
#define maxw 1000
#define INF 0x3f3f3f3f

int gcdExtended(int a, int b, int *x, int *y) 
    { 
        // Base Case 
        if (a%b == 0) 
        { 
            *x = 0; 
            *y = 1; 
            return b; 
        } 
    
        int x1, y1; // To store results of recursive call 
        int gcd = gcdExtended(b, a%b, &x1, &y1); 
    
        // Update x and y using results of recursive 
        // call
        *x = y1;
        *y = x1 - (a/b) * y1; 
        return gcd; 
    }
	
void mainFunction()
{
	int a, b, x, y;
	while(cin >> a >> b && cin){
		int g = gcdExtended(a, b, &x, &y);
		if (x < 0) {
			x += b / g;
			y -= a / g;
		}
		cout << x << " " << y << "\n";
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