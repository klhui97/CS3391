#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
#define INF 0x3f3f3f3f3f
const int N = 100005;
long long l, r, vis[N * 10], prime[N], pn = 0;
 
int main() {
	for (long long i = 2; i < N; i++) {
		if (vis[i]) continue;
		prime[pn++] = i;
		for (long long j = i; j < N; j += i)
			vis[j] = 1;
 	}
 	while (~scanf("%lld%lld", &l, &r)) {
 		memset(vis, 0, sizeof(vis));
 		for (long long i = 0; i < pn; i++) {
  			for (long long j = (l / prime[i] + (l % prime[i] != 0)) * prime[i]; j <= r; j += prime[i]) {
  				if (j / prime[i] != 1)
  					vis[j - l] = 1;
     		}
		}
		long long pre = -1;
		long long Max = 0, Min = INF;
		long long maxl, maxr, minl, minr, flag = 1;
		for (long long i = l; i <= r; i++) {
			if (vis[i - l] || i == 1) continue;
			if (pre != -1) {
				if (i - pre > Max) {
			 		Max = i - pre;
			 		maxl = pre; maxr = i;
    			}
    			if (i - pre < Min) {
    				Min = i - pre;
    				minl = pre; minr = i;
       			}
				flag = 0;
   			}
   			pre = i;
  		}
  		if (flag) printf("There are no adjacent primes.\n");
  		else printf("%lld,%lld are closest, %lld,%lld are most distant.\n", minl, minr, maxl, maxr);
  	}
	return 0;
}