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
#define ull unsigned long long
#define DUBUG true
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 65536
#define maxw 5
#define INF 0x3f3f3f3f

int nonprime[64] = {};
int nonprimeIdx = 0;
void SieveOfEratosthenes(int n)
{
    bool isprime[n+1];
    memset(isprime, true, sizeof(isprime));

    for (int p=2; p*p<=n; p++)
    {
        if (isprime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                isprime[i] = false;
        }
    }

    for (int p=2; p<=n; p++)
		if (!isprime[p])
			nonprime[nonprimeIdx++] = p;
}

ull upow(ull x, int p) {
	if (p == 0)
		return 1;
	if (p == 1)
		return x;
	return x * upow(x, p - 1);
}

void mainFunction()
{
	SieveOfEratosthenes(64);
	set<ull> s;
	ull j;
	int idx;
	s.insert(1);
	for (ull i = 2; i < 65536; i++) {
		idx = 0;
		while(idx < nonprimeIdx && nonprime[idx] * log2(i) < 64){
			j = upow(i, nonprime[idx]);
			s.insert(j);
			idx++;
			// $(j);
		}
		s.insert(j);
	}
	for(set<ull>::iterator it = s.begin(); it != s.end(); it++) {
		cout << *it << "\n";
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