#include <iostream>
using namespace std;


int main() {
    int duration, nRecord, month;
    double downPayment, loan, rate, deprecations[101];
    
    while (true) {
        cin >> duration >> downPayment >> loan >> nRecord;
        if (duration < 0) {
            break;
        }
        
        while (nRecord != 0) {
            cin >> month >> rate;
            for (int i = month; i < duration; i++)
                deprecations[i] = rate;
            nRecord--;
        }
        
        int now = 0;
        int carValue = (loan + downPayment) * (1 - deprecations[now]);
        int monthlyPayment = loan/duration;
        
        while (carValue < loan && now < duration) {
            now++;
            carValue = carValue * (1 - deprecations[now]);
            loan -= monthlyPayment;
        }
        
        if (now == 1) {
            printf("1 month\n");
        }else {
            printf("%d months\n", now);
        }
    }
    
    
    return 0;
}
