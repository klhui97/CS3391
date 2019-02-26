#include <iostream>
using namespace std;


int main() {
    int h, u, d, f;
    
    while (true) {
        scanf("%d %d %d %d", &h, &u, &d, &f);
        if (h == 0) {
            return 0;
        }
        
        int day = 0;
        double step = u * 1.0;
        double feet = 0;
        double drop = step * (f / 100.0);
        while (feet >= 0 && feet <= h) {
            day++;
            // day
            feet += step;
            if (feet > h) {
                break;
            }
            // night
            feet -= d;
            step -= drop;
            if (step < 0) {
                step = 0;
            }
        }
        
        if (feet >= h) {
            printf("success on day %d\n", day);
        }else if (feet + step > h) {
            printf("success on day %d\n", ++day);
        }else if (step <= 0 && feet >= 0){
            printf("failure on day %d\n", ++day);
        }else {
            printf("failure on day %d\n", day);
        }
        
    }
    
    return 0;
}
