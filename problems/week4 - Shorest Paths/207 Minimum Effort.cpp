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

/*** Data Structure ***/
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <deque> // double ended queue
#include <list>  // priority queue
#include <map>
using namespace std;

bool is_number(const std::string &s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

void mainFunction()
{

	int i, j, k;
	int n, e;
	int officeIndex;
	int hallIndex;
	string place[200];
	int places[200][200];
	int nxt[200][200];
	string line;

	while (cin >> n)
	{
		// Read places
		cin.ignore();
		i = 0;
		while (i < n)
		{
			getline(cin, line);
			place[i] = line;
			if (place[i] == "office")
				officeIndex = i;
			if (place[i] == "hall")
				hallIndex = i;
			i++;
		}

		// init places
		memset(places, -1, sizeof(places));

		// Read Edges
		cin >> e;
		getline(cin, line);

		string place1, place2;
		int to, back;
		for (int i = 0; i < e; i++)
		{
			string inputLine;
			getline(cin, inputLine);
			string start = "";
			string end = "";
			int splitNum;
			int go = -1;
			int back = -1;
			int numStartP;

			for (int j = 0; j < inputLine.length(); j++)
			{
				if (inputLine[j] == ':')
				{
					for (int n = 0; n < j; n++)
						start += inputLine[n];
					splitNum = j;
				}
				if (inputLine[j] >= '0' && inputLine[j] <= '9')
				{
					bool exitCh = false;
					for (int p = j; p < inputLine.length(); p++)
						if (inputLine[p] >= 'A' && inputLine[p] <= 'z')
						{
							exitCh = true;
							break;
						}
					if (!exitCh)
					{
						bool pNameExist = false;
						string temp = inputLine.substr(splitNum + 1, j - splitNum - 2);
						for (int p = 0; p < n; p++)
						{
							if (place[p] == temp)
							{
								pNameExist = true;
								break;
							}
						}
						if (pNameExist)
						{
							numStartP = j;
							break;
						}
					}
				}
			}

			for (int n = splitNum + 1; n < numStartP - 1; n++)
				end += inputLine[n];

			string numbers = inputLine.substr(numStartP);
			stringstream stream(numbers);
			stream >> go;
			if (!stream.eof())
				stream >> back;
			int startN;
			int endN;
			for (int j = 0; j < n; j++)
			{
				if (place[j] == start)
					startN = j;
				if (place[j] == end)
					endN = j;
			}

			places[startN][endN] = go;
			if (back != -1)
				places[endN][startN] = back;
		}

		// init next
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				nxt[i][j] = j;
			}
		}

		// flody
		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (places[i][j] == -1 || places[i][j] > places[i][k] + places[k][j])
					{
						if (places[i][k] != -1 && places[k][j] != -1)
						{
							places[i][j] = places[i][k] + places[k][j];
							nxt[i][j] = nxt[i][k];
						}
					}
				}
			}
		}

		i = officeIndex;
		j = hallIndex;
		cout << places[i][j] + places[j][i] << endl;

		// Start from
		cout << place[i]; // office
		k = i;
		
		while (nxt[k][j] != j)
		{
			k = nxt[k][j];
			cout << " -> " << place[k];
		}

		// [Back] Start from k
		k = nxt[k][j];
		cout << " -> " << place[k];
		
		while (nxt[k][i] != i)
		{
			k = nxt[k][i];
			cout << " -> " << place[k];
		}

		cout << " -> " << place[i]; // office
		cout << endl
			 << endl;
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
	// freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}