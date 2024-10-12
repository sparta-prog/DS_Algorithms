#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        int targetArrivalTime = times[targetFriend][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> chair(n,-1);
        sort(times.begin(),times.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });

        for(int i=0;i<n;i++) {
            int arrivalTime = times[i][0];
            int departTime = times[i][1];
            
            if(!pq.empty() && arrivalTime >= pq.top().first) {
                int chairNo = pq.top().second;
                pq.pop();
                pq.push({departTime,chairNo});

                if(arrivalTime == targetArrivalTime)
                    return i;
            }
            
        }
        return -1;
    }
};

int main() {
    vector<vector<int>> times = {{3,10},{1,5},{2,6}};
    int targetFriend = 0;
    Solution obj;

    cout<<obj.smallestChair(times,targetFriend);
}