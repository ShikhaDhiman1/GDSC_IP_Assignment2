#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> visited;
        stack <char> st;
        for(int i = 0; i < s.size(); i++){
            if(visited[s[i]] == 1) continue;
            while(!st.empty() && st.top() > s[i] && s.find_last_of(st.top()) > i){
                visited[st.top()] = 0;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]] = 1;
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};