#include <iostream>

using namespace std;

int main()
{
    int numPe, budget, numHo, numWe;
    while (scanf("%d %d %d %d", &numPe, &budget, &numHo, &numWe) == 4) {
        int minPrice = budget + 1;
        
        while (numHo-- != 0) {
            int pricePerPeople, numBed;
            cin >> pricePerPeople;
            for (int i = 0; i < numWe; i++) {
                cin >> numBed;
                if (numBed >= numPe) {
                    minPrice = min(numPe * pricePerPeople, minPrice);
                }
            }
        }
        
        if (minPrice <= budget) {
            printf("%d\n", minPrice);
        }else {
            printf("stay home\n");
        }
    }
    
    return 0;
}
