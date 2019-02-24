#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#define N 10001

struct node
{
    int v, next;
};

void mainFunction() {
    bool visited[N];
    node nodes[N];
    int adj_count[N];

    int t;
    cin >> t;
    while(t--) {
        int n, m, l;
        int x, y;
        int k;
        memset(visited, false, sizeof visited);
        memset(adj_count, -1, sizeof adj_count);
        int idx = 0;

        cin >> n >> m >> l;
        while(m--){
            cin >> x >> y;
            nodes[idx] = (node){y, adj_count[x]};
            adj_count[x] = idx++;
        }
        queue<int> Q;
        while(l--){
            cin >> k;
            if (!visited[k]) {
                visited[k] = true;
                Q.push(k);
            }
        }

        int ans = 0;
        while (!Q.empty()) {
            ++ans;
            int now = Q.front();
            Q.pop();

            for (int i = adj_count[now]; i != -1; i = nodes[i].next) {
                int v = nodes[i].v;
                if (!visited[v]) {
                    visited[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << ans << endl;
    }
}

int main() {
    mainFunction();
    return 0;
}