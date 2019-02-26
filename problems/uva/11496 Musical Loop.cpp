#include <stdio.h>
#include <stdlib.h>

int H[10005];

int main()
{
    int n;
    while (~scanf("%d",&n) && n) {
        for (int i = 1; i <= n; ++ i) {
            scanf("%d",&H[i]);
        }
        
        int count = 0;
        H[0] = H[n];
        H[n+1] = H[1];
        for (int i = 1; i <= n; ++ i) {
            if ((H[i]-H[i-1])*(H[i]-H[i+1]) > 0) {
                count ++;
            }
        }
        
        printf("%d\n",count);
    }
    
    return 0;
}
