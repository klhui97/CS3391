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

int sumd(int x) {
	int sum = 0;
	while (x > 0)
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
	
}
int solve(int n)
{
	if (n < 4) {
		return n + 1;
	}
	bool isprime = true;
    // Print the number of 2s that divide n
	int sum = 0;
    while (n%2 == 0)
    {
		// printf("%d ", 2);
		isprime = false;
		sum += sumd(2);
        n = n/2;
    }

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
			// printf("%d ", i);
			isprime = false;
            sum += sumd(i);
            n = n/i;
        }
    }

    if (n > 2) {
		// printf ("%d ", n);
		if (isprime) {
			sum = sumd(n) + 1;
		}else {
			sum += sumd(n);
		}
	}
	return sum;
}

void mainFunction()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		x++;
		int sumx = sumd(x);
		int sumxx = solve(x);
		while (sumx != sumxx)
		{
			x++;
			sumx = sumd(x);
			sumxx = solve(x);
		}
		// _(sumx);
		// $(solve(x));
		cout << x << "\n";
		
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