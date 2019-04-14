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

double dot(point_t p1, point_t p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

int dblcmp(double x) {
  return (x < -eps ? -1 : x > eps);
}

double cross(point_t p1, point_t p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

bool onSeg(point_t p, point_t a, point_t b) {
	return dblcmp(cross(a - p, b - p)) == 0 && dblcmp(dot(a - p, b - p)) <= 0;
}

double dist(point_t p1, point_t p2) {
    return (p2 - p1).l();
}

// 1 normal intersected, -1 denormal intersected, 0 not intersected
int testSS(point_t a, point_t b, point_t c, point_t d) {
    if (dblcmp(max(a.x, b.x) - min(c.x, d.x)) < 0) return 0;
    if (dblcmp(max(c.x, d.x) - min(a.x, b.x)) < 0) return 0;
    if (dblcmp(max(a.y, b.y) - min(c.y, d.y)) < 0) return 0;
    if (dblcmp(max(c.y, d.y) - min(a.y, b.y)) < 0) return 0;
    int d1 = dblcmp(cross(c - a, b - a));
    int d2 = dblcmp(cross(d - a, b - a));
    int d3 = dblcmp(cross(a - c, d - c));
    int d4 = dblcmp(cross(b - c, d - c));
    if ((d1 * d2 < 0) && (d3 * d4 < 0)) return 1;
    if ((d1 * d2 <= 0 && d3 * d4 == 0) || (d1 * d2 == 0 && d3 * d4 <= 0)) return -1;
    return 0;
}

bool insidePoly(point_t *p, int n, point_t t) {
	p[0] = p[n];
	for (int i = 0; i < n; ++i) if (onSeg(t, p[i], p[i + 1])) return true;
	point_t r = point_t(2353456.663, 5326546.243); // random point
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (testSS(t, r, p[i], p[i + 1]) != 0) ++cnt;
	}
	return cnt & 1;
}

void mainFunction()
{
    int t;
    cin >> t;
    int x1, x2, y1, y2;
    int xt, yt, xb, yb;
    point_t points[5];
    point_t p1;
    point_t p2;
    while(t--){
        cin >> x1 >> y1 >> x2 >> y2 >> xt >> yt >> xb >> yb;
        points[4] = point_t(xt, yt);
        points[3] = point_t(xb, yt);
        points[1] = point_t(xt, yb);
        points[2] = point_t(xb, yb);
        p1 = point_t(x1, y1);
        p2 = point_t(x2, y2);
        if (testSS(p1, p2, points[1], points[2]) != 0 ||
            testSS(p1, p2, points[1], points[3]) != 0 ||
            testSS(p1, p2, points[3], points[4]) != 0 ||
            testSS(p1, p2, points[2], points[4]) != 0 ||
            insidePoly(points, 4, p1) ||
            insidePoly(points, 4, p2)
        ) {
            cout << "T\n";
        }else {
            cout << "F\n";
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