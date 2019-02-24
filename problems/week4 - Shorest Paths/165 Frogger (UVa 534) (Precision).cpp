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
double INF = 0xffffffff;

struct point {
    int x, y;
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void mainFunction() {
    
    point points[201];
    double nodes[201][201];
    int c = 1;
    int n, i, j, k;
    int x, y;
    while (true){
        cin >> n;

        if (n == 0)
            break;
        cin.ignore();

        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                nodes[i][j] = INF;
            }
        }
    
        for (i = 1; i <= n; i++) {
            cin >> x >> y;
            points[i] = (point){x, y};
            for (j = 1; j < i; j++) {
                double d = distance(points[i].x, points[i].y, points[j].x, points[j].y);
                nodes[i][j] = nodes[j][i] = distance(points[i].x, points[i].y, points[j].x, points[j].y);
            }
        }

        for (k = 1; k <= n; k++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    if (nodes[i][k] != INF && nodes[k][j] != INF) {
                        nodes[i][j] = min(nodes[i][j], max(nodes[i][k], nodes[k][j]));
                    }
                }
            }
        }
        cout << "Scenario #" << c++ << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << nodes[1][2] << endl << endl;
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