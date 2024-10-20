#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    void NSL(vector<int> &nextSmallerLeft,vector<int> &heights) {
        int n = heights.size();
        stack<int> st;

        for(int i=0;i<n;i++) {
            int el = heights[i];
            while(!st.empty() && el <= heights[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                nextSmallerLeft[i] = -1;
            }
            else {
                nextSmallerLeft[i] = st.top();
            }
            st.push(i);
        }
    }

    void NSR(vector<int> &nextSmallerRight,vector<int> &heights) {
        int n = heights.size();
        stack<int> st;

        for(int i = n-1;i >= 0;i--) {
            int el = heights[i];
            while(!st.empty() && el <= heights[st.top()]) {
                st.pop();
            }

            if(st.empty()) {
                nextSmallerRight[i] = n;
            }
            else {
                nextSmallerRight[i] = st.top();
            }
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> nextSmallerLeft(n,0);
        vector<int> nextSmallerRight(n,0);

        int maxArea = INT_MIN;

        NSL(nextSmallerLeft,heights);
        NSR(nextSmallerRight,heights);

        for(int i=0;i<n;i++) {
            int width = nextSmallerRight[i] - nextSmallerLeft[i] - 1;
            int area = heights[i] * (width);

            maxArea = max(maxArea,area);
        }

        return maxArea;
    }
};

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    Solution obj;

    cout<<obj.largestRectangleArea(heights);
}