#include <iostream>
using namespace std;


int main() {
    int totalTestCase;
    int i = 1;
    
    cin >> totalTestCase;
    
    while (i <= totalTestCase) {
        int numCreature;
        int minSpeed = 0;
        cin >> numCreature;
        
        while (numCreature-- > 0) {
            int speed;
            cin >> speed;
            minSpeed = max(minSpeed, speed);
        }
        
        printf("Case %d: %d\n", i++, minSpeed);
    }
    
    return 0;
}
