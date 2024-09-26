#include <iostream>
#include <queue>

using namespace std;

struct Compare{
    bool operator() (pair<int,string>& a, pair<int,string>& b) {
        if(a.first == b.first) {
            //sort lexicographically
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

class Solution {
    typedef pair<int,string> p;
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        //store in a map
        unordered_map<string,int> mp;

        for(string& word : words) {
            mp[word]++;
        }
        priority_queue<p,vector<p>,Compare> pq;
        //insert into queue
        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second,it->first});
            //if size exceeds k 
            if(pq.size() > k)
                pq.pop();
        }
        //heap now contains k most frequent elements

        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    
    Solution obj;
    vector<string> result = obj.topKFrequent(words,k);

    for(auto x : result) {
        cout<<x<<" ";
    }
}