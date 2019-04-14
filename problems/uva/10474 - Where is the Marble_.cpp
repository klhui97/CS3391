#include <iostream>
#include <algorithm>

using namespace std;

bool compare (const int &a, const int &b) {
    return a < b;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    int mNum;
    int caseN = 1;
    int marbles[10000];
    
    while(cin >> mNum) {
        int t;
        cin >> t;
        
        if (mNum == 0 && t == 0)
        return 0;
        
        cout << "CASE# " << caseN++ << ":\n";
        
        for (int i = 0; i < mNum; i++) {
            cin >> marbles[i];
        }
        sort(marbles, marbles + mNum, compare);
        
        while (t-- > 0) {
            int key;
            
            cin >> key;
            int loc = -1;
            int low = 0;
            int high = mNum - 1;
            
            while (low <= high) {
                int mid = (low + high) / 2;
                if (marbles[mid] == key) {
                    loc = mid;
                    high = mid - 1;
                }else if (marbles[mid] > key) {
                    high = mid - 1;
                }else {
                    low = mid + 1;
                }
            }
            
            if (loc == -1) {
                cout << key << " not found\n";
            }else {
                cout << key << " found at " << loc + 1 << "\n";
            }
        }
    }
    
    return 0;
}
