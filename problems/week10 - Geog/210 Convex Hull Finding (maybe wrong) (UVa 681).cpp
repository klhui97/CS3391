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

#define maxn 520
#define maxw 5
#define INF 0x3f3f3f3f

int n;

#define eps 1e-6

struct point_t {
  double x, y;
  point_t() { }
  point_t(double tx, double ty) : x(tx), y(ty) { }
  point_t operator-(const point_t &r) const { return point_t(x - r.x, y - r.y); }
  point_t operator+(const point_t &r) const { return point_t(x + r.x, y + r.y); }
  point_t operator*(double r) const { return point_t(x * r, y * r); }
  point_t operator/(double r) const { return point_t(x / r, y / r); }
  point_t rot90() const { return point_t(-y, x); }
  double l() const { return sqrt(x * x + y * y); }
  void read() { scanf("%lf%lf", &x, &y); }
};

int dblcmp(double x) {
  return (x < -eps ? -1 : x > eps);
}

double cross(point_t p1, point_t p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

bool cmp(const point_t p1, const point_t p2) {
    return dblcmp(p1.y - p2.y) == 0 ? p1.x < p2.x : p1.y < p2.y;
}

int graham(point_t *p) {
    int top = 2; static point_t sk[maxn];
    sort(p + 1, p + 1 + n, cmp);
    sk[1] = p[1], sk[2] = p[2];
    for (int i = 3; i <= n; ++i) {
        while (top >= 2 && dblcmp(cross(p[i] - sk[top - 1], sk[top] - sk[top - 1])) >= 0) --top;
        sk[++top] = p[i];
    }
    int ttop = top;
    for (int i = n - 1; i >= 1; --i) {
        while (top > ttop && dblcmp(cross(p[i] - sk[top - 1], sk[top] - sk[top - 1])) >= 0) --top;
        sk[++top] = p[i];
    }
    for (int i = 1; i < top; ++i) p[i] = sk[i];
        return --top;
}

void mainFunction()
{
	int t;
    int i, j;
    int x1, y1;
    point_t points[maxn];
    bool ans[maxn];
    cin >> t;
    cout << t << "\n";
    while(t--){
        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> x1 >> y1;
            points[i] = point_t(x1, y1);
        }
        int top = graham(points);
        cout << top + 1 << "\n";
        for (i = 1; i <= top; i++) {
            cout << points[i].x << " " << points[i].y << "\n";
        }
        cout << points[1].x << " " << points[1].y << "\n";
        if (t != 0) {
            cout << "-1\n";
            cin >> n;
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
		cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << int(rand() % 24 + 1) << "\n";
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