#include <iostream>
#include <cstdlib>

using namespace std;

int fac[30];
int prim[50000];
int used[50000];

int main()
{
	for (int i = 0 ; i < 50000 ; ++ i)
		used[i] = 0;
	int save = 0;
	for (int i = 2 ; i < 50000 ; ++ i)
		if (!used[i]) {
			prim[save ++] = i;
			for (int j = 2*i ; j < 50000 ; j += i)
				used[j] = 1;
		}
	
	int n;
	while (cin >> n && n) {
		int count = 0,base = 0,m = n;
		while (n > 1 && base < save) {
			if (n%prim[base] == 0) {
				fac[count ++] = prim[base];
				while (n%prim[base] == 0)
					n /= prim[base];
			}
			base ++;
		}
		if (n > 1) fac[count ++] = n;
		
		long long ans = m;
		for (int i = 0 ; i < count ; ++ i)
			ans = ans/fac[i]*(fac[i]-1);
		
		cout << ans << endl;
	}
	return 0;
}