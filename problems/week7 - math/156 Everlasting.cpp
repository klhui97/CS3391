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
using namespace std;
#define DUBUG true
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 1000001
#define maxw 5
#define INF 0x3f3f3f3f

int prime[maxn];
int maxprime[maxn];
int sumprime[maxn];

void SieveOfEratosthenes(int n)
{
    bool isprime[n];
	memset(isprime, true, sizeof(isprime));

	for (int p=2; p*p<=n; p++)
	{
		if (isprime[p] == true)
		{
			for (int i=p*p; i<=n; i += p)
				isprime[i] = false;
		}
	}
  
	memset(sumprime, 0, sizeof sumprime);
    for (int a = 2; a < n; a++) {
		if (isprime[a]) {
			for (int j = 1; a * j < n; j++) {
				maxprime[a * j] = a;
				sumprime[a * j] += a; 
			}
		}
	}
}

void mainFunction()
{
	int a, b;
	SieveOfEratosthenes(maxn);
	while(cin >> a >> b && a && b){
		int aDiff = maxprime[a] - (sumprime[a] - maxprime[a]);
		int bDiff = maxprime[b] - (sumprime[b] - maxprime[b]);
		if (aDiff > bDiff)
			cout << "a" << "\n";
		else
			cout << "b" << "\n";
	}
	
}

void testCaseGenerator()
{
	int d[24];
	for (int i = 1; i < 25; i++)
	{
		d[i - 1] = i;
	}
	for (int i = 0; i < 100; i++)
	{
		// random_shuffle(begin(d), end(d));
		cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << int(rand() % 24 + 1) << endl;
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
	// testCaseGenerator();
	mainFunction();
	return 0;
}