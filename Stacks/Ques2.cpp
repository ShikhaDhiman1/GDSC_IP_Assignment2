#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size());
        vector<int> v(nums2.size());
        stack<int> s;
        s.push(-1);
        for(int j = nums2.size()-1; j >= 0; j--){
            while(s.top() != -1 && nums2[s.top()] <= nums2[j]){
                s.pop();
            }
            v[j] = s.top();
            s.push(j);
        }
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    if(v[j] != -1){
                        ans[i] = nums2[v[j]];
                    }
                    else{
                        ans[i] = -1;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
int main(){
    // cout<<(1>2)<<endl;
    cout<<('a'<'b')<<endl;
}