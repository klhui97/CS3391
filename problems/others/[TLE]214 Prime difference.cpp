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
#define $(x)                                         \
	{                                                \
		if (DUBUG)                                   \
			cout << #x << " = " << x << " " << endl; \
	}
#define _(x)                                 \
	{                                        \
		if (DUBUG)                           \
			cout << #x << " = " << x << " "; \
	}

#define maxn 1299709 + 1
#define maxw 5
#define INF 0x3f3f3f3f

using namespace std;

bool isprime[maxn];
int prime[maxn];
int cnt = 0;

void SieveOfEratosthenes(int n)
{
    
    memset(isprime, true, sizeof(isprime));

    for (int p=2; p*p<n; p++)
    {
        if (isprime[p] == true)
        {
            for (int i=p*p; i<n; i += p)
                isprime[i] = false;
        }
    }

    // Print all isprime numbers
    for (int p=2; p<n; p++)
		if (isprime[p])
			prime[cnt++] = p;
}

void mainFunction()
{
	int n;
	SieveOfEratosthenes(maxn);
	
	while(cin >> n && n){
		if(isprime[n]){
            cout << 0 << endl;
        }else {
			int mid, low, high;
			low = 0;
			high = cnt - 1;
			while(low <= high){
				mid = (low + high) / 2;
				if (prime[mid] > n) {
					high = mid - 1;
				}else if (prime[mid] < n) {
					low = low + 1;
				}
			}
			cout << prime[high + 1] - prime[high] << endl;
		}
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