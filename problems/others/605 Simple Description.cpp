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

#define maxn 10000
#define maxw 1000
#define INF 0x3f3f3f3f

struct node {
	int num;
	int min;
};

node stackIN[maxn];
node stackOUT[maxn];

int in=0;
int ot=0;

int getMin(){
	if(in > 0 && ot > 0)
		return min(stackIN[in-1].min, stackOUT[ot-1].min);
	if(ot==0) {
		int newMin = stackIN[in-1].num;
		while(in!=0){
				if(stackIN[in-1].num<newMin) newMin = stackIN[in-1].num;
				stackOUT[ ot++ ] = (node){stackIN[ in-1 ].num,newMin};
				in--;
			}
		return stackOUT[ot-1].min;
	}
	return -1; // if return -1, something wrong
}

void enq(int i){
	if(in==0) stackIN[in++] = (node){i, i};
	else{
		int eh = min(i,stackIN[in-1].min);
		stackIN[in++] = (node){i, eh};
	}
}

void dq(){
	if(ot==0){
		int newMin = stackIN[in-1].num;
		while(in!=0){
				if(stackIN[in-1].num<newMin)
					newMin = stackIN[in-1].num;
				stackOUT[ot++] = (node){stackIN[in-1].num,newMin};
				in--;
			}
	}
	ot--;
}

void mainFunction()
{
	int input;
	int cnt = 1;

	while(cin >> input && cin){
		if (cnt++ > 10000)
			dq();
		enq(input);
		cout << getMin() << "\n";
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