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


int foo(int a, int b) {
	return a %= b;
}
unsigned ModExp(unsigned a, unsigned b, unsigned c) {
	unsigned tmp;

	if(a==0) return 0;
	a%=c;

	if(b==1) return a;
	if(b==0) return (1);
	
	tmp = ModExp(a, b>>1, c);
	tmp = (tmp*tmp)%c;

	if (b&1) tmp = (tmp*a)%c;

	return tmp;
}

void mainFunction()
{
	int a , k , n , result;
  	while(cin >> a >> k >> n && cin){
		a = foo(a,n) , result = 1;
		if (n&(n-1)) {
			result = ModExp(a % n, k, n);
		}else {
			while(k--) {
				result*=a;
				result = (result)&(n-1);
				if (result == 0)
					break;
			}
		}
		
		cout << result << "\n";
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