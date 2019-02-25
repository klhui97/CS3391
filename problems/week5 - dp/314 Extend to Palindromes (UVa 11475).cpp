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

/*** Data Structure ***/
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <deque> // double ended queue
#include <list>  // priority queue
#include <map>
using namespace std;
#define maxn 100000 + 1
#define maxw 5

void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
			// cout << "i: " << i << " value: " << lps[i] << endl;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
				// cout << "i: " << i << " value: " << lps[i] << endl;
                i++;
            }
        }
    }
}

int KnuthMorrisPrattSearch(char *pat, char *txt)
{
    int M = strlen(pat); 
    int N = strlen(txt); 

    int lps[M]; 
  
    computeLPSArray(pat, M, lps); 

    int i = 0;
    int j = 0;
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) {
            j = lps[j - 1];
			return N + 1;
        }
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    }
	// cout << endl << "j is: " << j << endl;
	return j;
}


void mainFunction()
{
	int dp[maxn];
	int size;
	int i, j;
	char input[maxn];
	char reverse_input[maxn];
	char *s;
	char *rs;

	while (gets(input))
	{
		s = input;
		size = strlen(s);
		
		// cout << size << endl;
		j = 0;
		for (i = size - 1; i >= 0; i--) {
			reverse_input[j++] = input[i];
		}
		reverse_input[j] = 0;
		rs = reverse_input;
		j = KnuthMorrisPrattSearch(reverse_input, input);
		cout << input;
		if (j <= size) {
			cout << &rs[j] << endl;
		}else {
			cout << endl;
		}
		if (cin.eof())
		{
			return;
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
		cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3] << " " << int(rand() % 24 + 1) << endl;
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