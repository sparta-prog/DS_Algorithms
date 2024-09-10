#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.*/

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.length();

        if (n == 0)
            return 0;

        int time = 0, prev = 0;

        for (int curr = 1; curr < n; curr++)
        {
            if (colors[prev] == colors[curr])
            {
                time += min(neededTime[prev], neededTime[curr]);

                // prev points to the biggger value
                if (neededTime[prev] < neededTime[curr])
                {
                    prev = curr;
                }
            }
            else
            {
                prev = curr;
            }
        }
        return time;
    }
};

int main()
{
    Solution obj;
    // colors = "abaac", neededTime = [1,2,3,4,5]
    vector<int> neededTime = {1, 2, 3, 4, 5};
    string colors = "abaac";

    cout << obj.minCost(colors, neededTime);
}