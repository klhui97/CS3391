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
#define DUBUG false
#define $(x) {if (DUBUG) cout << #x << " = " << x << " " << endl;}
#define _(x) {if (DUBUG) cout << #x << " = " << x << " ";}

#define maxn 10
#define maxw 5
#define INF 0x3f3f3f3f

void mainFunction()
{
	int k, a, b, v;
	while(scanf("%d %d %d %d\n", &k, &a, &b, &v) == 4){
		int required_section = a / v;;
		if (a % v != 0) {
			required_section++;
		}
		int max_box_with_max_section = b / (k - 1);
		int remaining_divisor = b % (k - 1);
		// $(max_box_with_max_section);
		// $(remaining_divisor);
		if (required_section <= max_box_with_max_section * k) {
			int result = required_section / k;
			if (required_section % k != 0) {
				result++;
			}
			cout << result << endl;
		}else {
			int result = max_box_with_max_section;
			required_section -= max_box_with_max_section * k;
			$(result);
			$(required_section);
			// $(remaining_divisor);
			if (remaining_divisor) {
				$(remaining_divisor);
				required_section -= (remaining_divisor + 1);
				result++;
				$(result);
			}
			if (required_section > 0) {
				result += required_section;
				$(result);
			}
			$(result);
			
			cout << result << endl;
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