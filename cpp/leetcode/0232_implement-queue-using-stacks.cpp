#include <stack>

using namespace std;

class MyQueue {
  public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
    }
    void push(int x) {
        st1.push(x);
    }
    int pop() {
        int x = peek();
        if(!st2.empty()){
            st2.pop();
        }else{
            st1.pop();
        }
        return x;
    }
    int peek() {
        if (!st2.empty())
            return st2.top();
        else {
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
    bool empty() {
        return (st1.size()+st2.size())==0;
    }
};