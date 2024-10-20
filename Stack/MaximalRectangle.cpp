#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    void findLeft (vector<int>& NSL, vector<int> &height) {
        stack<int> st;
        int n = height.size();

        for(int i=0;i<n;i++) {
            if(st.empty()) {
                NSL[i] = -1;
            }
            else {
                while(!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }

                if(st.empty()) {
                    NSL[i] = -1;
                }
                else {
                    NSL[i] = st.top();
                }
            }
            st.push(i);
        }
    }
    void findRight (vector<int>& NSL, vector<int> &height) {
        stack<int> st;
        int n = height.size();

        for(int i=n-1;i>=0;i--) {
            if(st.empty()) {
                NSL[i] = n;
            }
            else {
                while(!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }

                if(st.empty()) {
                    NSL[i] = n;
                }
                else {
                    NSL[i] = st.top();
                }
            }
            st.push(i);
        }
    }
    int findArea(vector<int> &height) {
        int n = height.size();

        vector<int> NSR(n);
        vector<int> NSL(n);
        int maxArea = INT_MIN;

        findLeft(NSL,height);
        findRight(NSR,height);

        for(int i=0;i<n;i++) {
            int area = height[i]*(NSR[i] - NSL[i] - 1);
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n,0);

        for(int j=0;j<n;j++) {
            if(matrix[0][j] == '1') {
                height[j] = 1;
            }
        }

        int maxArea = findArea(height);

        for(int i=1;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j] == '1') {
                    height[j] += 1;
                }
                else {
                    height[j] = 0;
                }
            }
            maxArea = max(maxArea,findArea(height));
        }
        return maxArea;
    }
};

int main() {
    Solution obj;
    vector<vector<char>> data = {{'1','0','1','0','0'},{'1','0','1','1','1'},
        {'1','1','1','1','1'},{'1','0','0','1','0'}} ;

    cout<<obj.maximalRectangle(data);
}