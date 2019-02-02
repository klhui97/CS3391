#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
#include <iomanip>

using namespace std;

void mainFunction() {
    int i, j, next = 0;
    int t = 1;
    int n;
    while(cin >> n && cin) {
        int graph[21][21] = {};
        for(i = 1; i < 20; i++) {
            if(i != 1)
                cin >> n;
            while(n--) {
                cin >> next;
                graph[i][next] = 1;
                graph[next][i] = 1;
            }
        }
        for(int k = 1; k < 21; k++) {
            for(i = 1; i < 21; i++) {
                for(j = 1; j < 21; j++) {
                    if(graph[i][j] == 0 || graph[i][j] > graph[i][k]+graph[k][j]) {
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