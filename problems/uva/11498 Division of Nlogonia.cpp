#include <iostream>
using namespace std;

int main() {
    int m, n, x, y, t;
    scanf("%d",&t);
    
    while (t != 0) {
        scanf("%d %d",&n,&m);
        while(t--) {
            scanf("%d %d",&x,&y);
            
            if (abs(n) == abs(x) || abs(m) == abs(y)) {
                printf("divisa\n");
            }else if (n > x) {
                if (m > y) {
                    printf("SO\n");
                }else {
                    printf("NO\n");
                }
            }else {
                if (m > y) {
                    printf("SE\n");
                }else {
                    printf("NE\n");
                }
            }
        }
        scanf("%d",&t);
    }
    
    
    return 0;
}
