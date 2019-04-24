#include <iostream>
#include <algorithm>
using namespace std;

int findMid(int *a, const int &n, int key) {
    int loc = -1;
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] > key) {
            loc = mid;
            high = mid - 1;
        }else if (a[mid] < key) {
            low = mid + 1;
        }else {
            loc = mid;
            if (mid + 1 < n && a[mid + 1] == key) {
                low = mid + 1;
            }else {
                return mid;
            }
        }
    }
    
    return loc;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    int nBook;
    int bookPrices[10000];
    
    while (cin >> nBook && !cin.eof()) {
        for (int i = 0; i < nBook; i++) {
            cin >> bookPrices[i];
        }
        
        sort(bookPrices, bookPrices + nBook);
        
        int sum;
        cin >> sum;
        
        int j = findMid(bookPrices, nBook, sum / 2);
        int i = j - 1;
        
        while (i >= 0 && j < nBook) {
            if (bookPrices[j] + bookPrices[i] == sum) {
                break;
            }else if (sum - bookPrices[i] > bookPrices[j]) {
                j++;
            }else {
                i--;
            }
        }
        
        cout << "Peter should buy books whose prices are " << bookPrices[i] << " and " << bookPrices[j] << ".\n\n";
    }
    
    return 0;
}
