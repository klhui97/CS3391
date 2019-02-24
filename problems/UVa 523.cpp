/*** System Library ***/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib> // random
#include<ctime>
#include<climits> // all useful constants
#include<functional> // for hash
#include<algorithm>
#include<sstream>
#include<iomanip>

/*** Data Structure ***/
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<deque> // double ended queue
#include<list> // priority queue
using namespace std;
int INF = 0xffffffff;
#define N 1001
int dist[N][N];
int nxt[N][N];
int tax[N];

void mainFunction() {
	int t;
	int tmp;
	int n;
	int i, j;
	int city1, city2;
	cin >> t;
	cin.ignore();
	cin.ignore();
	string line;
	bool first_cout = true;

	while(t--){
		getline(cin, line);

		n = 0;
		i = j = 1;
		
		// First line
		stringstream ss(line);
		while(ss >> tmp) {
			dist[i][j++] = tmp;
			n++;
		}

		// Others
		for (i = 2; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				cin >> dist[i][j];
			}
		}
		
		// Tax
		for (i = 1; i <= n; i++) {
			cin >> tax[i];
		}

		for (int i = 1; i <= n; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				nxt[i][j] = j;
			}
		}
 
		// floyd
		for (int k = 1; k <= n; ++ k) {
			for (int i = 1; i <= n; ++ i) {
				for (int j = 1; j <= n; ++ j) {
					if (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j] + tax[k]) {
						if (dist[i][k] != -1 && dist[k][j] != -1) {
							dist[i][j] = dist[i][k] + dist[k][j] + tax[k];
							nxt[i][j] = nxt[i][k];
						}
					}
				}
			}
		}
			
		// City
		cin.ignore();
		while (getline(cin, line) && !line.empty()) {
			stringstream ss(line);
			ss >> city1 >> city2;
			int total_cost = dist[city1][city2];
			if (!first_cout)
				cout << endl;
			else
				first_cout = false;
			cout << "From " << city1 << " to " << city2 << " :" << endl;
			cout << "Path: " << city1;
			while (city1 != city2) {
				cout << "-->" << nxt[city1][city2];
				city1 = nxt[city1][city2];
			}
			cout << endl << "Total cost : " << total_cost << endl;
		}
		
	}
	
}

void testCaseGenerator() {
	int d[24];
	for (int i = 1; i < 25; i++) {
		d[i - 1] = i;
	}
	for (int i = 0; i < 100; i++) {
		// random_shuffle(begin(d), end(d));
		cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << int(rand() % 24 + 1) << endl;
	}
}

int main() {
	// freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}