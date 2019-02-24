#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <iomanip>
#define N 21

using namespace std;

void mainFunction() {
    int i, j, next = 0;
    int t = 1;
    int n;
    while(cin >> n && cin) {
        int graph[N][N] = {};
        for(i = 1; i < 20; i++) {
            if(i != 1)
                cin >> n;
            while(n--) {
                cin >> next;
                graph[i][next] = 1;
                graph[next][i] = 1;
            }
        }
        // k is the intermedia point
        // if i -> k + k -> j is smaller than i -> j
        // i -> k + k -> j becomes the shorest path
        for(int k = 1; k < N; k++) {
            for(i = 1; i < N; i++) {
                for(j = 1; j < N; j++) {
                    if(graph[i][j] == 0 || graph[i][j] > graph[i][k] + graph[k][j]) {
                        if(graph[i][k] && graph[k][j])
                            graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        cin >> n;
        cout << "Test Set #" << t++ << endl;
        int start, end;
        while(n--) {
            cin >> start >> end;
            cout << setw(2) << start << " to " << setw(2) << end << ": " << graph[start][end] << endl;
        }
        cout << endl;
    }
}

int main() {
    mainFunction();
    return 0;
}