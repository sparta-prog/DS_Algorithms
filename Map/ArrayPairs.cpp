#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        unordered_map<int,int> mp;

        for(int& x:arr) {
            int rem = (x%k + k) % k;
            mp[rem]++;
        }

        //check for 0
        if(mp[0]%2 != 0) {
            return false;
        }

        for(int rem = 1;rem <=k/2;rem++) {
            if(mp[rem] != mp[k-rem]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<int> data = {-1,-1,-1,-1,2,2,-2,-2};
    int k = 3;

    cout<<obj.canArrange(data,k);
}