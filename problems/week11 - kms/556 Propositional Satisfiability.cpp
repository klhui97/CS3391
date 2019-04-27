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

stack<char> op;
stack<bool> sv;

int rankk(char c) {
	if( c =='!' )
		return 3;
	else if( c =='&' )
		return 2;
	else if( c =='+' )
		return 1;
	return 0;
}

void solve() {
	char c = op.top();
	op.pop();

	if(c =='!') {
		bool a = sv.top();
		sv.pop();
		sv.push(!a);
	}else if(c == '&') {
		bool a = sv.top();
		sv.pop();
		bool b = sv.top();
		sv.pop();
		sv.push( a&&b );
	}else if(c == '+') {
		bool a = sv.top();
		sv.pop();
		bool b = sv.top();
		sv.pop();
		sv.push(a || b);
	}
}

void mainFunction()
{
	char input[200];
	while(gets(input)){
		sv = stack<bool>();
		op = stack<char>();

		for(int i = 0; input[i]; ++i){
			if( input[i] == ' ')
				continue;

			char c = input[i];

			if( input[i] >='a' && input[i] <='z' ) {
				sv.push(true);
			}else if( c == '(' ) {
				op.push( c );
			}else if( c ==')' ){
				while( op.top() != '('  )
					solve();
				op.pop();
			}else if( c =='!' || c =='&' || c == '+' ) {
				while( !op.empty() &&  rankk( op.top() ) >= rankk( c ) )
					solve();
				op.push( c );
			}
		}

		while(!op.empty())
			solve();
		
		if (sv.top()) {
			cout << "YES\n";
		}else {
			cout << "NO\n";
		}
	}
}

int main()
{
	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	mainFunction();
	return 0;
}