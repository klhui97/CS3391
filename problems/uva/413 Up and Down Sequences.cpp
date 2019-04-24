#include <iostream>

using namespace std;

int main()
{
    int d;
    
    while(cin >> d) {
        float upStep = 0;
        float upCount = 0;
        float downStep = 0;
        float downCount = 0;
        int nInput = 1;
        
        if (d == 0) {
            return 0;
        }
        
        int prev = d;
        int direction = 0;
        int tempCount = 0;
        while (cin >> d) {
            if (d == 0) {
                break;
            }
            
            nInput++;
            if (d > prev) {
                if (direction == -1) {
                    downStep += tempCount;
                    downCount++;
                    tempCount = 0;
                }
                direction = 1;
                tempCount++;
            }else if (d == prev) {
                tempCount++;
            }else {
                if (direction == 1) {
                    upStep += tempCount;
                    upCount++;
                    tempCount = 0;
                }
                direction = -1;
                tempCount++;
            }
            prev = d;
        }
        
        if (direction == 1) {
            upStep += tempCount;
            upCount++;
        }else if (direction == -1) {
            downStep += tempCount;
            downCount++;
        }
        
        if (upCount > 0 && downCount > 0) {
            printf("Nr values = %d:  %f %f\n", nInput, upStep / upCount, downStep / downCount);
        }else if (upCount > 0) {
            printf("Nr values = %d:  %f %f\n", nInput, upStep / upCount, 0.0);
        }else if (downCount > 0) {
            printf("Nr values = %d:  %f %f\n", nInput, 0.0, downStep / downCount);
        }else {
            printf("Nr values = %d:  %f %f\n", nInput, 0.0, 0.0);
        }
        
        
    }
    
    return 0;
}
