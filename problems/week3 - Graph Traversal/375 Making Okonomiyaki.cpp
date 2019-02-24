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
#include<cstring>

/*** Data Structure ***/
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<deque> // double ended queue
#include<list> // priority queue
using namespace std;
#define N 35

struct state
{
	int c[4];
	int steps;
};

int visited[N][N][N][N];
int c[4];
queue<state> states;

void fill(state tmp, int i) {
    tmp.c[i] = c[i];
    tmp.steps++;
    if (!visited[tmp.c[0]][tmp.c[1]][tmp.c[2]][tmp.c[3]]) {
        visited[tmp.c[0]][tmp.c[1]][tmp.c[2]][tmp.c[3]] = true;
        states.push(tmp);
    }
}

void fill_target(state tmp, int target, int source) {
    int available = tmp.c[source];
    int required = c[target] - tmp.c[target];
    if (tmp.c[target] + tmp.c[source] <= c[target]) {
        tmp.c[target] += tmp.c[source];
        tmp.c[source] = 0;
    }else {
        int required = c[target] - tmp.c[target];
        tmp.c[target] += required;
        tmp.c[source] -= required;
    }
    tmp.steps++;
    if (!visited[tmp.c[0]][tmp.c[1]][tmp.c[2]][tmp.c[3]]) {
        visited[tmp.c[0]][tmp.c[1]][tmp.c[2]][tmp.c[3]] = true;
        states.push(tmp);
    }
}

void empty(state tmp, int i) {
    tmp.c[i] = 0;
    tmp.steps++;
    if (!visited[tmp.c[0]][tmp.c[1]][tmp.c[2]][tmp.c[3]]) {
        visited[tmp.c[0]][tmp.c[1]][tmp.c[2]][tmp.c[3]] = true;
        states.push(tmp);
    }
}

void mainFunction() {
    
    int t;
    while (cin >> c[0] >> c[1] >> c[2] >> c[3] >> t) {
        if (t > c[0] && t > c[1] && t > c[2] && t > c[3]) {
            cout << -1 << endl;
            continue;
        }
        memset(visited, false, sizeof visited);
        while (!states.empty()) {
            states.pop();
        }
        
        state firstState = {{0, 0, 0, 0}, 0};
        state tmp;
        states.push(firstState);
        visited[0][0][0][0] = true;
        bool found = false;
        while (!states.empty()) {
            tmp = states.front();
            states.pop();
            if (tmp.c[0] == t || tmp.c[1] == t || tmp.c[2] == t || tmp.c[3] == t) {
                cout << tmp.steps << endl;
                found = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                fill(tmp, i);
                empty(tmp, i);
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i != j) {
                        fill_target(tmp, i, j);
                    }
                }
            }
        }
        if (!found) {
            cout << -1 << endl;
        }
    }
}

void testCaseGenerator() {
    int d[24];
    for (int i = 1; i < 25; i++) {
        d[i - 1] = i;
    }
    for (int i = 0; i < 100; i++) {
        random_shuffle(begin(d), end(d));
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