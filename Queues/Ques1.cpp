#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
    }
    
    void push(int x) {
        this->s1.push(x);
        return;
    }
    
    int pop() {
        if(this->s2.empty()){
            if(this->s1.empty()){
                cout<<"Underflow!!!\n";
                exit(1);
            }
            else{
                while(!this->s1.empty()){
                    int x = this->s1.top();
                    this->s1.pop();
                    this->s2.push(x);
                }
            }
        }
        int res = this->s2.top();
        this->s2.pop();
        return res;
    }
    
    int peek() {
        if(!this->s2.empty()){
            return (this->s2.top());
        }
        else{
            while(!this->s1.empty()){
                this->s2.push(this->s1.top());
                this->s1.pop();
            }
            return (this->s2.top());
        }
    }
    
    bool empty() {
        return (this->s1.empty() && this->s2.empty());
    }
};