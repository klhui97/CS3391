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

#define PI M_PI
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
};

int dblcmp(double x) {
    return (x < -eps ? -1 : x > eps);
}

ll C(int a, int b)
{
    ll aa = a, bb = b, ans = 1;
    for (int i = 0; i < b; i++)ans *= (aa - i);
    for (int i = 2; i <= b; i++)ans /= i;
    return ans;
}

double ans[2000];
point_t p[700];

void mainFunction()
{
	int t;
    cin >> t;
    while (t--)
    {
        int n;
		cin >> n;
        for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
        }
        long long re=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                double tmp = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
                if (dblcmp(tmp) <= 0)
                    tmp += 2 * PI;
                j < i ? ans[j] = tmp : ans[j - 1] = tmp;
            }
            sort(ans, ans + n - 1);
            int k = 1;
            long long re2 = 0;
            for (int j = 0; j < n - 1; j++)
                ans[j + n - 1] = ans[j] + 2 * PI;
            for (int j = 0; j < n - 1; j++) {
                while (fabs(ans[k] - ans[j]) - PI < 0) {
                    k++;
                }
                if (k - j - 1 >= 2)
                    re2 += C(k - j - 1, 2);
            }
            re += C(n - 1, 3) - re2;
        }
        cout << C(n, 4) - re << "\n";
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