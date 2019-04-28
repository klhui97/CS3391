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

#define maxn 2000000
#define maxw 1000
#define INF 0x3f3f3f3f

int weight[2000005];
int ans[2000005];
int composite[(maxn>>6)+1];
int primes[149032];

bool isPrime(int x){
    return x==2 || (x>2 && (x&1) && !(composite[x>>6]&(1<<((x>>1)&63))));
}

// A function to print all prime factors of a given number n 
int primeFactors(int n) 
{
	int cnt = 1;
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
		cnt++;
        // printf("%d ", 2); 
        n = n/2; 
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
	int sqrn = sqrt(n);
    for (int i = 0; primes[i] <= sqrn; i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%primes[i] == 0) 
        { 
			cnt++;
            // printf("%d ", i); 
            n = n/primes[i]; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) {
		cnt++;
		// printf ("%d", n);
	}

	return cnt;
}

void bitwiseSieve() {
    for(int i=3;i<=int(sqrt(maxn));i+=2)
    {
        if(!(composite[i>>6]&(1<<((i>>1)&63)))){
            for(int j=i*i;j<=maxn;j+=i+i)
                composite[j>>6]|=(1<<((j>>1)&63));
        }
    }
	int cnt = 0;
	ans[1] = 1;
	ans[2] = 2;
	weight[1] = 2;
	weight[2] = 2;
    for (int i = 3; i <= maxn; i++) {
		ans[i] = i;
        if (isPrime(i)) {
			primes[cnt++] = i;
		}
		weight[i] = primeFactors(i);
    }
}

int cmp(int a, int b) {
	if (weight[a] != weight[b])
		return weight[a] < weight[b];
	return a < b;
}

void mainFunction()
{
	bitwiseSieve();
	sort(ans + 1, ans + 2000000, cmp);
	int t;
	int c = 1;
	// for (int i = 1; i <= 100; i++) {
	// 	cout << i << " " << ans[i] << " " << weight[ans[i]] << "\n";
	// }
	while (cin >> t && t) {
		cout << "Case " << c++ << ": " << ans[t] << "\n";
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