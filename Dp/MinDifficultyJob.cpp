#include <iostream>
#include <vector>
#include <algorithm>

/*
1335. Minimum Difficulty of a Job Schedule
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.
*/

using namespace std;

class Solution
{
public:
    // helper function to find the minDifficulty
    int solver(vector<int> &jd, int i, int d, vector<vector<int>> &cache)
    {
        // Base case: if we're on the last day, take the max difficulty of the remaining jobs
        if (d == 1)
        {
            int mD = INT_MIN;
            for (int j = i; j < jd.size(); j++)
            {
                mD = max(mD, jd[j]); // Corrected to jd[j]
            }
            return mD;
        }

        // Check the cache for already computed values
        if (cache[i][d] != -4)
        {
            return cache[i][d];
        }

        int mD = jd[i]; // Start with the current job difficulty
        int finalResult = INT64_MAX;

        // Try to split jobs into two groups: first group handled today, rest recursively
        for (int j = i + 1; j <= jd.size() - d; j++)
        {
            mD = max(mD, jd[j]); // Get the max difficulty for the current day

            // Recursively solve for the remaining jobs in `d - 1` days
            int result = mD + solver(jd, j + 1, d - 1, cache);

            // Track the minimum difficulty found
            finalResult = min(finalResult, result);
        }

        return cache[i][d] = finalResult; // Cache the result and return
    }
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();

        if (n == 0)
            return -1;

        vector<vector<int>> cache(n, vector<int>(d + 1, -4));

        return solver(jobDifficulty, 0, d, cache);
    }
};

int main()
{
    Solution obj;

    vector<int> jobDifficulty = {6, 5, 4, 3, 2, 1};
    int d = 2;
    cout << obj.minDifficulty(jobDifficulty, d);

    return 0;
}