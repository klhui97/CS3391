/*** System Library  ***/
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

const double r0 = 0.000001;
double d, px, py, vx, vy;

bool solve(){
	if(abs(px * vy - vx * py) >= r0) return false;
	
	double xsum = px + vx;
	double ysum = py + vy;
	
	double dist = sqrt(xsum * xsum + ysum * ysum);
	double pdist = sqrt(px * px + py * py); 
	double vdist = sqrt(vx * vx + vy * vy);
	
	if(dist<pdist || dist<vdist){
		return (abs(pdist-d) < r0) || (pdist < d);
	}else{
        double acc = 2 - pdist;
        return (abs(acc-d)<r0) || (d>acc);
	}
}

void mainFunction()
{
	while(cin >> d && d){
		cin >> px >> py >> vx >> vy;
		
		if(solve())
			cout  << "possible\n";
		else
            cout  << "impossible\n";
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