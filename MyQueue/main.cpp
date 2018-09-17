#include <iostream>
#include <stack>
#include <queue>
#include <cassert>

using namespace std;

class MyQueue {
public:
    MyQueue() = default;

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        stack1.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        assert(not(stack1.empty() and stack2.empty()));
        if(stack2.empty()) {
            while(!stack1.empty()) {
                int ele = stack1.top();
                stack1.pop();
                stack2.push(ele);
            }
        }
        int ele = stack2.top();
        stack2.pop();
        return ele;
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        assert(not(stack1.empty() and stack2.empty()));
        if(stack2.empty()) {
            while(!stack1.empty()) {
                int ele = stack1.top();
                stack1.pop();
                stack2.push(ele);
            }
        }
        return stack2.top();
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};


int main() {
    auto queue = new MyQueue();
    queue->push(1);
    cout << queue->pop() << endl;
    queue->push(2);
    queue->push(3);
    cout << queue->top() << endl;
    return 0;
}