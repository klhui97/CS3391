#include <iostream>
using namespace std;

int main() {
    int a, b, c, t;
    scanf("%d",&t);
    int caseNumber = 1;
    while (t != 0) {
        scanf("%d %d %d",&a,&b,&c);
        if ((a > b && b > c) || (a < b && b < c)) {
            printf("Case %d: %d\n", caseNumber++, b);
        }else if ((a > c && c > b) || (a < c && c < b)) {
            printf("Case %d: %d\n", caseNumber++, c);
        }else {
            printf("Case %d: %d\n", caseNumber++, a);
        }
        t--;
    }
    
    
    return 0;
}
