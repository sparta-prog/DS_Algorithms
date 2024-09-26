#include <iostream>
#include<queue>
#include <math.h>

using namespace std;

class Solution {
public:
    typedef pair<int,int> p;
    int calcDistance(int x,int y) {
        int dist = x*x + y*y;

        return dist;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        if(n == 0)
            return {{}};

        //max heap
        priority_queue<p> pq; 
        for(int i=0;i<n;i++) {
            int x = points[i][0];
            int y = points[i][1];
            //calculate distance
            int dist = calcDistance(x,y);
            //store
            pq.push({dist,i});
            /**
             * Check size for space optimisation
            */
           if(pq.size() > k) {
                pq.pop();
           }
        }
        //store in a result
        vector<vector<int>> result;

        while(!pq.empty()) {
            int ind = pq.top().second;
            int x = points[ind][0];
            int y = points[ind][1];

            result.push_back({x,y});
            pq.pop();
        }
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{1,1},{3,3},{-3,-3},{5,-1},{-2,4}};
    int k = 2;
    Solution obj;

    auto result = obj.kClosest(points,k);

    for(auto &v : result) {
        cout<<v[0]<<","<<v[1]<<endl;
    }

    return 0;
}