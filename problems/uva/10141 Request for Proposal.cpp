#include <iostream>

using namespace std;

string temp, name, bestName;

int main() {
    int n, p, T = 0;
    while (~scanf("%d %d", &n, &p) && n) {
        
        getchar();
        for (int i = 0 ; i < n ; ++ i)
            getline(cin, temp);
        
        int     maxm = 0, number;
        double    cost = 0, price;
        while (p-- != 0) {
            getline(cin, name);
            scanf("%lf %d", &price, &number);
            
            getchar();
            for (int j = 0; j < number; j++) {
                getline(cin, temp);
            }
            
            if ((maxm < number) || (maxm == number && cost > price)) {
                maxm = number;
                cost = price;
                bestName  = name;
            }
        }
        
        if (T ++)
            printf("\n");
        cout << "RFP #" << T << endl;
        cout << bestName << endl;
    }
    return 0;
}
