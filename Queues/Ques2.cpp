#include <bits/stdc++.h>
using namespace std;

class DataStream {
public:
    int value;
    int k;
    queue<int> q;
    unordered_map<int, int> map;
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        q.push(num);
        map[num]++;
        if(q.size() > k){
            int x = q.front();
            q.pop();
            map[x]--;
            if(map[x] == 0){
                map.erase(x);
            }
        }
        if(q.size() < k){
            return false;
        }
        if(map.size() == 1){
            for(auto it : map){
                if(it.first == value){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }
};