#include<bits/stdc++.h>

using namespace std;

int findNextJob(vector<vector<int>>& jobs,int start,int currEnd) {
    //linear search
    int n = jobs.size();
    
    int result = -1;
    for(int i=start;i<n;i++) {
        if(jobs[i][1] >= currEnd) {
            result = i;
        }
    }
    return result;
}

int solve(vector<vector<int>>& jobs,int i) {
    if(i >= jobs.size()) {
        return 0;
    }
    
    int next = findNextJob(jobs,i+1,jobs[i][1]);
    
    int op1 = jobs[i][2] + solve(jobs,next);
    
    int op2 = solve(jobs,i+1);
    
    return max(op1,op2);
}

int maxProfit(vector<int> &start,vector<int> &end,vector<int> &profit) {
    
    int n = start.size();
    
    if(n == 0)
        return 0;
    //group the jobs together
    vector<vector<int>> jobs(n, vector<int>(3,0));
    
    for(int i=0;i<n;i++) {
        jobs.push_back({start[i],end[i],profit[i]});
    }
    
    //sort by start times
    sort(jobs.begin(),jobs.end(), [](auto &vec1, auto &vec2) {
        return vec1[1] <= vec2[1];
    });
    
    int maxProfit = solve(jobs,0);
    
    return maxProfit;
}

int main() {
    
    int n = 5;
    vector<int> start = {1,2,3,3};
    vector<int> end = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    
    
    cout<<maxProfit(start,end,profit);
}