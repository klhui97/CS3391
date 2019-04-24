#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int t;
    
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    cin.get();
    
    while(t-- > 0){
        stack<char> s;
        string line;
        bool isOk = true;
        
        getline(cin, line);
        
        int i = 0;
        while (i < line.size() && isOk) {
            if (line[i] == '[') {
                s.push(']');
            }else if (line[i] == '(') {
                s.push(')');
            }else {
                if (!s.empty() && s.top() == line[i]) {
                    s.pop();
                }else {
                    isOk = false;
                }
            }
            i++;
        }
        
        if (isOk && s.empty()) {
            cout << "Yes\n" ;
        }else {
            cout << "No\n" ;
        }
        
    }
    
    return 0;
}
