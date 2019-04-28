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

int findGcd(int a, int b) {
    if (a == 0)
        return b;
    return findGcd(b%a, a);
}

/**
* navSign: if number < 0, set it to true. otherwise false
* **/
string solve(string integer, string point, string recurring) {
    string res;
	int ivalue = stoi(integer);
    ivalue < 0 ? res = "-": res = "";
    ivalue = abs(ivalue);

	int ppow = point.length(), rpow = recurring.length();
	int pvalue = 0;
	int rvalue = 0;
	if (ppow > 0)
		pvalue += stoi(point);
	if (rpow > 0)
		rvalue += stoi(recurring);

	if (ppow == 0 && rpow == 0) {
		res += to_string(ivalue);
		res += "/";
		res += "1";
	}else {
		 // num = convert point & recurring into integer
		// it is multiplied by 10^(ppow + rpow)
		int num = pvalue * pow(10, rpow) + rvalue;
		int den = pow(10, ppow + rpow);
		if (rpow > 0) {
			den -=  pow(10, ppow);
			num -= pvalue;
		}

		int gcd = findGcd(num, den);

		// append numerator
		res += to_string((den * ivalue + num) / gcd);
		res += "/";
		// append denominator
		res += to_string(den / gcd);
	}
    return res;
}

void mainFunction()
{
	int t;
	string s;
	int cnt = 1;
	while(cin >> t && t != -1){
		string point = "";
		string recur = "";
		cin >> s;
		for (int i = 2; i < s.length(); i++) {
			if (i + t < s.length()) {
				point += s[i];
			}else {
				recur += s[i];
			}
		}
		cout << "Case " << cnt++ << ": " << solve("0", point, recur) << "\n";
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