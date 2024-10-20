#include <iostream>
#include <vector>
#include<queue>

using namespace std;

class Solution {
    typedef pair<int,char> p;
public:
    string longestDiverseString(int a, int b, int c) {
        //store in priority queue
        priority_queue<p> q;

        if(a>0) q.push({a,'a'});
        if(b>0) q.push({b,'b'});
        if(c>0) q.push({c,'c'});

        string result = "";

        while(!q.empty()) {
            int maxCount = q.top().first;
            int maxChar = q.top().second;
            q.pop();

            if(result.size() >= 2 && result[result.size() - 1] == maxChar && result[result.size() - 2] == maxChar) {
                //check for next char
                if(!q.empty()) {
                    int count = q.top().first;
                    int nextChar = q.top().second;
                    q.pop();
                    if(count == 0)
                        break;

                    result += nextChar;
                    count--;

                    if(count > 0) {
                        q.push({count,nextChar});
                    }
                }
                else {
                    break;
                }
            }
            else {
                result += maxChar;
                maxCount--;
            }
            if(maxCount > 0) {
                    q.push({maxCount,maxChar});
                }
        }
        return result;
    }
};

int main() {
    Solution obj;
    int a=1,b=1,c=7;
    cout<<obj.longestDiverseString(a,b,c);
}