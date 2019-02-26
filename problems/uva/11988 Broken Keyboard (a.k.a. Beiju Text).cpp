#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<string> res;
    string line;
    cin.sync_with_stdio(false);
    cin.tie(0);
    
    while(cin >> line){
        bool end = true;
        
        auto it = line.begin();
        auto head = it;
        auto tail = line.end();
        
        while(1){
            while(it != tail && *it != '[' && *it != ']' )
                it++;
            
            if (end)
                res.push_back(string(head, it));
            else
                res.push_front(string(head, it));

            if(it == tail){
                for(auto i : res)
                    cout << i ;
                cout << endl;
                res.clear();
                break;
            }
            if(*it == '[')
                end = false;
            else
                end = true;
            it++;
            head = it;
        }
        
    }
}
