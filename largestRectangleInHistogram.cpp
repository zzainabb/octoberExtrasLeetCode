#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;              
        long long best = 0;

        for (int i = 0; i <= n; ++i) {
            int h = (i == n) ? 0 : heights[i]; 
            while (!st.empty() && h < heights[st.top()]) {
                int mid = st.top(); st.pop();
                int left = st.empty() ? 0 : st.top() + 1;
                int right = i - 1;
                long long width = right - left + 1;
                best = max(best, 1LL * heights[mid] * width);
            }
            st.push(i);
        }
        return (int)best;
    }
};
