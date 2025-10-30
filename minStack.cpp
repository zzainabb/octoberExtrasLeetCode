#include <iostream>
#include <stack>
#include <algorithm> 
#include <optional>


class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minTrackerStack;

public:
    MinStack() {
        
    }

    void push(int val) {
        mainStack.push(val);
        if (minTrackerStack.empty() || val <= minTrackerStack.top()) {
            minTrackerStack.push(val);
        }
    }

    void pop() {
        if (mainStack.empty()) {
            return; 
        }
        if (mainStack.top() == minTrackerStack.top()) {
            minTrackerStack.pop();
        }
        mainStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minTrackerStack.top();
    }
};

