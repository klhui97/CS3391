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

#define maxn 100000000
#define maxw 5
#define INF 0x3f3f3f3f

int composite[(maxn>>6)+1];

bool isPrime(int x){
    return x==2 || (x>2 && (x&1) && !(composite[x>>6]&(1<<((x>>1)&63))));
}

void mainFunction()
{
	for(int i=3;i<=int(sqrt(maxn));i+=2)
    {
        if(!(composite[i>>6]&(1<<((i>>1)&63)))){
            for(int j=i*i;j<=maxn;j+=i+i)
                composite[j>>6]|=(1<<((j>>1)&63));
        }
    }
	int n;
	int t;
	while(cin >> n){
		if (n <= 6) {
			if (n == 5) {
				cout << n << " is the sum of " << 2 << " and " << 3 << ".\n";
			}else {
				cout << n << " is not the sum of two primes!\n";
			}
		}else if (n % 2 == 0) {
			for (t = n / 2; t > 0; t--) {
				if (isPrime(t) && isPrime(n - t) && (t != n - t)) {
					break;
				}
			}
			cout << n << " is the sum of " << t << " and " << n - t << ".\n";
		}else {
			if (isPrime(n - 2)) {
				cout << n << " is the sum of " << 2 << " and " << n - 2 << ".\n";
			}else {
				cout << n << " is not the sum of two primes!\n";
			}
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
	cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}