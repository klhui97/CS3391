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

#define maxn 10
#define maxw 5
#define INF 0x3f3f3f3f

struct suffix 
{ 
    int index;
    int rank[2];
}; 

int cmp(struct suffix a, struct suffix b) 
{ 
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0): 
           (a.rank[0] < b.rank[0] ?1: 0); 
} 

vector<int> buildSuffixArray(string txt, int n) 
{
    struct suffix suffixes[n]; 

    for (int i = 0; i < n; i++) 
    { 
        suffixes[i].index = i; 
        suffixes[i].rank[0] = txt[i] - 'A'; 
        suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'A'): -1; 
    } 

    sort(suffixes, suffixes+n, cmp);
    int ind[n];

    for (int k = 4; k < 2*n; k = k*2) 
    { 
        int rank = 0; 
        int prev_rank = suffixes[0].rank[0]; 
        suffixes[0].rank[0] = rank; 
        ind[suffixes[0].index] = 0; 
  
        for (int i = 1; i < n; i++) 
        { 
            if (suffixes[i].rank[0] == prev_rank && 
                    suffixes[i].rank[1] == suffixes[i-1].rank[1]) 
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = rank; 
            } 
            else
            { 
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = ++rank; 
            } 
            ind[suffixes[i].index] = i; 
        } 

        for (int i = 0; i < n; i++) 
        { 
            int nextindex = suffixes[i].index + k/2; 
            suffixes[i].rank[1] = (nextindex < n)? 
                                  suffixes[ind[nextindex]].rank[0]: -1; 
        }
        sort(suffixes, suffixes+n, cmp); 
    } 
    vector<int>suffixArr; 
    for (int i = 0; i < n; i++) 
        suffixArr.push_back(suffixes[i].index); 
    return  suffixArr; 
} 

vector<int> kasai(string txt, vector<int> suffixArr) 
{ 
    int n = suffixArr.size(); 
  
    vector<int> lcp(n, 0);
    vector<int> invSuff(n, 0); 

    for (int i=0; i < n; i++) 
        invSuff[suffixArr[i]] = i; 

    int k = 0; 

    for (int i=0; i<n; i++) 
    {
        if (invSuff[i] == n-1) 
        { 
            k = 0; 
            continue; 
        }
        int j = suffixArr[invSuff[i]+1]; 
  
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k]) 
            k++; 
  
        lcp[invSuff[i]] = k;
        if (k>0) 
            k--; 
    }
    return lcp; 
} 

void printArr(vector<int>arr, int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

void mainFunction()
{
    string str;
	int t;
	int len;
	cin >> t;
	while(t--){
		cin >> str;
		vector<int>suffixArr = buildSuffixArray(str, str.length());
		vector<int>lcp = kasai(str, suffixArr); 
		int n = suffixArr.size();
		int maxI = -1;
		int cnt;
		int i = 0;
		// cout << "Suffix Array : \n"; 
		// for (int i = 0; i < n; i++) 
		// 	cout << &str[suffixArr[i]] << "      " << lcp[i] << "\n"; 

		while(i < n) {
			if (maxI == -1) {
				if (lcp[i] > 0) {
					maxI = i;
					cnt = 1;
					while(lcp[i] == lcp[maxI]){
						i++;
						cnt++;
					}
					continue;
				}
			}else {
				if (lcp[i] > lcp[maxI]) {
					maxI = i;
					cnt = 1;
					while(lcp[i] == lcp[maxI]){
						i++;
						cnt++;
					}
					continue;
				}
			}
			i++;
		}
		
		if (maxI != -1) {
			for (int i = suffixArr[maxI]; i < suffixArr[maxI] + lcp[maxI]; i++) 
				cout << str[i];
			cout << " " << cnt << "\n";
		}else {
			cout << "No repetitions found!\n";
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
	// cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}