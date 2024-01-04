#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // cout<<(s.length() & 1);
        if(s.length()%2 != 0) return false;
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(s[i] == ')' && !st.empty()){
                if(st.top() == '(') st.pop();
                else{
                    return false;
                }
            }
            else if(s[i] == '}' && !st.empty()){
                if(st.top() == '{') st.pop();
                else{
                    return false;
                }
            }
            else if(s[i] == ']' && !st.empty()){
                if(st.top() == '[') st.pop();
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};