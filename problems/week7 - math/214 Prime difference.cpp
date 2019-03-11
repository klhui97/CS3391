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
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << endl;}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 100000
#define maxw 1299709
#define INF 0x3f3f3f3f

int prime[maxn];
int table[maxw];

void SieveOfEratosthenes(int limit)
{
    bool sieve[limit]; 
    memset(sieve, false, sizeof(sieve));
	if (limit > 2)
		sieve[2] = true;
	if (limit > 3)
		sieve[3] = true;

    for (int x = 1; x * x <= limit; x++) { 
        for (int y = 1; y * y <= limit; y++) {
            int n = (4 * x * x) + (y * y); 
            if (n <= limit + 1 && (n % 12 == 1 || n % 12 == 5)) 
                sieve[n] ^= true; 
  
            n = (3 * x * x) + (y * y); 
            if (n <= limit + 1 && n % 12 == 7) 
                sieve[n] ^= true; 
  
            n = (3 * x * x) - (y * y); 
            if (x > y && n <= limit + 1 && n % 12 == 11) 
                sieve[n] ^= true; 
        } 
    }

    for (int r = 2; r * r <= limit; r++) { 
        if (sieve[r]) { 
            for (int i = r * r; i <= limit; i += r * r) 
                sieve[i] = false; 
        } 
    }
  
    // Print primes using sieve[] 
    for (int a = 2; a <= limit; a++) 
        if (sieve[a]) 
            cout << a << " ";
	cout << endl;

	// memset(table, 0, sizeof table);
	int idx = 0;
    for (int p=2; p<=limit; p++)
        if (sieve[p]) {
			prime[idx++] = p;
		}

	idx = 0;
	for (int i = 2; i <= limit; i++) {
		if (sieve[i]) {
			table[i] = 0;
			idx++;
		}else {
			table[i] = prime[idx] - prime[idx - 1];
		}
	}
}

void mainFunction()
{
	int n;
	SieveOfEratosthenes(maxw);
	int idx = 0;
	while(cin >> n && n != 0){
		cout << table[n] << "\n";
		idx++;
		assert(idx!=1299709);
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
	cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}